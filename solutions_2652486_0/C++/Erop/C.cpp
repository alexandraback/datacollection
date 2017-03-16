#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const double EPS = 1e-9;

struct S
{
	string s;
	int prod;
	S (){}
	S (string &_s, int _prod)
	{
		s = _s;
		prod = _prod;
	}
	bool operator < (const S & other) const
	{
		if (s != other.s)
			return s < other.s;
		return prod < other.prod;
	}
};

map<S, int> prob;

int R, N, M, K;
char s[10];
char x[10];

void calc(int cur, int m)
{
	if (cur >= N)
	{
		s[cur] = 0;
		memcpy(x, s, sizeof(s));
		sort(x, x + cur);
		++prob[S(string(x), m)];
		return;
	}
	for (int i = 2; i <= M; ++i)
	{
		s[cur] = i + '0';
		calc(cur + 1, m);
		calc(cur + 1, m*i);
	}
}

void solve()
{
	
	scanf("%d%d%d%d", &R, &N, &M, &K);
	calc(0, 1);
	vector<S> cur;
	puts("");
	for (int i = 0; i < R; ++i)
	{
		cur.clear();
		for (int j = 0; j < K; ++j)
		{
			int t;
			scanf("%d", &t);
			for (map<S, int>::iterator it = prob.begin(); it != prob.end(); ++it)
			{
				if (it->first.prod == t)
					cur.push_back(it->first);
			}
		}
		sort(cur.begin(), cur.end());
		string prv = "";
		int cnt = 0;
		int p = 0;
		int xans = 0;
		string sans = "";
		for (int j = 0; j < cur.size(); ++j)
		{
			if (cur[j].s == prv)
			{
				++cnt;
				p += prob[cur[j]];
			}
			else
			{
				prv = cur[j].s;
				cnt = 1;
				p = prob[cur[j]];
			}
			if (cnt == K && p > xans)
			{
				xans = p;
				sans = prv;
			}
		}
		puts(sans.c_str());
	}

}
int main()
{
	freopen("Ctest.txt", "r", stdin);
	freopen("Cout.txt", "w", stdout);

	int T;
	scanf ("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		fprintf(stderr, "%d/%d\n", i+1, T);
		solve();
	}
	return 0;
}