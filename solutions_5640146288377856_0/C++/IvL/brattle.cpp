#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

int SolveLine(int C, int W){
	if (C == W) return W;
	return W + 1;
}

int Solve(){
	int R, C, W;
	scanf("%d%d%d", &R, &C, &W);
	return R * (C / W) - 1 + SolveLine(C % W + W, W);
}

int main(){
	int t;
	scanf("%d", &t);
	FOR(1, t + 1, i){
		printf("Case #%d: %d\n", i, Solve());
	}
	return 0;
}

