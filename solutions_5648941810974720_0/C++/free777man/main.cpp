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

const string dig[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[333], res[10];

void solve()
{
    string s;
    cin>>s;

    CLR(res,0);

    res[0] = count(ALL(s), 'Z');
    res[2] = count(ALL(s), 'W');
    res[4] = count(ALL(s), 'U');
    res[6] = count(ALL(s), 'X');
    res[8] = count(ALL(s), 'G');

    CLR(cnt,0);
    int n = SZ(s);

    REP(i,n)++cnt[s[i]];
    REP(d,10)REP(i,res[d])REP(j,SZ(dig[d]))--cnt[dig[d][j]];

    res[1] = cnt['O'];
    res[3] = cnt['H'];
    res[5] = cnt['F'];
    res[7] = cnt['S'];

    REP(d,10)if(d&1)REP(i,res[d])REP(j,SZ(dig[d]))--cnt[dig[d][j]];

    res[9] = cnt['I'];
    REP(i,res[9])REP(j,SZ(dig[9]))--cnt[dig[9][j]];

    REP(d,10)REP(i,res[d])cout << d;
    cout<<endl;

    //REP(i,333)if(cnt[i]!=0)cout << "\nError!\n"<<s<<endl;
}


int main()
{
    //freopen("../input.txt", "r", stdin);
    freopen("../data/A-small-attempt1.in", "r", stdin);
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
