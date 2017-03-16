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
using namespace std;

#define SD(i) scanf("%d", &(i))
#define SDD(i, j) scanf("%d%d", &(i), &(j))
#define SDDD(i, j, k) scanf("%d%d%d", &(i), &(j), &(k))
#define SDDDD(i, j, k, l) scanf("%d%d%d%d", &(i), &(j), &(k), &(l))
#define SL(i) scanf("%lld", &(i))
#define SC(i) scanf(" %c", &(i))
#define SS(i) scanf(" %s", &(i))
#define PD(i) printf("%d\n", i)
#define PL(i) printf("%lld", i)
#define PC(i) printf("%c", i)
#define PS(i) printf("%s", i)
#define PN printf("\n");

#define FOR(i,a,b) for(int i=a;i<b;++i)
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

char a[10000];
char m[8][8];
map<char, int> mp;

inline char mul(char c1, char c2) {
    return m[mp[c1]][mp[c2]];
}

char getinv(char ch) {
    if(ch == '1') return '2';
    if(ch == '2') return '1';
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
    return ch - 'a' + 'A';
}

char getinv1(char ch) {
    if(ch == '1') return '1';
    if(ch == '2') return '2';
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
    return ch - 'a' + 'A';
}

void solve() {
    int l;
    LL x;
    SD(l);
    cin>>x;
    SC(a[0]);
    char ch;
    REP(i, l-1) {
        SC(ch);
        a[i+1] = mul(a[i], ch);
    }
    char req = 'i';
    int xc = 1, in = 0;
    bool flag = false, found = true;
    REP(i, 4) {
        REP(j, l) {
            if(a[j] == req) flag = true, in = j, j = l;
        }
        if(flag) break;
        req = mul(getinv1(a[l-1]), req);
        xc++;
        if(xc > x) break;
    }
    found &= flag;
    req = mul(req, 'j');
    flag = false;
    //cout<<found<<":"<<xc<<":"<<req<<endl;
    REP(i, 5) {
        FOR(j, (in+1)%l, l) {
            if(a[j] == req) flag = true, in = j, j = l;
        }
        if(flag) break;
        req = mul(getinv1(a[l-1]), req);
        xc++;
        in = l-1;
        if(xc > x) break;
    }
    found &= flag;
    //cout<<found<<":"<<xc<<":"<<req<<endl;
    req = mul(req, 'k');
    if(found) {
        x -= xc;
        x %= 4;
        ch = a[l-1];
        //cout<<req<<":"<<ch<<":"<<x<<endl;
        while(x--) ch = mul(ch, a[l-1]);
        //cout<<ch<<":"<<req<<endl;
        if(ch != req) PS("NO");
        else PS("YES");
    }
    else PS("NO");
    PN;
}

void solve1() {
    int l, x;
    SDD(l, x);
    char c[l];
    SS(c);
    REP(i, x) REP(j, l) {
        if(i == 0 && j == 0) a[0] = c[0];
        else a[i*l + j] = mul(a[i*l + j - 1], c[j]);
    }
    int in = 0;
    bool flag = false, found = true;
    FOR(i, in, l*x) {
        if(a[i] == 'i') in = i+1, i = MOD, flag = true;
    }
    found &= flag;
    flag = false;
    FOR(i, in, l*x) {
        if(a[i] == mul('i', 'j')) in = i+1, i = MOD, flag = true;
    }
    //REP(i, l*x) cout<<(char)a[i];PN;
    found &= flag;
    if(found) {
        if(a[l*x - 1] != mul('i', mul('j', 'k'))) PS("NO");
        else PS("YES");
    } else PS("NO");
    PN;
}

int main() {
    char t[4][4] = {{'1', 'i', 'j', 'k'}, {'i', '2', 'k', 'J'}, {'j', 'K', '2', 'i'}, {'k', 'j', 'I', '2'}};
    REP(i, 4) REP(j, 4) m[i][j] = t[i][j];
    REP(i, 4) REP(j, 4) m[i][j+4] = m[i+4][j] = getinv(t[i][j]);
    REP(i, 4) REP(j, 4) m[i+4][j+4] = t[i][j];
    REP(i, 8) mp[m[0][i]] = i;
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
        //solve1();
    }
    #ifdef raaja
        }
    #endif
}
