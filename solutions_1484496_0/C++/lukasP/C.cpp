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

        int q = 1;
        rep(i,0,10) q *= 3;
        map<int, vi> first, second;
        rep(k,0,q)
        {
            int w = k;
            vi o(10);
            rep(i,0,10)
            {
                o[i] = w % 3 - 1;
                w /= 3;
            }

            int f = 0, s = 0;
            rep(i,0,10)
            {
                f += o[i] * a[i];
                s += o[i] * a[i + 10];
            }
            first[f] = o;
            second[s] = o;
        }

        bool ok = false;
        trav(it,first) if (!ok)
            if (second.count(it->first))
            {
                printf("Case #%d:\n", sd+1);
                vi res[2];
                rep(i,0,10) if (it->second[i] != 0)
                    res[it->second[i] > 0].push_back(a[i]);
                vi& tt = second[it->first];
                rep(i,0,10) if (tt[i] != 0)
                    res[tt[i] < 0].push_back(a[i + 10]);

                rep(i,0,2)
                {
                    rep(j,0,res[i].size())
                    {
                        cout << res[i][j];
                        if (j + 1 < res[i].size())
                            cout << " ";
                    }
                    cout << endl;
                }
                ok = true;
            }
        if (!ok)
            printf("Case #%d:\nImpossible\n", sd+1);
    }
}
