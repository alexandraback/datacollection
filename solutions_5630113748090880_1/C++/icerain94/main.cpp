#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long ll;
#define C_UE 10
#define V2V_UE 10
#define maxn 10000000
#define mod 1000000007

int num[2505];
int main()
{
    freopen("B-large.txt","r",stdin);
    freopen("B-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(num,0,sizeof(num));
        int n;
        scanf("%d",&n);
        for(int i=0;i<2*n-1;i++)
        {
            int x;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&x);
                num[x]++;
            }
        }
        int idx=0;
        printf("Case #%d: ",cas);
        for(int i=1;i<=2500;i++)
        {
            if(num[i]%2)
            {
                idx++;
                if(idx!=n) printf("%d ",i);
                else printf("%d\n",i);
            }
        }

    }
}
