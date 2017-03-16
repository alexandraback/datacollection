#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair
#define sc second
#define ft first

#define FOR(i,N) for (int i=1; i<=N; i++)
#define REP(i,l,r) for (int i=l; i<=r; i++)

#define INF ~0U>>1
#define eps 1e-9

int T, J, P, S, K;

int main ()
{
#ifndef ONLINE_JUDGE
#ifndef MEKTPOY
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
#else
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
#endif
	cin >> T;
	for (int test = 1; test <= T; test ++)
	{
		printf ("Case #%d: ", test);
		cin >> J >> P >> S >> K;
		if (S <= K)
		{
			printf ("%d\n", J * P * S);
			for (int i = 1; i <= J; i ++)
				for (int j = 1; j <= P; j ++)
					for (int k = 1; k <= S; k ++)
					{
						printf ("%d %d %d\n", i, j, k);
					}
		}
		else
		{
			printf ("%d\n", J * P * K);
			for (int i = 0; i < J; i ++)
			{
				for (int j = 0; j < P; j ++)
					for (int k = 0; k < K; k ++)
					{
						int a = i, b = j, c = (i + j + k) % S;
						printf ("%d %d %d\n", a + 1, b + 1, c + 1);
					}
			}
		}
	}
	return 0;
}
