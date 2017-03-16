#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define BZ 1000000

typedef struct
{
    int d,n,w,e,s,del_d,del_p,del_s;
}Attack;

typedef struct
{
    int xuhao;
    int day;
    int begin;
    int end;
    int s;
}ATT;

ATT b[1000];
Attack a[15];
int cq[676065+BZ];
int half[676065+BZ];

bool cmp(ATT x,ATT y)
{
    return x.day<y.day;
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int i,j,m,n,T,ans,cnt=1,tmp,k,day;
    ATT tag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        m=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&a[i].d,&a[i].n,&a[i].w,&a[i].e,&a[i].s,&a[i].del_d,&a[i].del_p,&a[i].del_s);
            for (j=0;j<a[i].n;j++)
            {
                tag.xuhao=i;
                tag.day=a[i].d+j*a[i].del_d;
                tag.begin=a[i].w+j*a[i].del_p+BZ;
                tag.end=a[i].e+j*a[i].del_p+BZ;
                tag.s=a[i].s+j*a[i].del_s;
                b[m++]=tag;
            }
        }
   //     printf("................\n");
        sort(b,b+m,cmp);
        for(i=0;i<m;i++)
        {
      //      printf("%d %d %d %d\n",b[i].day,b[i].begin,b[i].end,b[i].s);
        }
        memset(cq,0,sizeof(cq));
        memset(half,0,sizeof(half));
        tmp=0;
        day=-1;
        ans=0;
        for (i=0;i<m;i++)
        {
            if (b[i].day!=day)
            {
                for (j=i-1;j>=0;j--)
                {
                    if (b[j].day!=day) break;
                    for (k=b[j].begin;k<=b[j].end;k++)
                    {
                        cq[k]=max(cq[k],b[j].s);
                    }
                    for (k=b[j].begin;k<b[j].end;k++)
                    {
                        half[k]=max(half[k],b[j].s);
                    }
                }
                day=b[i].day;
                i--;
                continue;
            }
            for (j=b[i].begin;j<=b[i].end;j++)
            {
                if (cq[j]<b[i].s) break;
            }
            if (j<=b[i].end)
            {
                ans++;
             //   printf("\n%d %d\n",i,ans);
                continue;
            }
            for (j=b[i].begin;j<b[i].end;j++)
            {
                if (half[j]<b[i].s) break;
            }
            if (j<b[i].end) ans++;
       //     printf("\n%d %d\n",i,ans);
        }
        printf("Case #%d: %d\n",cnt++,ans);
    }
    return 0;
}
