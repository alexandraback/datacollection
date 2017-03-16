#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)

using namespace std;

typedef	long long	int64;

set<pair<int,int64> >	hash;
int			S[55], V[55], N, T, ans;
double			t[55 * 55 * 2], P[55];


int	cmp(double X, double Y)
{
	if (fabs(X - Y) < 1e-9) return 0;
	return X < Y ? -1 : 1;
}

int	times = 0;

bool	work(int m, int64 x)
{
	if (m > T)
	{
		ans = m;
		return 1;
	}
	if (hash.find(make_pair(m, x)) != hash.end()) return 0;
	hash.insert(make_pair(m, x));
	
	for (int i = 0; i < N; ++ i)
		P[i] = S[i] + t[m] * V[i];
	
	bool	crash = 0;
	for (int i = 0; i < N && !crash; ++ i)
	for (int j = i + 1; j < N && !crash; ++ j)
		if ((x & (1ll << i)) && (x & (1ll << j)) || !(x & (1ll << i)) && !(x & (1ll << j)))
		{
			crash |= cmp(max(P[i], P[j]) - min(P[i], P[j]), 5) == -1;
		}
	if (crash) return 0;
	
	maxx(ans, m);
	
	bool	touch = 0;
	for (int i = 0; i < N; ++ i)
	for (int j = i + 1; j < N; ++ j)
		if ((x & (1ll << i)) && (x & (1ll << j)) || !(x & (1ll << i)) && !(x & (1ll << j)))
		{
			touch |= !cmp(max(P[i], P[j]) - min(P[i], P[j]), 5);
		}
	
	if (!touch)
		if (work(m + 1, x)) return 1;
	
	for (int i = 0; i < N; ++ i)
	{
		bool	crash = 0;
		
		for (int j = 0; j < N && !crash; ++ j) if (i != j)
		{
			crash |= cmp(max(P[i], P[j]) - min(P[i], P[j]), 5) < 0;
		}
		
		if (!crash)
			if (work(m, x ^ (1ll << i))) return 1;
	}
	
	return 0;
}

int	main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		memset(S, 0, sizeof(S));
		memset(V, 0, sizeof(V));
		memset(t, 0, sizeof(t));
		memset(P, 0, sizeof(P));
		hash.clear();
		T = 0;
		ans = 0;
		
		scanf("%d", &N);
		
		if (test == 7)
			int	asd=1;
		
		int64	x = 0;
		
		for (int i = 0; i < N; ++ i)
		{
			char	side[5];
			scanf("%s%d%d", &side, &V[i], &S[i]);
			if (side[0] == 'L') x += (1ll << i);
		}
		
		for (int i = 0; i < N; ++ i)
		for (int j = i + 1; j < N; ++ j)
		{
			int	u = i, v = j;
			if (S[u] < S[v]) swap(u, v);
			
			if (V[u] > V[v])
			{
				if (S[u] - S[v] >= 5) continue;
				t[++ T] = ((double)S[u] - S[v]) / ((double)V[u] - V[v]);
			} else
			if (V[u] < V[v])
			{
				if (S[u] - S[v] > 5)
				{
					t[++ T] = ((double)S[u] - S[v] - 5) / ((double)V[v] - V[u]);
				}
				t[++ T] = ((double)S[u] - S[v] + 5) / ((double)V[v] - V[u]);
			}
		}
		t[0] = 0;
		sort(t + 1, t + T + 1);
		
		int	_T = 0;
		for (int i = 1; i <= T; ++ i)
			if (cmp(t[i], t[i - 1])) t[++ _T] = t[i];
		T = _T;
		
		work(0, x);
		
		printf("Case #%d: ", test);
		if (ans > T) puts("Possible"); else printf("%.9lf\n", t[ans]);
	}
	
	return 0;
}
