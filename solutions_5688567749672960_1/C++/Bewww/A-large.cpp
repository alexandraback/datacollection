#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int ii,TT;
long long n;
long long ans;
long long nine[17];
long long a[17];
long long b[17];

void FF(long long x)
{
  if(x==0)
   {
     ans+=1;
     return ;
   }
  long long i,j,k;
  long long p,q,r;
  k=0;
  for(i=1;i<=x;i++)
   {
     if(i==1)k+=10;
     else if(i==2)k+=19;
     else
      {
        r=-1;
        for(j=1;j<=i-1;j++)
         {
           p=i-j;
           if(r==-1)r=nine[j]+nine[p];
           else
            {
              if(nine[j]+nine[p]<r)r=nine[j]+nine[p];
            }
         }
         k+=r+1;
      }
   }
  ans+=k;
}

int main()
{
    freopen("A-large (2).in","r",stdin);
    freopen("A-large (2)out.txt","w",stdout);
    long long i,j,k;
    long long p,q,r;
    long long t,tt,ttt;
    
    tt=1;
    nine[0]=0;
    for(i=1;i<=16;i++)
     {
       tt*=10;
       nine[i]=tt-1;
     }
    
scanf("%d",&TT);
for(ii=1;ii<=TT;ii++)
{
  scanf("%I64d",&n);
  ans=0;
  r=0;
  p=n;
  while(p!=0) 
   {
     b[r]=p%10;
     p/=10;
     r++;
   }
  FF(r-1);
  for(i=0;i<r;i++)
   {
     a[i]=b[r-i-1];
   }
  for(i=r-1;i>=0;i--)
   {
     if(a[i]!=0)break;
   }
  t=-1;
  //printf("Flag 1 %I64d\n",ans);
  if(a[i]!=1)
   {
     p=a[i]-1;
     for(j=i-1;j>=0;j--)
      {
        p*=10;
        p+=a[j];
      }
     q=1;
     for(j=i;j<r-1;j++)q*=10;
     q*=p;
     q+=1;
     tt=n-q;
     //if(tt<0)printf("Bug\n");
     if(t==-1&&tt>=0)t=p+tt+1;
     else 
      {
        if(t>p+tt+1)t=p+tt+1;
      }
   }
 // printf("Flag 2 t=%I64d\n",t);
  for(k=i-1;k>=0;k--)
   {
                   //  printf("k=%d\n",k);
     p=a[k];
     for(j=k-1;j>=0;j--)
      {
        p*=0;
        p+=a[j];
      }
     //      printf("p=%d\n",p);
     q=1;
     for(j=k;j<r-1;j++)q*=10;
     q*=p;
     q+=1;
     tt=n-q;
     //if(tt<0)printf("Bugggg\n");
     if(t==-1&&tt>=0)t=p+tt+1;
     else 
      {
        if(tt>=0&&t>p+tt+1)t=p+tt+1;
      }
   }
  long long bew=1;
  while(bew*10<=n)
   {
     bew*=10;
   }
  //printf("%I64d %I64d %I64d\n",t,n-bew,ans);
  if(t>n-bew)t=n-bew;
  if(t!=-1)ans+=t;
  
  printf("Case #%d: %I64d\n",ii,ans);
}
    
    
    scanf(" ");
    return 0;
}
