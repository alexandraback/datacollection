#include <bits/stdc++.h>

using namespace std;

struct Outfit
{
	int j, p, s;
	Outfit(int J, int P, int S): j(J), p(P), s(S) {}
};

struct Info
{
	int j, p, s;
	int cnt[3][11][11];
	vector<Outfit> res;
	Info() {}
	Info(int J, int P, int S): j(J), p(P), s(S) { memset(cnt, 0, sizeof(cnt)); }
};

bool operator<(Info x, Info y)
{
	if (x.j == y.j)
	{
		if (x.p == y.p)
			return x.s < y.s;
		return x.p < y.p;
	}
	return x.j < y.j;
}

int test, J, P, S, k, cnt[3][11][11];
vector<Info> outfit;

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d %d %d %d", &J, &P, &S, &k);
		outfit.clear();
		for (int j = 1; j <= J; ++j)
		for (int p = 1; p <= P; ++p)
		for (int s = 1; s <= S; ++s)
			outfit.push_back(Info(j, p, s));

		int mxi = 0;
		for (int i = 0; i < (int)outfit.size(); ++i)
		{
			Info &b = outfit[i];
			b.res.push_back(Outfit(b.j, b.p, b.s));
			b.cnt[0][b.j][b.p] = b.cnt[1][b.p][b.s] = b.cnt[2][b.s][b.j] = 1;
			for (int j = 0; j < i; ++j)
			{
				Info &a = outfit[j];
				// cout << a.cnt[0][b.j][b.p] << ' ' << a.cnt[1][b.p][b.s] << ' ' << a.cnt[2][b.s][b.j] << '\n';
				// cout << a.res.size() << ' ' << b.res.size() << '\n';
				if (a.cnt[0][b.j][b.p] < k && a.cnt[1][b.p][b.s] < k
					&& a.cnt[2][b.s][b.j] < k && a.res.size() >= b.res.size())
				{
					b.cnt[0][b.j][b.p] = a.cnt[0][b.j][b.p] + 1;
					b.cnt[1][b.p][b.s] = a.cnt[1][b.p][b.s] + 1;
					b.cnt[2][b.s][b.j] = a.cnt[2][b.s][b.j] + 1;
					b.res = a.res;
					b.res.push_back(Outfit(b.j, b.p, b.s));
					if (b.res.size() > outfit[mxi].res.size())
						mxi = i;
				}
			}
		}

		printf("Case #%d: %d\n", tt, outfit[mxi].res.size());
		for (int i = 0; i < (int)outfit[mxi].res.size(); ++i)
			printf("%d %d %d\n", outfit[mxi].res[i].j, outfit[mxi].res[i].p, outfit[mxi].res[i].s);
	}
	return 0;
}