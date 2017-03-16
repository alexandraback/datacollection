#include<stdio.h>
#include<string.h>
int main()
{
int t,i,len,j,k;
scanf("%d",&t);
char s[1001],x;
for(i=1;i<=t;i++)
{
char s1[1001]="\0",s2[1001]="\0";
scanf("%s",s);
len=strlen(s);
s1[0]=s[0];
for(j=1;j<len;j++)
{
x=s[j];
if(x>=s1[0])
{
strcpy(s2,s1);
s1[0]=x;
for(k=1;k<=j;k++)
{
    s1[k]=s2[k-1];
}
}
else
{
s1[j]=x;
}
}
printf("Case #%d: %s\n",i,s1);
}
return 0;
}
