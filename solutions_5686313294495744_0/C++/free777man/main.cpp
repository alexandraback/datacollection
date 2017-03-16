#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

string a[22], b[22];

void solve()
{
    int n;
    cin>>n;

    REP(i,n)cin>>a[i]>>b[i];

    int res = 0, mx=1<<n;

    REP(mask,mx)
    {
        int m = mask, bc=0;
        while(m)++bc,m&=m-1;

        if(bc<=res)continue;

        set<string> ta, tb, fa, fb;

        REP(i,n)
        {
            if(mask&(1<<i))fa.insert(a[i]), fb.insert(b[i]);
            else ta.insert(a[i]), tb.insert(b[i]);
        }

        char ok=1;

        for (auto & x : fa)if(ta.count(x) == 0)
        {
            ok=0;
            break;
        }

        if(ok)for (auto & x : fb)if(tb.count(x) == 0)
        {
            ok=0;
            break;
        }

        if(ok)res=bc;
    }

    cout << res << endl;
}


int main()
{
    //freopen("../input.txt", "r", stdin);
    freopen("../data/C-small-attempt0.in", "r", stdin);
    freopen("../output.txt", "w+", stdout);

    int T;
    scanf("%d", &T);
    REP(i, T)
    {
        printf("Case #%d: ", i+1);
        solve();
    }

    return 0;
}
