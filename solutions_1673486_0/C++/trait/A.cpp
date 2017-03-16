#define FILEIO

#define INPUT "in"
#define OUTPUT "out"

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cassert>
#include <cmath>

#define mp make_pair
#define pb push_back
#define foreach(i,T) for(__typeof(T.begin()) i = T.begin(); i != T.end(); ++i)

using namespace std;

namespace Solve {
	const int MAXN = 100020;

	typedef long double ll;
	
	int B, A; ll a[MAXN] = {1};

	inline void Input(void) {
		scanf("%d%d", &A, &B);
		for (int i = 1; i <= A; i++) scanf("%Lf", &a[i]);
	}

	inline ll Cal(void) {
		ll ret = B + 2, P = 1; /*
		for (int i = 1; i <= A; i++) {
			P *= a[i];
			ll tmp = P * (B - A + 1) + (1 - P) * (B - A + 1 + B + 1);
			if (!(tmp < ret)) break; 
			if (i == A) ret = tmp;
		}*/
		P = 0;
		for (int i = 0; i <= A; i++) {
			P += log10(a[i]);
			int c = B - A + 1 + 2 * (A - i) + B + 1;
			ll tmp = P + log10(B + 1);
			ll t = (tmp < -6) ? 0 : pow(10.0, tmp);
			if (c - t < ret)
				ret = c - t;
		}
		return ret;
	}

	inline ll force(void) {
		ll ret = B + 2, P = 1;
		for (int i = 0; i <= A; i++) {
			P *= a[i];
			ll tmp = B - A + 1 + 2 * (A - i) + B + 1;
			ll t = P * (B + 1);
			if (tmp - t < ret) ret = tmp - t;
		}
		return ret;
	}

	inline void solve(void) {
		Input();
		ll Ans = Cal();
		ll check = force();
		fprintf(stderr, "%Lf %Lf\n", Ans, check);
		assert(fabs(Ans-check) <= 0.000001);
		printf("%Lf\n", Ans);
	}
}

int main(void) {
	#ifdef FILEIO
		freopen(INPUT, "r", stdin);
		freopen(OUTPUT, "w", stdout);
	#endif
	int t, i = 1; for (scanf("%d", &t); t; t--, i++) {
		printf("Case #%d: ", i);
		Solve::solve();
	}
	return 0;
}

