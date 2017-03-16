#include <bits/stdc++.h>
using namespace std;

#define FOR(x, a, b) for (int x = (a); x <= (b); x++)

int wynik(int R, int C, int W)
{
	return R * (C / W) + W - (C % W == 0 ? 1 : 0);
}

int zrob_test()
{
	int R, C, W;
	cin >> R >> C >> W;
	return wynik(R, C, W);
}

int main()
{
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	FOR(t, 1, T)
		cout << "Case #" << t << ": " << zrob_test() << '\n';
	return 0;
}
