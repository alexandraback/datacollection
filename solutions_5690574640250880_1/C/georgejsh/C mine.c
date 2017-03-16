#include<stdio.h>
#define MAX 1000000007
int main()
{
 int t;
 char a[51][51];
 int r,c,i,j,k,m,p;
 for(scanf("%d",&t),p=0;p<t;p++)
 {
  scanf("%d%d%d",&r,&c,&m);
  printf("Case #%d:\n",p+1);
  for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   a[i][j]='.';
  if(r==1)
  {
   a[0][0]='c';
   for(j=c-1;j>=0;j--)
    if(m)
     a[0][j]='*',m--;
	else
     a[0][j]='.';	
  }
  else if(c==1)
  {
   a[0][0]='c';
   for(j=r-1;j>=0;j--)
    if(m)
     a[j][0]='*',m--;
	else
     a[j][0]='.';
  }
  else if(r==2)
  {
   if(c==2)
   {
    if(m==3)
	{
	 a[0][1]=a[1][1]=a[1][0]='*';
	}
	else if(m!=0)
	{ 
    printf("Impossible\n");
	continue;
    }
   }
   else if(m==r*c-1)
   {
   for(j=c-1;j>=0;j--)
     a[0][j]='*',a[1][j]='*';
   }
   else if(m%2!=0 || m>r*c-4)
   { 
    printf("Impossible\n");
	continue;
   }
   for(j=c-1;j>=0;j--)
    if(m)
     a[0][j]='*',a[1][j]='*',m-=2;
	else
     a[0][j]='.',a[1][j]='.';
  }
  else if(c==2)
  {
   if(m==r*c-1)
   {
    for(j=r-1;j>=0;j--)
      a[j][0]='*',a[j][1]='*';
   }
   else if(m%2!=0 || m>r*c-4)
   { 
    printf("Impossible\n");
	continue;
   }
   for(j=r-1;j>=0;j--)
    if(m)
     a[j][0]='*',a[j][1]='*',m-=2;
	else
     a[j][0]='.',a[j][1]='.';
  }
  else
  {
   if(m<=(r-2)*(c-2))
   {
    //to write
	for(i=r-1;i>=2;i--)
	 for(j=c-1;j>=2;j--)
	  if(m)
	   a[i][j]='*',m--;
   }
   else if(m>r*c-4)
   {
    if(m==r*c-1)
	{
	//to write
	 for(i=0;i<r;i++)
	 for(j=0;j<c;j++)
	   a[i][j]='*';
	}
	else
	{ 
    printf("Impossible\n");
	continue;
    }
  }
  else if(m==(r-2)*(c-2)+2*(r-3)+2*(c-3)+1 || m==(r-2)*(c-2)+2*(r-3)+2*(c-3)+3)
   { 
    printf("Impossible\n");
	continue;
   }
  
   else
   {
    for(i=r-1;i>=2;i--)
	 for(j=c-1;j>=2;j--)
	  if(m)
	   a[i][j]='*',m--;
	if(m%2==0)
	{
	 for(j=r-1;j>2;j--)
      if(m)
       a[j][0]='*',a[j][1]='*',m-=2;
	 if(m)
	 {
	  for(j=c-1;j>2;j--)
       if(m)
        a[0][j]='*',a[1][j]='*',m-=2;
	 }
	 if(m)
	 {
	  a[2][0]=a[2][1]='*';m-=2;
	 }
	 if(m)
	 {
	  a[0][2]=a[1][2]='*';m-=2;
	 }
	}
	else
	{
	 a[2][2]='.';m++;
	 for(j=r-1;j>2;j--)
      if(m)
       a[j][0]='*',a[j][1]='*',m-=2;
	 if(m)
	 {
	  for(j=c-1;j>2;j--)
       if(m)
        a[0][j]='*',a[1][j]='*',m-=2;
	 }
   }
  }
 }
  a[0][0]='c';
  for(i=0;i<r;i++)
  {
  for(j=0;j<c;j++)
  {
   printf("%c",a[i][j]);
  }
  printf("\n");
  }
 
}
return 0;
}