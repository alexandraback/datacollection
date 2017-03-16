#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int Max = 10010;

int E, R, N, A[Max];
int U[Max];
LL D[Max];

void update(LL &r, LL d)
{
	if (r < d) r = d;
}

LL MyCal()
{
	memset(D, -1, sizeof(D));
	D[E] = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = E; j >= 0; --j)
			if (D[j] > -1)
				update(D[min(j + R, E)], D[j]);

		cout << "i = " << i << ": ";
		for (int j = 0; j <= E; ++j) cout << D[j] << " "; cout << endl;

		for (int j = E; j > 0; --j)
			if (D[j] > -1)
				update(D[j - 1], D[j] + A[i]);

		cout << "i = " << i << ": ";
		for (int j = 0; j <= E; ++j) cout << D[j] << " "; cout << endl;
	}

	return D[0];
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tCase = 1; tCase <= T; ++tCase)
	{
		scanf("%d%d%d", &E, &R, &N);

		priority_queue<PII, vector<PII>> myQ;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &A[i]);
			myQ.push(make_pair(A[i], i));
		}

		LL res = 0;
		set<int> lesS;
		set<int, greater<int>> grtS;

		for (int i = 0; i < N; ++i)
		{
			PII p = myQ.top(); myQ.pop();
			int cur = p.second;

			//cout << p.second << ": " << p.first << endl;
			
			set<int>::iterator lesT = lesS.upper_bound(p.second);
			set<int>::iterator grtT = grtS.upper_bound(p.second);

			LL got = E;
			LL remain = 0;

			if (grtT != grtS.end())
			{
				int pre = *grtT;

				//cout << "pre = " << pre << endl;

				got = min((cur - pre) * (LL)R, got);
			}

			if (lesT != lesS.end())
			{
				int aft = *lesT;

				remain = max(U[aft] - (aft - cur) * (LL)R, 0LL);
				got = max(got - remain, 0LL);

				//cout << "aft = " << aft << endl;
				//cout << "remain = " << remain << endl;
			}

			U[p.second] = got + remain;
			res += p.first * got;
			//cout << "=> Got " << got << " * " << p.first << "|" << U[p.second] << endl;

			lesS.insert(p.second);
			grtS.insert(p.second);
		}

		printf("Case #%d: ", tCase);
		cout << res << endl;
		//if (MyCal() != res) while(1);
	}

	return 0;
}
