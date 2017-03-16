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
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define RREP(i,n) RFOR(i,n-1,0)
#define ECH(it, v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define MKP make_pair
#define MOD 1000000007
typedef long long LL;
typedef unsigned long long uLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

int r, c, m, d;
char a[2500];
void printtt() {
    REP(i, r*c)
        if(i%c == 0) printf("\n%c", a[i]);
        else printf("%c", a[i]);
        printf("\n");
}
void printt1() {
    printf("\n");
    REP(i, c) {
        REP(j, r) {
            printf("%c", a[j*c+i]);
        }
        printf("\n");
    }
}
void solve(bool flag) {
    if(m >= (r-2) * c) {
        d = r*c-m;
        if(d < 4 || d == 5 || d == 7) printf("\nImpossible\n");
        else {
            REP(i, m+d) a[i] = '*';
            if(d&1) {
                REP(i, (d>>1)-1) a[i] = a[i+c] = '.';
                a[2*c] = a[2*c+1] = a[2*c+2] = '.';
            } else REP(i, (d>>1)) a[i] = a[i+c] = '.';
            a[0] = 'c';
            flag ? printt1() : printtt();
        }
    }
    else {
        if(m%c != c-1) {
            REP(i, m) a[i] = '*';
            FOR(i, m, r*c) a[i] = '.';
            a[r*c-1] = 'c';
            flag ? printt1() : printtt();
        } else {
            d = r*c-m;
            if(c == 2 || (d == 2*c+1 && c < 4)) printf("\nImpossible\n");
            else {
                REP(i, m) a[i] = '*';
                FOR(i, m, r*c) a[i] = '.';
                a[r*c-1] = 'c';
                if(d == 2*c+1) {
                    a[(r-1)*c] = a[(r-2)*c] = '*';
                    a[(r-2)*c - 2] = a[(r-2)*c - 3] = '.';
                } else {
                    d = m / c + 1;
                    a[d*c] = '*';
                    a[d*c - 2] = '.';
                }
                flag ? printt1() : printtt();
            }
        }
    }
}

int main() {
    #ifdef raaja
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int zz, qq = 0;
    scanf("%d ", &zz);
    while(qq++ < zz) {
        scanf("%d %d %d ", &r, &c, &m);
        printf("Case #%d:", qq);
        if(c == 1 || r == 1 || m == 0 || r*c-m == 1) {
            REP(i, m) a[i] = '*';
            FOR(i, m, r*c) a[i] = '.';
            a[r*c-1] = 'c';
            printtt();
        } else if(c <= r) {
            solve(0);
        } else {
            swap(r, c);
            solve(1);
        }
    }
}
