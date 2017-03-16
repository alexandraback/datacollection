#include<stdio.h>
#include<string.h>
 
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
 
int n,x,y,i,j;
 
scanf("%d",&n);
 
int xarr[50];
int yarr[50];
 
char ans[500];
char temp[3];
char tomp[3];
 
for(i=0;i<n;i++)
{
scanf("%d %d",&x,&y);
 
xarr[i]=x;
yarr[i]=y;
}
 
for(i=1;i<=n;i++)
{
 
x=xarr[i-1];
y=yarr[i-1];
 
ans[0]='\0';
 
if(x<0)
{
temp[0]='E';
temp[1]='W';
temp[2]=0;
x*=-1;
}
 
else
{temp[0]='W';
temp[1]='E';
temp[2]=0;
}
 
if(y<0)
{
tomp[0]='N';
tomp[1]='S';
tomp[2]=0;
y*=-1;
}
 
else
{
tomp[0]='S';
tomp[1]='N';
tomp[2]=0;}
 
 
for(j=0;j<x;j++)
{
strcat(ans,temp);
}
for(j=0;j<y;j++)
{
strcat(ans,tomp);
}
 
printf("Case #%d: %s\n",i,ans);
 
}
return 0;
}
