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
typedef pair<int, int> Item;

const int Maxn = 100+10;
const llong INF = 0x7f7f7f7f7f7f7f7fLL;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int realcmp(double a, double b){ return (a>b+eps) ? 1 : ((a+eps<b)?-1:0); }

int main()
{
    int T, n, s, p;
    ios::sync_with_stdio(0);
    freopen("B-large.in", "r", stdin);
    freopen("a.out", "w", stdout);

    cin>>T;
    for(int c=0; c<T; c++)
    {
        cin>>n>>s>>p;
        int a, ans=0;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            if( a <= 1 )
            {
                if( a >= p )
                    ans++;
            }
            else
            {
                if( a%3 == 0 )
                {
                    if( a/3 >= p )
                        ans++;
                    else if( a/3+1>=p && s>0 )
                    {
                        s--;
                        ans++;
                    }
                }
                else if( a%3 == 1 )
                {
                    if( (a+2)/3 >= p )
                        ans++;
                }
                else
                {
                    if( (a+1)/3 >= p )
                        ans++;
                    else if( (a+4)/3>=p && s>0 )
                    {
                        s--;
                        ans++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", c+1, ans);
    }

    return 0;
}
