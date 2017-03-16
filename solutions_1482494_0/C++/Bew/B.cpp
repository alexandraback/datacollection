#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n;
int T;
struct ST
{
  int x;
  int id;
  bool operator <(const ST&o)const
   {
     return o.x>x;
   }
};
ST a[2111],b[2111];
int A[2111],B[2111];
int tower[2111];
int star,ans;
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int i,j,k;
    int p,q,r,t;
    int one,two;
    scanf("%d",&T);
    for(int ii=0;ii<T;ii++)
     {
       scanf("%d",&n);
       for(i=0;i<n;i++)
        {
          scanf("%d %d",&a[i].x,&b[i].x);
          A[i]=a[i].x;
          B[i]=b[i].x;
          a[i].id=i;
          b[i].id=i;
        }
        sort(a,a+n);
        sort(b,b+n);
       /* for(i=0;i<n;i++)
         {
           printf("%d  %d %d | %d %d\n",i,a[i].x,a[i].id,b[i].x,b[i].id);
         }*/
       for(i=0;i<2000;i++)tower[i]=0;
       star=0;ans=0;one=0;two=0;
       while(1)
        {
          p=0;
          for(;two<n;two++)
           {
             if(star<b[two].x)break;
             if(tower[b[two].id]==0)
              {
                tower[b[two].id]=2;
                star+=2;ans++;p++;
           //     printf("2 %d %d %d\n",two,star,ans);
              }
             else if(tower[b[two].id]==1)
              {
                tower[b[two].id]=2;
                star+=1;ans++;p++;
          //      printf("2 %d %d %d\n",two,star,ans);
              }
           }
          if(two==n)break;
          q=0;r=0;t=-999999999;
          for(one=0;one<n;one++)
           {
             if(tower[a[one].id]==0)
              {
                if(star>=a[one].x)
                 {
                   if(B[a[one].id]>t)
                    {
                      t=B[a[one].id];
                      r=one;
                      q++;
                    }
                 }
              }
             /*if(q!=0)break;
             if(star<a[one].x)break;
             if(tower[a[one].id]==0)
              {
                tower[a[one].id]=1;
                star+=1;ans++;p++;q++;
             //   printf("1 %d %d %d\n",one,star,ans);
              }
             else if(tower[a[one].id]==1)
              {
                printf("BUG");
              }
             else if(tower[a[one].id]==2)
              {
                 star=star;
              }*/
           }
          if(q!=0)
           {
             tower[a[r].id]=1;
             star+=1;ans++;p++;
            // printf("1 %d %d %d  %d\n",r,star,ans,t);
           }
          if(p==0)break;
        }
       if(two==n)printf("Case #%d: %d",ii+1,ans);
       else printf("Case #%d: Too Bad",ii+1);
       if(ii<T-1)printf("\n");
     }
     /*
    printf("\n");
    for(i=0;i<n;i++)
     {
       printf(">%d | %d\n",i,tower[i]);
     }
    printf(">>> %d %d\n",one,two);
    */
    
    scanf(" ");
    return 0;
}
