#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef __int64 LL;
const int MAXN=100000;
LL v[MAXN];

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B_output_small.txt","w",stdout);
    //freopen("B_output_large.txt","w",stdout);
    int T;
    LL E,R,N;
    LL f[20][100];
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%I64d%I64d%I64d",&E,&R,&N);
        for (int i=1;i<=N;i++) scanf("%I64d",&v[i]);
        memset(f,0,sizeof(f));
        for (int i=1;i<=N;i++)
        {
            for (int j=0;j<=E;j++)
            {
                if (j<=R)
                {
                    f[i][j]=f[i-1][j];
                    for (int k=0;k<=E;k++)
                    {
                        f[i][j]=max(f[i][j],f[i-1][k]+k*v[i]);
                    }
                }else{
                    for (int k=j-R;k<=E;k++)
                    {
                        f[i][j]=max(f[i][j],f[i-1][k]+(k-(j-R))*v[i]);
                    }
                }
            }
        }
        LL result=0;
        for (int i=0;i<=E;i++) result=max(result,f[N][i]);
        printf("Case #%d: %I64d\n",cases,result);
    }
    return 0;
}
