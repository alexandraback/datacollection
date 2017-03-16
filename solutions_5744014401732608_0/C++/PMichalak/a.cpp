#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int (I) = (A); (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int (I) = (A); (I) >= (B); (I)--)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAINS(A,X) (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
using namespace std;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U> &_p) { return os << "(" << _p.X << "," << _p.Y << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& _V) { bool f = true; os << "["; for(auto v: _V) { os << (f ? "" : ",") << v; f = false; } return os << "]"; }
template<typename T> ostream& operator << (ostream &os, const set<T>& _S) { bool f = true; os << "("; for(auto s: _S) { os << (f ? "" : ",") << s; f = false; } return os << ")"; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& _M) { return os << set<pair<T, U>>(ALL(_M)); }
typedef signed long long slong;
typedef long double ldouble;
const slong INF = 1000000100;
const ldouble EPS = 1e-9;

slong N, P;

void read_data() {
    scanf("%lld %lld", &N, &P);
}

const int MAXN = 55;
slong DP[MAXN];
bool R[MAXN][MAXN];

void pre() {
    DP[1] = 1;
    FOR(i,2,MAXN) FOR(j,1,i-1) DP[i] += DP[j];
}

void solve() {
    CLEAR(R);
    FOR(i,1,N-1) FOR(j,i+1,N-1) R[i][j] = true;
    FORD(i,N-1,1) {
        if(P >= DP[i]) {
            R[i][N] = true;
            P -= DP[i];
        }
    }
    if(P > 0) {
        printf("IMPOSSIBLE\n");
        return;
    }
    printf("POSSIBLE\n");
    FOR(i,1,N) {
        FOR(j,1,N) printf("%d", R[i][j]);
        printf("\n");
    }
    //FOR(i,1,50) cout << i << " " << DP[i] << endl;
}

int main() {
    pre();
    int z;
    scanf("%d", &z);
    FOR(test_id,1,z) {
        printf("Case #%d: ", test_id);
        read_data();
        solve();
        printf("\n");
    }
}
