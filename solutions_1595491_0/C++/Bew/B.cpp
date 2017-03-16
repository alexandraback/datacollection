#include<stdio.h>
int normal[100]={0};
int sur[100]={0};
int a[300];
int use[303];
int T,n,P,S;

void pre();
int main()
{
    int i,j,k;
    pre();
    freopen("B-small-attempt1.in","r",stdin);
   freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&T);
    for(i=0;i<T;i++)
     {
       scanf("%d %d %d",&n,&S,&P);
    //   printf("%d %d %d\n",n,S,P);
       for(j=0;j<n;j++)scanf("%d",&a[j]);
   //    for(j=0;j<n;j++)printf("%d",a[j]);printf("\n");
       for(j=0;j<300;j++)use[j]=0;
       k=0;
       for(j=0;j<n;j++)
        {
        //  printf("> %d %d  %d %d\n",a[j],normal[a[j]],sur[a[j]],P);
          if(normal[a[j]]>=P)
           {
             k++;
             use[j]=1;
           }
        }
       for(j=0;j<n;j++)
        {
          if(S==0)break;
          if(sur[a[j]]>=P)
           {
            if(use[j]==0)
             {
               k++;
               use[j]=1;
               S--;
             }
           }
        }
       printf("Case #%d: %d",i+1,k);
       if(i<T-1)printf("\n");
     }
    
    
    scanf(" ");
    return 0;
}
void pre()
{
  int i,j,k;
  int p,q,r;
  for(i=0;i<=10;i++)
   {
     for(j=i;j<=10;j++)
      {
       for(k=j;k<=10;k++)
        {
          if(k-i<=2)
           {
             p=i+j+k;
             //printf("%d %d %d | %d\n",i,j,k,p);
             if(k-i==0||k-i==1)
              {
                if(normal[p]<k)normal[p]=k;
              }
             else if(k-i==2)
              {
                if(sur[p]<k)sur[p]=k;
              }
           }
        }
      }
   }
   sur[29]=10;
   sur[30]=10;
//  for(i=0;i<=30;i++)printf("%d %d %d\n",i,normal[i],sur[i]);
}
