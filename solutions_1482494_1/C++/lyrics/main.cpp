#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#define sz(a) ((int)(a).size())
#define foreach(i, v) for(__typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)
using namespace std;
typedef long long llong;

const int Maxn = 1000+10;
const int INF = 0x7f7f7f7f;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int realcmp(double a, double b){ return (a>b+eps) ? 1 : ((a+eps<b)?-1:0); }

int a[Maxn], b[Maxn];
bool fa[Maxn], fb[Maxn];

int main()
{
    int cas, n;
    ios::sync_with_stdio(0);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    cin>>cas;
    for(int c=1; c<=cas; c++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i]>>b[i];
        memset(fa, 0, sizeof(fa));
        memset(fb, 0, sizeof(fb));

        int cnt=0, ans=0;
        while( cnt < 2*n )
        {
            bool flags=false;
            for(int i=0; i<n; i++)
                if( fa[i] && !fb[i] && b[i]<=cnt )
                {
                    ans++;  cnt++;
                    fb[i] = 1;
                    flags = true;
                    break;
                }
            if( flags )
                continue;

            for(int i=0; i<n; i++)
                if( !fa[i] && !fb[i] && b[i]<=cnt )
                {
                    ans++;  cnt += 2;
                    fa[i] = fb[i] = 1;
                    flags = true;
                    break;
                }
            if( flags )
                continue;

            int maxn=-1, ith=-1;
            for(int i=0; i<n; i++)
                if( !fa[i] && !fb[i] && a[i]<=cnt )
                {
                    if( maxn < b[i] )
                    {
                        ith = i;
                        maxn = b[i];
                    }
                }
            if( maxn == -1 )
                break;
            ans++;  cnt++;
            fa[ith] = 1;
        }
        if( cnt < 2*n )
            printf("Case #%d: Too Bad\n", c);
        else
            printf("Case #%d: %d\n", c, ans);
    }

    return 0;
}
