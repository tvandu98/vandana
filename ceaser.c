//Ceaser Cipher
#include<stdio.h>
FILE *source,*dest;
void encrypt();
void decrypt();
void main()
{
  int choice;
  int k;
  printf("Enter Key from 1-26");
  scanf("%d",&k);
    do
  {
    printf("\n\n\t\tCeaser Cipher\n\nEnter your chice:\n");
    printf("1.Encryption\n2.Decryption\n3.Exit.\n\nYour Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:encrypt(k);
      break;
      case 2:decrypt(k);
      break;
      //default: exit();
    }
   getch();
  }while(choice);
}
void encrypt(int k)
{
char fname[15],ch;
int n;

gets(fname);

source = fopen("src.txt","r");
dest = fopen("Dest.txt","w");
while ((ch=getc(source))!=EOF)
{
n=((toupper(ch)-65)+k)% 26;
ch=(char)(n+65);
putc(ch,dest);
}
fclose(dest);
fclose(source);
printf("\n\nThe file has been encrypted...\n\nThe contents are:\n");
dest=fopen("Dest.txt","r");
while((ch=getc(dest))!=EOF)
printf("%c",ch);
}
void decrypt(int k)
{
char fname[15],ch;
int i,n;
printf("\n\nEnter the name of file to be decrypted:\n");
gets(fname);
dest = fopen(fname,"r");
printf("\nDecrypted contents are : ");
while ((ch=getc(dest))!=EOF)
{
n=(toupper(ch)-65)-k;
if(n<0)
  {
	 n=n+26;
   }
  n=n%26;
ch=(char)(n+65);
putchar(ch);
}
fclose(source);
}

