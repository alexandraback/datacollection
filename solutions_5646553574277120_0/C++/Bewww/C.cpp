#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int T,ii;
int C,n,m;
int a[10];
int x[100];
int ans;
int found;

int f(int lim)
{
  int i,j,k;
  for(i=0;i<100;i++)x[i]=0;
  for(i=0;i<lim;i++)
   {
    // x[a[i]]=1;
   }
  x[0]=1;
  /*
  for(i=1;i<=m;i++)
   {
     if(x[i]==0)
      {
        for(j=0;j<lim;j++)
         {
           if(i-a[j]>=0)
            {
              if(x[i-a[j]]==1)x[i]=1;
            }
         }
      }
   }*/
  //printf(">");for(int iii=1;iii<=m;iii++)printf("%d",x[iii]);printf("\n");
  for(i=0;i<lim;i++)
   {
     k=a[i];
     for(j=m;j>=1;j--)
      {
        //if(j==4)printf("%d %d %d\n",k,x[j-k],x[j]);
        if(j-k>=0)
         {
           if(x[j-k]==1)x[j]=1;
         }
      }
     // printf(">");for(int iii=1;iii<=m;iii++)printf("%d",x[iii]);printf("\n");
   } 
  //for(i=1;i<=m;i++)printf("%d",x[i]);printf("\n");
  for(i=1;i<=m;i++)
   {
     if(x[i]==0)return 0;
   }
  return 1;
}
int F(int h,int lim)
{
  if(found==1)return 0;
  int i,j,k;
  if(h==lim)
  {
   // printf(">");
   // for(i=0;i<lim;i++)printf("%d ",a[i]);printf("\n");
    //scanf("%d",&k);
    if(f(lim)==1)
     {
       found=1;
      // printf("%d <\n",a[lim-1]);
     }
    return 0;
  }
  for(i=1;i<=m;i++)
   {
     for(j=0;j<h;j++)
      {
        if(i==a[j])break;
      }
     if(j==h)
      {
        a[h]=i;
        F(h+1,lim);
      }
   }
  return 0;
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1out.txt","w",stdout);
   int i,j,k;
   int p,q,r;
   int t,tt,ttt;
    
scanf("%d",&T);
for(ii=1;ii<=T;ii++)
{
   scanf("%d %d %d",&C,&n,&m);
   for(i=0;i<n;i++)scanf("%d",&a[i]);
   ans=0;
   found=0;
   if(f(n)==0)
    {
      while(1)
       {
         ans++;
         F(n,n+ans);
         if(found==1)break;
       }
      // printf("%d\n",ans);
    }
   
   printf("Case #%d: %d\n",ii,ans);
}

    
    
    scanf(" ");
    return 0;
}
