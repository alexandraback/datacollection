#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
    int tt; scanf("%d", &tt);
    rep(sd,0,tt)
    {
        int n; scanf("%d", &n);
        vi a(n);
        rep(i,0,n) scanf("%d", &a[i]);
        int x = accumulate(a.begin(), a.end(), 0);

        printf("Case #%d:", sd+1);
        rep(j,0,n)
        {
            double down = 0, up = 1;
            rep(iter,0,30)
            {
                double m = (down + up) / 2;
                double need = 0;
                double val = a[j] + m * x;
                rep(i,0,n) if (j != i)
                    need += max(.0, (val - a[i]) / x);
                if (need <= 1 - m)
                    down = m;
                else
                    up = m;
            }
            printf(" %.9lf", down * 100);
        }
        printf("\n");
    }
}
