#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn (55)
#define maxn2 (1305)

int T;
int N;
int S[maxn];
int P[maxn];
int L[maxn]; // which lane (0 - L, 1 - R)

double ct[maxn2]; // collision time
int c1[maxn2]; // car 1 (slower)
int c2[maxn2]; // car 2 (faster)
int cn;

int cs[maxn2];

int l[maxn];
int pos;
int sol;

bool cmpfcs(int a, int b)
{
	if(ct[a] != ct[b])
		return ct[a] < ct[b];
	else if(c1[a] != c1[b])
		return c1[a] < c1[b];
	else
		return c2[a] < c2[b];
}

double pt[maxn];

double abs1d(double a)
{
	return (a >= 0) ? a : -a;
}

int has_collision(double t)
{
	int i, j;

//	printf("     collision test %lf\n", t);
	for(i = 0; i < N; ++i)
	{
		pt[i] = P[i] + S[i] * t;
//		printf("     %d : pos %c  %lf\n", i + 1, "LR"[l[i]], pt[i]);
	}

	for(i = 0; i < N; ++i)
	{
		for(j = i + 1; j < N; ++j)
		{
			if(abs1d(pt[i] - pt[j]) < 5.0 - 1e-9 && l[i] == l[j])
			{
//				printf("    COLLIDE\n");
				return 1;
			}
		}
	}

	return 0;
}

int attempt(int id)
{
	if(id < cn)
	{
		if(sol < id)
			sol = id;

		int cid = cs[id];
//		printf("attempt %d : %lf %d %d\n", id + 1, ct[cid], c1[cid] + 1, c2[cid] + 1);

		int a = c1[cid];
		int b = c2[cid];

		int la = l[a];
		int lb = l[b];

		int i, j;
		for(i = 0; i < 2; ++i)
		{
			if(id > 0)
			{
				int incon = 0;
				for(j = id - 1; j >= 0 && abs1d(ct[cs[j]] - ct[cid]) < 1e-9 && !incon; --j)
				{
					if(c1[cs[j]] == a && l[a] == !i)
						incon = 1;
					if(c1[cs[j]] == b && l[b] == i)
						incon = 1;
					if(c2[cs[j]] == a && l[a] == !i)
						incon = 1;
					if(c2[cs[j]] == b && l[b] == i)
						incon = 1;
				}

				if(incon)
					continue;
			}

			l[a] = i;
			l[b] = !i;

			if(!has_collision(ct[cid]))
			{
				if(attempt(id + 1))
					return 1;
			}

			l[a] = la;
			l[b] = lb;
		}

		return 0;
	}
	else
	{
		pos = 1;
		return 1;
	}
}

int main()
{
	int tt;
	scanf("%d", &T);

	for(tt = 1; tt <= T; ++tt)
	{
		int i, j;

//		printf("Run case %d\n", tt);
		scanf("%d", &N);
		for(i = 0; i < N; ++i)
		{
			int a, b;
			char s[4];
			scanf("%s %d %d", s, &a, &b);
			S[i] = a;
			P[i] = b;
			L[i] = (s[0] == 'R');
			l[i] = L[i];
		}

		cn = 0;

		for(i = 0; i < N; ++i)
		{
			for(j = 0; j < N; ++j)
			{
				if(S[i] < S[j])
				{
//					printf("%d - %d : %lf %lf\n", i + 1, j + 1, ((double) P[i] - P[j] - 5.0) / (S[j] - S[i]), ((double) P[i] - P[j] + 5.0) / (S[j] - S[i]));
					double ct1 = ((double) P[i] - P[j] - 5.0) / (S[j] - S[i]);
					double ct2 = ((double) P[i] - P[j] + 5.0) / (S[j] - S[i]);

					if(ct2 > 1e-9)
					{
						if(ct1 < 0)
							ct1 = 0;

						ct[cn] = ct1;
						c1[cn] = i;
						c2[cn] = j;
						++cn;
					}
				}
			}
		}

		for(i = 0; i < cn; ++i)
		{
//			printf("%d : %lf %d %d\n", i, ct[i], c1[i] + 1, c2[i] + 1);

			cs[i] = i;
		}

		sort(cs, cs + cn, cmpfcs);

		pos = 0;
		sol = 0;
		attempt(0);

		if(pos)
			printf("Case #%d: Possible\n", tt);
		else
			printf("Case #%d: %lf\n", tt, ct[cs[sol]]);
	}

	return 0;
}
