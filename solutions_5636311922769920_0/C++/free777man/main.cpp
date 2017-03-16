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


void solve()
{
    int k,c,s;
    cin>>k>>c>>s;

    if (s!=k)
    {
        printf("IMPOSSIBLE\n");
        return;
    }

    REP(i,s)
    {
        ll res = i;
        REP(j,c-1)res=res*k+i;

        cout << res+1 << " ";
    }

    cout << endl;
}


int main()
{
    //freopen("../input.txt", "r", stdin);
    freopen("../data/D-small-attempt0.in", "r", stdin);
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
