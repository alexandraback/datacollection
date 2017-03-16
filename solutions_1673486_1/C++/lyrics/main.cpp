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

const int Maxn = 100000+10;
const int INF = 0x7f7f7f7f;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int realcmp(double a, double b){ return (a>b+eps) ? 1 : ((a+eps<b)?-1:0); }

double p[Maxn], mul[Maxn];

int main()
{
    int cas, A, B;
    ios::sync_with_stdio(0);
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);

    cin>>cas;
    for(int c=1; c<=cas; c++)
    {
        set<double> ans;
        cin>>A>>B;
        p[0] = 1.0;
        for(int i=1; i<=A; i++)
            cin>>p[i];
        mul[0] = 1.0;
        for(int i=1; i<=A; i++)
            mul[i] = mul[i-1]*p[i];

        for(int i=0; i<=A; i++)
        {
            double tmp = mul[A-i]*(B-A+1+2*i)+(1-mul[A-i])*(2*B-A+2+2*i);
            ans.insert(tmp);
        }
        ans.insert(B+2.0);
        printf("Case #%d: %.9lf\n", c, *ans.begin());
    }

    return 0;
}
