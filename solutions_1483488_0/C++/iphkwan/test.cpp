#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int e[10]={1,10,100,1000,10000,100000,1000000,10000000};
int v[10],k;
int main()
{
    //freopen("t.in","r",stdin);
    //freopen("t.txt","w",stdout);
    int t,a,b,ans,p,tmp;
    bool ok;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        scanf("%d%d",&a,&b);
        ans=0;
        for(int i=a;i<=b;i++)
        {
            p=0;
            while(i/e[p]>0)
                p++;
            k=0;
            for(int j=1;j<p;j++)
            {
                tmp=(i%e[j]*e[p-j])+i/e[j];
                if(tmp<=b && tmp>i)
                {
                    ok=true;
                    for(int m=0;m<k;m++)
                        if(tmp==v[m])
                        {
                            ok=false;
                            break;
                        }
                    if(ok)
                    {
                        v[k++]=tmp;
                        ans++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
