#include<algorithm>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define fup FOR
#define fdo FORD
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x).size())
#define siz SIZE
#define CLR memset((x),0,sizeof (x))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SQR(a) ((a)*(a))

#define DEBUG 1
#define debug(x) {if(DEBUG) cerr << #x << " = " << x << endl;}
#define debugv(x) {if(DEBUG) {cerr << #x << " = "; FORE(it,(x)) cerr << *it << " . "; cerr  <<endl;}}

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef VI vi;
typedef LL lli;

const int inf = 1000000000;
map<int, int> S;
int a[600];

void solve(int tcase) {
    int n;
    printf("Case #%d:\n", tcase);
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    srand(7);
    int ss = -1;
    for(int i = 0; ; ++i) {
        int s = 0;
        int v = 0;
        vector<int> V;
        REP(j, n) {
            if (rand()% 2 == 0) {
                s += a[j];
                v = 3*v + a[j];
                V.PB(a[j]);
            }
        }
        if (S.find(s) != S.end() && S[s] != v) {
            ss = s;
            FORE(it, V) {
                printf("%d ", *it);
            }
            printf("\n");
            break;

        } else S[s] = v;
    }
    srand(7);
    for(int i = 0; ; ++i) {
        int s = 0;
        vector<int> V;
        REP(j, n) {
            if (rand()% 2 == 0) {
                s += a[j];
                V.PB(a[j]);
            }
        }
        if (s == ss) {
            FORE(it, V) {
                printf("%d ", *it);
            }
            printf("\n");
            break;
        }
    }
    S.clear();
}

int main() {
    int t;
    scanf("%d", &t);
    REP(i, t) solve(i+1); 
    return 0;
}
