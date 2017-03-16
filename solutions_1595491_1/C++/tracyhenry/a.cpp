#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

struct score
{
	int a, b, c, sum;
	int surprising;
};

int F[110][110], A[110];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	vector<score> P[100];
	for (int i = 0; i < 100; i ++)
		P[i].clear();
	for (int a = 0; a <= 10; a ++)
		for (int b = 0; b <= 10; b ++)	
			for (int c = 0; c <= 10; c ++)
				if (abs(a - b) <= 2 && abs(a - c) <= 2 && abs(b - c) <= 2)
				{
					score cur;
					cur.a = a, cur.b = b, cur.c = c;
					cur.sum = a + b + c;
					if (abs(a - b) > 1 || abs(a - c) > 1 || abs(b - c) > 1)
						cur.surprising = 1;
					else cur.surprising = 0;
					P[cur.sum].push_back(cur);
				}
				
	//
	int T, n, s, least;
	cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		cin >> n >> s >> least;
		for (int i = 1; i <= n; i ++)
			cin >> A[i];
		//DP
		for (int i = 0; i <= n; i ++)
			for (int j = 0; j <= s; j ++)
				F[i][j] = -10000;
		F[0][0] = 0;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j <= min(i, s); j ++)
			{
				int cur = A[i + 1], B;
				//suprising
				B = 0;
				for (int k = 0; k < P[cur].size(); k ++)
					if (P[cur][k].surprising)
 						B = max(B, max(max(P[cur][k].a, P[cur][k].b), P[cur][k].c));
				if (j < s)
					F[i + 1][j + 1] = max(F[i + 1][j + 1], F[i][j] + (B >= least ? 1 : 0));
				//not surprising
				B = 0;
				for (int k = 0; k < P[cur].size(); k ++)
					if (! P[cur][k].surprising)
						B = max(B, max(max(P[cur][k].a, P[cur][k].b), P[cur][k].c));
				F[i + 1][j] = max(F[i + 1][j], F[i][j] + (B >= least ? 1 : 0));
			}
		cout << F[n][s] << endl;
	}
	return 0; 
}
