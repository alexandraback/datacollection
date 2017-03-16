#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;

int R, N, M, K;
VI prod;

bool check(VI &num, int p)
{
	int m = num.size();
	for (int i = 0; i < (1 << m); ++i)
	{
		int q = 1;
		for (int j = 0; j < m; ++j)
			if (i & (1 << j)) q *= num[j];
		if (p == q) return true;
	}
	return false;
}

bool check(VI &num)
{
	for (int i = 0; i < K; ++i)
		if (!check(num, prod[i])) return false;
	return true;
}

vector<VI> ans;
VI curr;
void search(int i)
{
	if (i >= N)
	{
		if (check(curr)) ans.push_back(curr);
		return;
	}
	for (int j = 2; j <= M; ++j)
	{
		curr[i] = j;
		search(i + 1);
	}
}
void solve()
{
	ans.clear();
	curr.resize(N);
	search(0);
	VI out(N);
	for (int i = 0; i < N; ++i) out[i] = 2;
	if ((int)ans.size() > 0)
	{
		int index = rand() % ans.size();
		out = ans[index];
	}
	for (int i = 0; i < N; ++i)
	{
		//if (i > 0) printf(" ");
		printf("%d", out[i]);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		printf("Case #%d:\n", cs);
		scanf("%d%d%d%d", &R, &N, &M, &K);
		prod.resize(K);
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < K; ++j) scanf("%d", &prod[j]);
			solve();
		}
	}
	return 0;
}
