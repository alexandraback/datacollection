#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 100000
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t,a,b,k,i,j;
    cin>>t;
    int ko = 0;
    while(t--)
    {
        LL ans = 0;
        cin>>a>>b>>k;
        for(i = 0;i < a ; i++)
            for(j = 0 ;j < b ; j++)
            {
                int kk = i&j;
                if(kk<k)
                ans++;
            }
        printf("Case #%d: ",++ko);
        cout<<ans<<endl;
    }

    return 0;
}
