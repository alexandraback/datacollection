#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 4;

struct sub_pattern
{
	int w, h;
	char pat[N][N];
	void output()
	{
		int i, j;
		for (i = h-1; i >= 0; i--, puts(""))
			for (j = 0; j < w; j++)
				printf("%d ", pat[j][i]);
	}
};
struct pattern
{
	vector<sub_pattern> subs;
};
vector<pattern> pats[N+1];

int r, c;
int a[N][N];
char used[N][N];
int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};

inline bool valid(const int &x, const int &y)
{
	return x >= 0 && x < c && y >= 0 && y < r;
}

int bfs(const int &x, const int &y)
{
	int i, ret = 1, nx, ny;
	queue<pair<int, int> > q;
	while (!q.empty()) q.pop();
	used[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		pair<int, int> &qi = q.front();
		for (i = 0; i < 4; i++)
		{
			nx = qi.first + mx[i];
			ny = qi.second + my[i];
			if (valid(nx, ny) && !used[nx][ny] && a[nx][ny] == 0)
			{
				used[nx][ny] = 1;
				ret++;
				q.push(make_pair(nx, ny));
			}
		}
		q.pop();
	}
	return ret;
}

int main()
{
	
pattern pat;
sub_pattern sub;
pat.subs.clear();
sub.w = 1; sub.h = 1;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; 
pat.subs.push_back(sub);
pats[1].push_back(pat);
pat.subs.clear();
sub.w = 2; sub.h = 1;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[1][0] = 1; 
pat.subs.push_back(sub);
sub.w = 1; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; 
pat.subs.push_back(sub);
pats[2].push_back(pat);
pat.subs.clear();
sub.w = 3; sub.h = 1;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[1][0] = 1; sub.pat[2][0] = 1; 
pat.subs.push_back(sub);
sub.w = 1; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[0][2] = 1; 
pat.subs.push_back(sub);
pats[3].push_back(pat);
pat.subs.clear();
sub.w = 2; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[1][0] = 1; sub.pat[1][1] = 1; 
pat.subs.push_back(sub);
sub.w = 2; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[1][0] = 1; 
pat.subs.push_back(sub);
sub.w = 2; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[1][1] = 1; 
pat.subs.push_back(sub);
sub.w = 2; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][1] = 1; sub.pat[1][1] = 1; sub.pat[1][0] = 1; 
pat.subs.push_back(sub);
pats[3].push_back(pat);
pat.subs.clear();
sub.w = 2; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[1][1] = 1; sub.pat[1][0] = 1; 
pat.subs.push_back(sub);
pats[4].push_back(pat);
pat.subs.clear();
sub.w = 2; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[0][2] = 1; sub.pat[1][2] = 1; 
pat.subs.push_back(sub);
sub.w = 3; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][1] = 1; sub.pat[1][1] = 1; sub.pat[2][1] = 1; sub.pat[2][0] = 1; 
pat.subs.push_back(sub);
sub.w = 2; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[1][0] = 1; sub.pat[1][1] = 1; sub.pat[1][2] = 1; 
pat.subs.push_back(sub);
sub.w = 3; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[1][0] = 1; sub.pat[2][0] = 1; 
pat.subs.push_back(sub);
sub.w = 2; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][2] = 1; sub.pat[1][2] = 1; sub.pat[1][1] = 1; sub.pat[1][0] = 1; 
pat.subs.push_back(sub);
sub.w = 3; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[1][0] = 1; sub.pat[2][0] = 1; sub.pat[2][1] = 1; 
pat.subs.push_back(sub);
sub.w = 2; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[0][2] = 1; sub.pat[1][0] = 1; 
pat.subs.push_back(sub);
sub.w = 3; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[1][1] = 1; sub.pat[2][1] = 1; 
pat.subs.push_back(sub);
pats[4].push_back(pat);
pat.subs.clear();
sub.w = 2; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[0][2] = 1; sub.pat[1][1] = 1; 
pat.subs.push_back(sub);
sub.w = 3; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][1] = 1; sub.pat[1][1] = 1; sub.pat[2][1] = 1; sub.pat[1][0] = 1; 
pat.subs.push_back(sub);
sub.w = 2; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][1] = 1; sub.pat[1][0] = 1; sub.pat[1][1] = 1; sub.pat[1][2] = 1; 
pat.subs.push_back(sub);
sub.w = 3; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[1][0] = 1; sub.pat[2][0] = 1; sub.pat[1][1] = 1; 
pat.subs.push_back(sub);
pats[4].push_back(pat);
pat.subs.clear();
sub.w = 2; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][1] = 1; sub.pat[0][2] = 1; sub.pat[1][0] = 1; sub.pat[1][1] = 1; 
pat.subs.push_back(sub);
sub.w = 3; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[1][0] = 1; sub.pat[1][1] = 1; sub.pat[2][1] = 1; 
pat.subs.push_back(sub);
sub.w = 2; sub.h = 3;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[1][1] = 1; sub.pat[1][2] = 1; 
pat.subs.push_back(sub);
sub.w = 3; sub.h = 2;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][1] = 1; sub.pat[1][1] = 1; sub.pat[1][0] = 1; sub.pat[2][0] = 1; 
pat.subs.push_back(sub);
pats[4].push_back(pat);
pat.subs.clear();
sub.w = 1; sub.h = 4;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[0][1] = 1; sub.pat[0][2] = 1; sub.pat[0][3] = 1; 
pat.subs.push_back(sub);
sub.w = 4; sub.h = 1;
memset(sub.pat, 0, sizeof(sub.pat));
sub.pat[0][0] = 1; sub.pat[1][0] = 1; sub.pat[2][0] = 1; sub.pat[3][0] = 1; 
pat.subs.push_back(sub);
pats[4].push_back(pat);

/*
	int i, j, k, l, m, sz, pat_cnt, sub_cnt, w, h, x, y;
*/
/*
	for (i = 1; i <= 4; i++, puts(""))
		for (j = 0; j < pats[i].size(); j++)
		{
			pattern &p = pats[i][j];
			for (k = 0; k < p.subs.size(); k++)
			{
				sub_pattern &sp = p.subs[k];
				sp.output();
			}
		}
*/
/*
	freopen("PD_small_code.txt", "w", stdout);
	puts("pattern pat;");
	puts("sub_pattern sub;");
	while (scanf("%d", &sz) == 1)
	{
		scanf("%d", &pat_cnt);
		while (pat_cnt--)
		{
			scanf("%d", &sub_cnt);
			printf("pat.subs.clear();\n", sz);
			while (sub_cnt--)
			{
				scanf("%d%d", &w, &h);
				printf("sub.w = %d; sub.h = %d;\n", w, h);
				puts("memset(sub.pat, 0, sizeof(sub.pat));");
				while (scanf("%d%d", &x, &y) == 2 && !(x == -1 && y == -1))
					printf("sub.pat[%d][%d] = 1; ", x, y);
				puts("");
				puts("pat.subs.push_back(sub);");
			}
			printf("pats[%d].push_back(pat);\n", sz);
		}
	}
*/
	int i, j, k, l, m, n, t, x;
	char found, allfit;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++)
	{
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: ", cases);
		if ( (r * c) % x != 0)
			puts("RICHARD");
		else
		{
			for (i = 0; i < pats[x].size(); i++)
			{
				pattern &p = pats[x][i];
				found = 0;
				for (j = 0; j < p.subs.size() && !found; j++)
				{
					sub_pattern &sp = p.subs[j];
					for (k = 0; k <= c - sp.w && !found; k++)
						for (l = 0; l <= r - sp.h; l++)
						{
							// fill pattern into a[][]
							memset(a, 0, sizeof(a));
							for (m = 0; m < sp.w; m++)
								for (n = 0; n < sp.h; n++)
									a[k + m][l + n] = sp.pat[m][n];
							
							allfit = 1;
							memset(used, 0, sizeof(used));
							for (m = 0; m < c && allfit; m++)
								for (n = 0; n < r; n++)
								{
									if (used[m][n]) continue;
									if (a[m][n] == 0)
									{
										if (bfs(m, n) % x != 0)
										{
											allfit = 0;
											break;
										}
									}
								}
							if (allfit)
							{
								found = 1;
								break;
							}
						}
				}
				if (!found) // found pattern !
				{
					puts("RICHARD");
					break;
				}
			}
			if (i == pats[x].size())
				puts("GABRIEL");
		}
	}
	return 0;
}
