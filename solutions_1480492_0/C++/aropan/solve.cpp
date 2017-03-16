#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 10;
const double EPS = 1e-9;
const double INF = 1e+30;

int a[MAXN];
double x[MAXN];
int S[MAXN], P[MAXN];
pair < double, pair <int, int> > t[MAXN * MAXN];
int upd[MAXN][MAXN];
int n, m;
double ans;


int rec(int k)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] == a[j])
			{
				if (fabs(x[i] - x[j]) < 5.0 - EPS)
					return false;
//				if (fabs(x[i] - x[j]) - 5.0 < EPS && ((x[i] < x[j]) ^ (S[i] <= S[j])))
//					return false;
			}

	if (k == m)
	{
		ans = INF;
		return true;
	}
	if (upd[t[k].second.first][t[k].second.second] == 0)
		ans = max(ans, t[k].first);

	upd[t[k].second.first][t[k].second.second]++;
	for (int i = 0; i < n; i++) x[i] += (t[k].first - t[k - 1].first) * S[i];
	if (fabs(x[t[k].second.first] - x[t[k].second.second]) < 5.0 - EPS)
	{
		if (rec(k + 1)) return true;
	}
	else
	{
    	int
    		fs = a[t[k].second.first],
    		sc = a[t[k].second.second];

    	for (int i = 0; i < 2; i++)
    	{
    		a[t[k].second.first] = i;
    		a[t[k].second.second] = 1 - i;
    		if (rec(k + 1)) return true;
    	}
    	a[t[k].second.first] = fs;
    	a[t[k].second.second] = sc;
    }
	for (int i = 0; i < n; i++) x[i] -= (t[k].first - t[k - 1].first) * S[i];
	upd[t[k].second.first][t[k].second.second]--;
	return false;
}

int main()
{
    freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

    int test;
    scanf("%d", &test);
    for (int T = 1; T <= test; T++)
    {
    	scanf("%d\n", &n);
    	for (int i = 0; i < n; i++)
    	{
    		char c;
    		scanf("%c %d %d\n", &c, &S[i], &P[i]);
    		a[i] = c == 'R';
    		x[i] = P[i];
    	}

    	m = 0;
    	t[m++] = make_pair(0, make_pair(0, 0));
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    		{
    			if (i == j || P[i] > P[j] || S[i] <= S[j]) continue;
    			double
    				st = (P[j] - P[i] - 5) / (double)(S[i] - S[j]),
    				fn = (P[j] - P[i] + 5) / (double)(S[i] - S[j]);
    			t[m++] = make_pair(st, make_pair(i, j));
    			t[m++] = make_pair((st + fn) / 2, make_pair(i, j));
    			t[m++] = make_pair(fn, make_pair(i, j));
    		}
    	ans = 0;
    	sort(t, t + m);
    	memset(upd, 0, sizeof(upd));
    	rec(1);
    	printf("Case #%d: ", T);
    	if (ans > INF / 2)
    		puts("Possible");
    	else
    		printf("%.10lf\n", ans);
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
