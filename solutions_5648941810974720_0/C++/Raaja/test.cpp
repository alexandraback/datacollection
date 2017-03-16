#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <ctime>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;

#define SD(i) scanf("%d", &(i))
#define SDD(i, j) scanf("%d%d", &(i), &(j))
#define SDDD(i, j, k) scanf("%d%d%d", &(i), &(j), &(k))
#define SDDDD(i, j, k, l) scanf("%d%d%d%d", &(i), &(j), &(k), &(l))
#define SL(i) scanf("%lld", &(i))
#define SC(i) scanf(" %c", &(i))
#define SS(i) scanf(" %s", &(i))
#define PD(i) printf("%d", i)
#define PL(i) printf("%lld", i)
#define PC(i) printf("%c", i)
#define PS(i) printf("%s", i)
#define PN printf("\n");

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SFOR(i,a,b,c) for(int i=a;i<b;i+=c)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define RREP(i,n) RFOR(i,n-1,0)
#define ECH(it, v) for(auto it=v.begin();it!=v.end();++it)
#define ALL(x) (x).begin(),(x).end()
#define SRT(x) sort(ALL(x))
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define MOD 1000000007
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long UL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PI;

void solve() {
    string s;
    cin>>s;
    char a[256];
    int c[10];
    CLR(a);
    CLR(c);
    REP(i, s.length()) a[s[i]]++;
    c[0] = a['Z'];
    a['E'] -= a['Z'];
    a['R'] -= a['Z'];
    a['O'] -= a['Z'];
    a['Z'] = 0;
    c[8] = a['G'];
    a['E'] -= a['G'];
    a['H'] -= a['G'];
    a['T'] -= a['G'];
    a['I'] -= a['G'];
    a['G'] -= a['G'];
    c[4] = a['U'];
    a['F'] -= a['U'];
    a['O'] -= a['U'];
    a['R'] -= a['U'];
    a['U'] -= a['U'];
    c[5] = a['F'];
    a['I'] -= a['F'];
    a['V'] -= a['F'];
    a['E'] -= a['F'];
    a['F'] -= a['F'];
    c[2] = a['W'];
    a['T'] -= a['W'];
    a['O'] -= a['W'];
    a['W'] -= a['W'];
    c[3] = a['T'];
    a['H'] -= a['T'];
    a['R'] -= a['T'];
    a['E'] -= a['T'];
    a['E'] -= a['T'];
    a['T'] -= a['T'];
    c[1] = a['O'];
    a['N'] -= a['O'];
    a['E'] -= a['O'];
    a['O'] -= a['O'];
    c[6] = a['X'];
    a['S'] -= a['X'];
    a['I'] -= a['X'];
    a['X'] -= a['X'];
    c[7] = a['S'];
    c[9] = a['I'];
    s = "";
    REP(i, 10) REP(j, c[i]) s += i+'0';
    cout<<s<<endl;
}

int main() {
    #ifdef raaja
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        REP(i, 1) {
    #endif
    int zz = 1, qq;
    SD(zz);
    qq = zz;
    while(zz--) {
        printf("Case #%d: ", qq-zz);
        solve();
    }
    #ifdef raaja
        }
    #endif
}
