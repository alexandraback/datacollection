#include<iostream>
using namespace std;
int ans,t,i1,i,l[1005][3],s,t1,m,n,a[1005][2],st,f[1005],max1,maxi;

int cmp(const void *a, const void *b)
{
     return(*(int *)a-*(int *)b);
}

int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("b1.out","w",stdout);
    scanf("%d",&t1);
    for (i1=1;i1<=t1;i1++)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        for (i=0;i<n;i++)
        {
            scanf("%d %d",&a[i][0],&a[i][1]);
            l[i*2][0]=a[i][0];
            l[i*2][1]=i;
            l[i*2][2]=1;
            l[i*2+1][0]=a[i][1];
            l[i*2+1][1]=i;
            l[i*2+1][2]=2;
        }
        qsort(l,n*2,sizeof(l[0]),cmp);
        s=0;t=-1;ans=0;m=0;st=0;
        memset(f,0,sizeof(f));
        while (l[t+1][0]==0&(t+1<=2*n)) t++;
        while (s<=t&&s<2*n&&m<n)
        {
              bool f1=false;
              for (i=s;i<=t;i++)
                  if (l[i][2]==2&&f[l[i][1]]!=2)
                  {
                      ans++;
                      f1=true;
                      m++;
                      if (f[l[i][1]]==1) st+=1;else st+=2;
                      f[l[i][1]]=2;
                  }
              if (!f1)
              {
                  max1=-1;
                  while (f[l[s][1]]!=0&&s<t)
                  {
                        s++;
                  }
                  if (f[l[s][1]]==0)
                  {
                      /*ans++;
                      f[l[s][1]]=1;
                      st++;
                      s++;*/
                      max1=a[l[s][1]][1];
                      maxi=s;
                  }
                  for (i=s+1;i<=t;i++)
                      if (f[l[i][1]]==0&&a[l[i][1]][1]>max1)
                      {
                          max1=a[l[i][1]][1];
                          maxi=i;
                      }
                  if (max1!=-1)
                  {
                      ans++;
                      f[l[maxi][1]]=1;
                      st++;
                      f1=true;
                  }
              }
              if (!f1) break;
              while (l[t+1][0]<=st&&(t+1<2*n)) t++;
        } 
        if (m==n)
        {
             printf("Case #%d: %d\n",i1,ans);
        }
        else
            printf("Case #%d: Too Bad\n",i1);
    }
    return 0;
}
