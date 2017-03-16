#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<sstream>
#include<ctime>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<cstdio>
#include<map>
using namespace std;
typedef unsigned long long u64;
typedef long long i64;
typedef unsigned long long u32;
typedef long long i32;
#pragma comment(linker, "/STACK:16777216");
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;
i64 i64INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
i32 i32INF = 1000 * 1000 * 1000;
double INF = 1e10;
double mINF = INF + 100.0;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, 1, -1};
int n, m;
double h;
double clg[100][100];
double flr[100][100];
double dp[100][100];

bool ok(int i, int j)
{
	return i >=0 && i < n && j >= 0 && j < m;
}

double getWaterLevel(double time, int i, int j)
{
	return h - time*10.0 - flr[i][j];
}

double getWait(int fromi, int fromj, int toi, int toj, double time)
{
	double level = h - time*10.0;
	
	double res = 0.0;

	res = max(res, (-(clg[toi][toj]-50.0)+level)/10.0);
	res = max(res, (-(clg[toi][toj]-50.0)+flr[fromi][fromj])/10.0);
	res = max(res, (-(clg[toi][toj]-50.0)+flr[toi][toj])/10.0);
	res = max(res, (-(clg[fromi][fromj]-50.0)+flr[toi][toj])/10.0);

	return res;
}

void solve(int i, int j, bool waited)
{
	for(int ii = 0; ii < 4; ii++)
	{
		int _i = i+di[ii];
		int _j = j+dj[ii];
		if(ok(_i, _j))
		{
			double wait = getWait(i, j, _i, _j, dp[i][j]);
			double res;
			if(waited || wait > EPS)
			{
				if(getWaterLevel(dp[i][j]+wait, i, j) - 20.0 > -EPS)
					res = dp[i][j] + wait + 1.0;
				else
					res = dp[i][j] + wait + 10.0;
			}
			else
				res = dp[i][j];

			if(dp[_i][_j] - res > EPS)
			{
				dp[_i][_j] = res;
				solve(_i, _j, waited || wait > EPS);
			}
		}
	}

	return;
}

int main()
{
	freopen("B-small-attempt2.in" ,  "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);

	int t;
	cin >> t;
	for(int test = 1; test <= t; test++)
	{
		cin >> h >> n >> m;

		for(int i = 0; i < 100; i++) for(int j = 0; j < 100; j++) dp[i][j] = INF;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> clg[i][j];

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> flr[i][j];

		dp[0][0] = 0.0;
		solve(0, 0, false);

		printf("Case #%d: %0.9lf\n", test, dp[n-1][m-1]);
	}

	return 0;
}