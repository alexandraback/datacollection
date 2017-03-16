#include<stdio.h>
#include<string.h>
int main()
{
int t,i=0;
scanf("%d",&t);

while(t--)
{
char A[1000],B[1000];
int num,ans=0,k,j,l;
scanf("%s",A);
scanf("%d",&num);
for(k=0;k<num;k++)
  B[k]='1';
B[k]='\0';
for(k=0;k<strlen(A);k++)
{   if(A[k]=='a' || A[k]== 'e'|| A[k] == 'i' || A[k]== 'o' || A[k] == 'u')
   A[k]='0';
   else A[k]='1';}
//printf("%d\n",num);
for(j=0;j<strlen(A);j++)
{ for(k=j;k<strlen(A);k++)
{ //printf("ll%d\n",k);
if(k-j >= num-1 ) 
{char T[1000];

for(l=j;l<=k;l++) T[l-j]=A[l];
T[l-j]='\0';
//printf("%s %s %d\n",T,A,ans);
if(strstr(T,B)!=NULL) ans++;}}}
printf("Case #%d: %d\n",i+1,ans);
i++;
}
}
