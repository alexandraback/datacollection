#include<stdio.h>
#include<stdlib.h>
long long T,n,m;
long long a[111][111]={0};
struct ST
{
   long long x,id;
};
ST box[111];
ST toy[111];
ST inbox[111];
ST intoy[111];
long long arr[111]={0},ARR=0;
long long A,B,count=0,ans;
long long min(long long xx,long long yy)
{
 if(xx<yy)return xx;
 return yy;
}
long long f(long long h)
{
  long long i,j,k;
  long long sum=0;
  long long idx,idy;
  for(i=1;i<=n;i++)box[i]=inbox[i];
  for(i=1;i<=m;i++)toy[i]=intoy[i];
/*  printf("\n\n");
  for(i=1;i<=n;i++)printf("%d %d\n",box[i].x,box[i].id);printf("\n");
  for(i=1;i<=m;i++)printf("%d %d\n",toy[i].x,toy[i].id);
  printf("\n\n");*/
  if(box[1].id==toy[1].id)
   {
     k=min(box[1].x,toy[1].x);
     sum+=k;
     box[1].x-=k;
     toy[1].x-=k;
   }
  idx=1;idy=1;
  for(i=0;i<h;i++)
   {
     if(arr[i]==1)
      {
        idx++;
      }
     else if(arr[i]==2)
      {
        idy++;
      }
     else printf("FUCK");
    // printf("%d %d\n",idx,idy);
     if(box[idx].id==toy[idy].id)
      {
    //    printf("   %d %d\n",idx,idy);
        k=min(box[idx].x,toy[idy].x);
        sum+=k;
        box[idx].x-=k;
        toy[idy].x-=k;
      } 
   }
  if(sum>ans)ans=sum;
}
long long rec(long long h,long long AA,long long BB)
{
   long long i;
   //printf("%d %d %d\n",h,AA,BB);
  if(h==A+B)
   {
     //for(i=0;i<h;i++)printf("%d",arr[i]);printf("\n");
     f(h);
    // printf(">> %d\n",ans);
     count++;
     return 0;
   }
  if(AA!=A)
   {
      arr[h]=1;
      rec(h+1,AA+1,BB);
   }
  if(BB!=B)
   {
     arr[h]=2;
     rec(h+1,AA,BB+1);
   }
  return 0;
}
long long gen(long long aaa,long long bbb)
{
   long long i,j,k;
   A=aaa;B=bbb;
   rec(0,0,0);
   //printf("%d\n",count);
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    long long i,j,k;
    long long p,q,r;
    scanf("%I64d",&T);
    for(int ii=0;ii<T;ii++)
     {
       scanf("%I64d %I64d",&n,&m);
       for(i=1;i<=n;i++)
        {
          scanf("%I64d %I64d",&box[i].x,&box[i].id);
          inbox[i].x=box[i].x;
          inbox[i].id=box[i].id;
        }
       for(i=1;i<=m;i++)
        {
          scanf("%I64d %I64d",&toy[i].x,&toy[i].id);
          intoy[i].x=toy[i].x;
          intoy[i].id=toy[i].id;
        }
       ans=-999999999;
       gen(n-1,m-1);
       printf("Case #%d: %I64d",ii+1,ans);
       if(ii<T-1)printf("\n");
     } 
    
    scanf(" ");
    return 0;
}
