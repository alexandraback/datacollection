#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout

const int MAXN = 500;

int n, k;
int have[MAXN], t[MAXN], used[MAXN], w[MAXN], p[MAXN], g_used[MAXN];
int inch[MAXN][MAXN];
vector <int> ans, tmp;

bool dfs(int u, int &n_left)
{
	w[u] = 1;

	for (int i = 0; i < n; i++)
		if (!used[i] && inch[u][t[i]])
		{
			if (w[i] == 0)
			{
				p[i] = u;
				if (dfs(i, n_left)) return 1;
			}
			else
			if (w[i] == 1)
			{
				tmp.clear();

				int v = u;
				while (true)
				{
					tmp.PB(v);
					used[v] = 1;
					n_left--;
					if (v == i) break;
					v = p[v];
				}
				for (int j = SIZE(tmp)-1; j>=0; j--)
				{
					inch[n][t[tmp[j]]]--;
					for (int k = 0; k <= 200; k++)
						inch[n][k] += inch[tmp[j]][k];
				}

				return 1;
			}
		}

	w[u] = 2;

	return 0;
}

bool can_go(int n_left)
{
	memset(w, 0, sizeof(int)*(n+2));
	while (dfs(n, n_left)) memset(w, 0, sizeof(int)*(n+2));
//	printf("n_left=%d n=%d\n", n_left, n);
	memset(w, 0, sizeof(int)*(n+1));
	for (int i = 0; i < n; i++) if (!used[i])
		for (int j = 0; j < n; j++) if (!used[j])
			if (inch[i][t[j]])
				w[j]++;
	for (int vv=0; vv!=-1;)
	{
	 	vv = -1;
	 	for (int i = 0; i < n; i++) if (!used[i] && !w[i])
	 	{
	 		vv = i;
	 		break;
	 	}
	 	if (vv==-1 || !inch[n][t[vv]]) break;
	 	n_left--;
	 	used[vv] = 1;
	 	inch[n][t[vv]]--;
	 	for (int k = 0; k <= 200; k++) inch[n][k] += inch[vv][k];
	 	for (int j = 0; j < n; j++)
	 		if (!used[j] && inch[vv][t[j]])
	 			w[j]--;
	}

	return n_left==0;
}

void main2()
{
	scanf("%d%d", &k, &n);
	memset(have, 0, sizeof(have));
	memset(inch, 0, sizeof(inch));
	memset(g_used, 0, sizeof(g_used));
	memset(used, 0, sizeof(used));
	for (int i = 0; i < k; i++)
	{
	 	int x;
	 	scanf("%d", &x);
	 	have[x]++;
	}
	for (int i = 0; i < n; i++)
	{
		int len;
	 	scanf("%d%d", t+i, &len);
	 	for (int j = 0, x; j < len; j++)
	 		scanf("%d", &x),
	 		inch[i][x]++;
	}

	int N_LEFT=n;

	for (int k = 0; k <= 200; k++)
		inch[n][k] = have[k];

	if (!can_go(N_LEFT))
	{
//		cerr << "Hasdas\n";
		gout << "IMPOSSIBLE\n";
		return;
	}

	ans.clear();
	for (bool fnd=1; fnd;)
	{
	 	fnd = 0;
//	 	cerr << "N_LEFT=" << N_LEFT << endl;
	 	for (int i = 0; i < n && !fnd; i++) if (!g_used[i] && have[t[i]])
	 	{
//	 		printf("trying for i=%d\n", i+1);
	 		for (int k = 0; k <= 200; k++)
	 			inch[n][k] = have[k]-(k==t[i])+inch[i][k];
	 		for (int k = 0; k < n; k++)
	 			used[k] = g_used[k];
	 		used[i] = 1;

	 		if (can_go(N_LEFT-1))
	 		{
//	 			printf("Here removing %d\n", i+1);
//	 			cerr << SIZE(ans);
		 		ans.PB(i);
//		 		cerr << "pushed\n";
		 		have[t[i]]--;
		 		for (int k = 0; k <= 200; k++)
		 			have[k] += inch[i][k];
		 		g_used[i] = 1;
	 		 	N_LEFT--;
	 		 	fnd = 1;
//	 		 	cerr << "Good\n";
	 		}
	 	}
	}

 	gout;
 	for (int i = 0; i < n; i++)
 		printf("%d%c", ans[i]+1, " \n"[i+1==n]);
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
