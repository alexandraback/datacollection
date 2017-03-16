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
    string s;
    cin>>s;

    int n=SZ(s) - 1, res = 0;

    while(true)
    {
        while(n>=0&&s[n]=='+')--n;
        if(n<0)break;

        REP(i,n+1)s[i]=s[i]=='+'?'-':'+';
        ++res;
    }

    printf("%d\n",res);
}


int main()
{
    //freopen("../input.txt", "r", stdin);
    freopen("../data/B-large.in", "r", stdin);
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
