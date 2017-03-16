#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

bool solve()
{
	nrint(X); nrint(R); nrint(C);
	if (C > R) swap(R, C);
	if (R * C % X != 0) return true;
	if (X >= C * 2 + 1) return true;
	if (X >= 7) return true;
	if (X < C) return false;
	int rem = X - C;
	for (int A = 0; A <= rem; A++)
	{
		int B = rem - A;
		bool anyAnswer = false;
		for (int i = A; i < R - B; i++)
		{
			int x = C * i - A;
			int y = C * (R - i - 1) - B;
			if (x % X == 0 && y % X == 0)
				anyAnswer = true;
		}
		if (!anyAnswer) return true;
	}
	return false;
}

int main()
{
	nrint(T);
	jjl(test, T) printf("Case #%d: %s\n", test + 1, solve() ? "RICHARD" : "GABRIEL");
}