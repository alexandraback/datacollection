#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

int a[10];
int tmp[100];
map<int,int> mm;

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int i,j,n,cnt=1,r,m,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&r,&n,&m,&k);
        printf("Case #%d:\n",cnt++);
        while(r--)
        {
            for (i=0;i<k;i++)
            {
                scanf("%d",&tmp[i]);
            }
            for (a[0]=2;a[0]<=m;a[0]++)
            {
                for (a[1]=2;a[1]<=m;a[1]++)
                {
                    for (a[2]=2;a[2]<=m;a[2]++)
                    {
                  //      printf("%d%d%d\n",a[0],a[1],a[2]);
                        mm.clear();
                        mm[1]=1;
                        mm[a[0]]=mm[a[1]]=mm[a[2]]=1;
                        mm[a[0]*a[1]]=mm[a[0]*a[2]]=mm[a[1]*a[2]]=1;
                        mm[a[0]*a[1]*a[2]]=1;
                        for (i=0;i<k;i++)
                        {
                            if (mm[tmp[i]]==0) break;
                        }
                        if (i==k) break;
                    }
                    if (a[2]<=m) break;
                }
                if (a[1]<=m) break;
            }
            if (a[0]<=m)
            {
                printf("%d%d%d\n",a[0],a[1],a[2]);
            }
        }
    }
}
