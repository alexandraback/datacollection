// Fruit of Light
// FoL CC
// Orange Strawberry
// Som mudra, pekna a sikovna
// Sikovnejsia ako vcera

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#ifdef EBUG
#define DEBUG(x) cerr << "DEBUG (F " << __FUNCTION__ << ", L" << __LINE__ << "): " << #x << ": " << x << endl;
#define DPRINTF(args...) fprintf(stderr, "DEBUG: " args) // :P
#define DBG if (1)
#else 
#define DEBUG(x)
#define DPRINTF(args...)
#define DBG if (0)
#endif

#define FORRANGE(i, ma) for (typeof(ma) i = 0; i < (ma); i++)
#define FORRANGE1(i, ma) for (typeof(ma) i = 1; i <= (ma); i++)
#define FOREACH(it, data) for (typeof((data).begin()) it = (data).begin(); it != (data).end(); ++it)

typedef long long ll;

// ============================================================================

#define mp make_pair

vector<pair<int, ll> > A, B;
int An, Bn;
ll rec(int Ai, int Bi, ll sofar) {
    if (Ai == An || Bi == Bn) return sofar;
    ll ma = 0;
    if (A[Ai].first == B[Bi].first) {
        if (A[Ai].second < B[Bi].second) {
            B[Bi].second -= A[Ai].second;
            ma = max(ma, rec(Ai+1, Bi, sofar+A[Ai].second));
            B[Bi].second += A[Ai].second;
        }
        else {
            A[Ai].second -= B[Bi].second;
            ma = max(ma, rec(Ai, Bi+1, sofar+B[Bi].second));
            A[Ai].second += B[Bi].second;
        }
    }
    else
        ma = max(rec(Ai, Bi+1, sofar), rec(Ai+1, Bi, sofar));
    return ma;
}

int main() {
    int T; scanf("%d", &T); FORRANGE1(t, T) {
        A.clear(); B.clear();
        scanf("%d%d", &An, &Bn);
        FORRANGE(ai, An) { int t; ll c; scanf("%lld%d", &c, &t); A.push_back(mp(t, c)); }
        FORRANGE(bi, Bn) { int t; ll c; scanf("%lld%d", &c, &t); B.push_back(mp(t, c)); }
        printf("Case #%d: %lld\n", t, rec(0,0,0));
    }
	return 0;
}
