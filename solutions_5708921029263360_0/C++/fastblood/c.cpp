#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long lint;
typedef unsigned long long ull;

const int INF = 1000000000;
const lint LINF = 1000000000000000000ll;
const double eps = 1e-8;

int a, b, c, r;
int pa[15][15], pb[15][15], used[15][15][15];

struct comb
{
public:
	comb(int a, int b): a(a), b(b), c(-1)
	{
	}

	int a;
	int b;
	int c;
};

int tryfill(int x, int y)
{
	vector<int> tmp;
	for (int i = 0; i < c; i++)
		tmp.pb(i);
	std::random_shuffle(tmp.begin(), tmp.end());

	for (int ix = 0; ix < c; ix++)
	{
		int i = tmp[ix];

		if (pa[i][x] >= r || pb[i][y] >= r)
			continue;

		if (used[x][y][i])
			continue;

		return i;
	}

	return -1;
}

void solve()
{
	scanf("%d%d%d%d", &a, &b, &c, &r);

	vector<comb> ans;
	int anscnt = 0;

	for (int i = 0; i < 3000; i++)
	{

		memset(pa, 0, sizeof(pa));
		memset(pb, 0, sizeof(pb));
		memset(used, 0, sizeof(used));

		vector<comb> res;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				for (int k = 0; k < r; k++)
					res.pb(comb(i, j));

		while (true)
		{
			bool ok = false;
			for (int i = 0; i < res.size() && !ok; i++)
				if (res[i].c == -1)
				{
					int z = tryfill(res[i].a, res[i].b);
					if (z != -1)
					{
						res[i].c = z;
						pa[z][res[i].a]++;
						pb[z][res[i].b]++;
						used[res[i].a][res[i].b][z] = 1;
						ok = true;
					}
				}

			if (!ok)
				break;
		}

		int cnt = 0;
		for (int i = 0; i < res.size(); i++)
			if (res[i].c != -1)
				cnt++;

		if (anscnt < cnt)
		{
			anscnt = cnt;
			ans = res;
		}
	}

	printf("%d\n", anscnt);
	for (int i = 0; i < ans.size(); i++)
		if (ans[i].c != -1)
			printf("%d %d %d\n", ans[i].a + 1, ans[i].b + 1, ans[i].c + 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	scanf("%d", &tn);
	for (int i = 0; i < tn; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}

	return 0;
}
