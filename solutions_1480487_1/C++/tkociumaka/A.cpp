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

PII S[500];
long double res[500];
int solve(int tcase) {
    printf("Case #%d:", tcase);
    int n;
    scanf("%d", &n);
    int x = 0;
    REP(i, n) {
        int s;
        scanf("%d", &s);
        S[i] = MP(s, i);
        x += s;
    }
    sort(S, S+n);
    long double rem = x;
    long double lev = S[0].FI;
    FOR(i, 1, n-1) {
        int cur = i*(S[i].FI - S[i-1].FI);
        if (rem >= cur) {
            lev = S[i].FI;
            rem -= cur;
        } else {
            lev += rem/i;
            rem = 0;
            break;
        }
    }
    lev += rem/n;
    REP(i, n) {
        if (S[i].FI > lev) {
            res[S[i].SE] = 0;
        } else {
            res[S[i].SE] = (lev - S[i].FI)/x;
        }
    }
    REP(i, n) {
        printf(" %.9Lf", 100*res[i]);
    }
    printf("\n");
    return 0;


}


int main() {
    int t;
    scanf("%d", &t);
    REP(i, t) solve(i+1);

    return 0;
}
