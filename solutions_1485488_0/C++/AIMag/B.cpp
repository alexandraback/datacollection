#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

int dr[] = {+1, -1, 0, 0};
int dc[] = {0, 0, +1, -1};

int C[11][11], F[11][11], H, N, M;

bool inBounds(int r, int c) {
	return (0<=r && r<N && 0<=c && c<M);
}

map<PII, int> fl;

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		fl.clear();
		scanf("%d %d %d", &H, &N, &M);
		FOR(i, 0, N)
			FOR(j, 0, M)
				scanf("%d", &C[i][j]);
		FOR(i, 0, N)
			FOR(j, 0, M)
				scanf("%d", &F[i][j]);

		queue<PII> q;
		q.push(PII(0*M+0, 0));

		while (!q.empty())
		{
			int cR = q.front().first/M;
			int cC = q.front().first%M;
			int TT = q.front().second;
			int HH = max(H - q.front().second, 0);
			q.pop();

			if (HH)
			{
				if (fl.find(PII(cR*M+cC, TT+1)) == fl.end()) {
					q.push(PII(cR*M+cC, TT+1)); fl[PII(cR*M+cC, TT+1)] = 1;
				}
			}

			FOR(p, 0, 4)
			{
				int nR = cR+dr[p];
				int nC = cC+dc[p];
				if (!inBounds(nR, nC)) continue;

				if (HH+50>C[nR][nC]) continue;
				if (F[cR][cC]+50>C[nR][nC]) continue;
				if (F[nR][nC]+50>C[nR][nC]) continue;

				if (F[nR][nC]+50>C[cR][cC]) continue;

				if (TT == 0)
				{
					if (fl.find(PII(nR*M+nC, TT)) != fl.end()) continue;
					q.push(PII(nR*M+nC, TT)); fl[PII(nR*M+nC, TT)] = 1;
				}
				else
				{
					if (HH-F[cR][cC]>=20)
					{
						if (TT >= 10*H) continue;
						if (fl.find(PII(nR*M+nC, TT+10)) != fl.end()) continue;
						q.push(PII(nR*M+nC, TT+10)); fl[PII(nR*M+nC, TT+10)] = 1;
					}
					else
					{
						if (TT >= 10*H) continue;
						if (fl.find(PII(nR*M+nC, TT+100)) != fl.end()) continue;
						q.push(PII(nR*M+nC, TT+100)); fl[PII(nR*M+nC, TT+100)] = 1;
					}
				}
			}
		}
		int res = -1;
		FOR(i, 0, 10*(H+1))
			if (fl.find(PII((N-1)*M+(M-1), i)) != fl.end()) {
				res = i; break;
			}

		printf("Case #%d: %d.%d\n", ++ind, res/10, res%10);
	}

	return 0;
}