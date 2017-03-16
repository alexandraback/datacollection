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

ll get(ll n)
{
    ll x = n;
    set<int> used;

    while(true)
    {
        ll y = x;
        while(y)used.insert(y%10), y/=10;

        if (SZ(used)==10)
            return x;

        x += n;
    }

    return x;
}


void solve()
{
    int n;
    scanf("%d",&n);

    if(n==0)
    {
        printf("INSOMNIA\n");
        return;
    }

    ll x = get(n);
    printf("%lld\n",x);
}


int main()
{
    //freopen("../input.txt", "r", stdin);
    freopen("../data/A-small-attempt0.in", "r", stdin);
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
