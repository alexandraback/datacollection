#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#define MAX_SIZE (1000 + 2)

template <typename T1, typename T2>
struct Tuple
{
	T1 x;
	T2 y;
	Tuple() {}
	Tuple(T1 _x, T2 _y): x(_x), y(_y) {}
};

typedef Tuple<double, char> Block;

inline bool comp(const Block &l, const Block &r)
{
	return l.x < r.x;
}

inline int getMax(int x, int y)
{
	return x > y ? x : y;
}

Tuple<int, int> work()
{
	static int f[MAX_SIZE][MAX_SIZE];
	static double naomi[MAX_SIZE], ken[MAX_SIZE];

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lf", &naomi[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%lf", &ken[i]);
	sort(naomi + 1, naomi + n + 1);
	sort(ken + 1, ken + n + 1);

	for(int i = 1; i <= n; ++i)
	{
		f[i][0] = f[i - 1][0] + (naomi[i] > ken[n] ? 1 : 0);
		for(int j = 1; j < i; ++j)
			f[i][j] = getMax(f[i - 1][j - 1] + (naomi[i] > ken[j] ? 1 : 0), f[i - 1][j] + (naomi[i] > ken[n - (i - j) + 1] ? 1 : 0));
		f[i][i] = f[i - 1][i - 1] + (naomi[i] > ken[i] ? 1 : 0);
	}

	int lose = 0;
	vector<Block> t(2 * n + 2);
	for(int i = 1; i <= n; ++i)
		t[i] = Block(naomi[i], 'N');
	for(int i = 1; i <= n; ++i)
		t[i + n] = Block(ken[i], 'K');
	sort(&t[1], &t[2 * n + 1], comp);

	list<Block> l;
	for(int i = 1; i <= 2 * n; ++i)
		l.push_back(t[i]);
	while(true)
	{
		bool flag = false;
		for(list<Block>::iterator iter = l.begin(); !l.empty(); )
		{
			list<Block>::iterator last = iter;
			++iter;
			if(iter == l.end())
				break;
			if(last->y == 'N' && iter->y == 'K')
			{
				l.erase(iter);
				l.erase(last);
				++lose;
				flag = true;
				break;
			}
		}
		if(!flag)
			break;
	}

	int ret = 0;
	for(int i = 0; i <= n; ++i)
		ret = getMax(ret, f[n][i]);
	return Tuple<int, int>(ret, n - lose);
}

int main()
{
	freopen("war.in", "r", stdin);
	freopen("war.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
	{
		Tuple<int, int> ans = work();
		printf("Case #%d: %d %d\n", i, ans.x, ans.y);
	}

	fclose(stdin);
	fclose(stdout);
}
