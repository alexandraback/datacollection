
#include<cassert>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstring>
#include<stack>
#include<sstream>
#include<complex>
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define DEBU true
#define debug(x) { if (DEBU) cerr << #x << " = " << x << "\n"; }
#define debugv(x) { if (DEBU) { cerr << #x << " = "; FORE(it,(x)) cerr<< *it <<","; cerr<<"\n"; } }
#define fup(i,a,b) for(int i=(a);i<=(b);i++)
#define fdo(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x),0,sizeof (x))
#define abso(a) ((a)<0?(-(a)):(a))
#define maxi(a,b) ((a)>(b)?(a):(b))
#define mini(a,b) ((a)<(b)?(a):(b))
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define siz(a) ((int)a.size())
#define inf 1000000000
#define SQR(a) ((a)*(a))

using namespace std;
typedef long long lli;
typedef double ld;

int cas, n;
#define maxn 22
int t[maxn];

int kto[maxn];
bool go(int act, int s1, int s2) {
    if (act > n) {
        if (s1 == s2 && s1 > 0) {
            fup(i, 1, n) if (kto[i] == 1) printf("%d ", t[i]);
            printf("\n");
            
            fup(i, 1, n) if (kto[i] == 2) printf("%d ", t[i]);
            printf("\n");

            return true;
        }
        return false;
    }
    kto[act] = 1;
    if (go(act + 1, s1 + t[act], s2)) return 1;

    kto[act] = 2;
    if (go(act + 1, s1, s2 + t[act])) return 1;
    kto[act] = 0;
    if (go(act + 1, s1, s2)) return 1;
    
    return false;
}

int main() {
    cin >> cas;
    fup(c, 1, cas) {
        cin >> n;
        fup(i, 1, n) cin >> t[i];
        printf("Case #%d:\n", c);
        if (go(1, 0, 0)) {
        } else printf("Impossible\n");
    }
	return 0;
}

