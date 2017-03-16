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
typedef vector<ll> vl;
int len = 14;
vector<vl> sets(vl &a)
{
    int q = 1;
    rep(i,0,len) q *= 3;
    map<ll, vector<int> > first, second;
    rep(k,1,q)
    {
        int w = k;
        vi o(len);
        rep(i,0,len)
        {
            o[i] = w % 3;
            if (o[i] == 2)
                o[i] -= 3;
            w /= 3;
        }

        ll f = 0, s = 0;
        rep(i,0,len)
        {
            f += o[i] * a[i];
            s += o[i] * a[i + len];
        }
        first[f] = o;
        second[s] = o;
    }

    trav(it,first)
        if (second.count(it->first))
        {
            vector<vl> res(2, vl());
            rep(i,0,len) if (it->second[i] != 0)
                res[it->second[i] > 0].push_back(a[i]);
            vi& tt = second[it->first];
            rep(i,0,len) if (tt[i] != 0)
                res[tt[i] < 0].push_back(a[i + len]);
            return res;
        }
    return vector<vl> ();
}
int main()
{
    int tt; scanf("%d", &tt);
    rep(sd,0,tt)
    {
        int n; scanf("%d", &n);
        vector<ll> a(n);
        rep(i,0,n) scanf("%lld", &a[i]);

        while (true)
        {
            vl b = a;
            rep(i,0,2*len)
            {
                int ind = rand() % (b.size() - i) + i;
                swap(b[ind], b[i]);
            }
            b.resize(2 * len);

            vector<vl> res = sets(b);
            if (!res.empty())
            {
                printf("Case #%d:\n", sd+1);
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
                break;
            }
        }
        cerr << sd+1 << endl;
    }
}
