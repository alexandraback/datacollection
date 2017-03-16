#define _SCL_SECURE_NO_WARNINGS
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>
//#include <unordered_map>
#include <list>
#include <set>
#include <random>
#include <stack>
#include <sstream>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;



stack <time_t> time_stack;
void startTimer()
{
	time_stack.push(clock());
}
double stopTimer()
{
	double time = clock() - time_stack.top();
	time_stack.pop();
	return time / double(CLOCKS_PER_SEC);
}



#define MAXN 500000
#define MAXM 500
#define MAXK 100
#define INF int(2e9)
#define MOD 1000000009
#define EPS double(1e-15)
#define LAM double(1e-6)
#define PI double(3.14159265359)

double sqr(double x)
{
	return x*x;
}


int dfs(int v, int g[6][6], int n)
{
	int  res = 0;
	if (v == n - 1)
		return 1;
	for (int j = v + 1; j < n; j++)
		if (g[v][j] == 1)
			res += dfs(j, g, n);
	return res;
}


int main()
{
	startTimer();
	ios::sync_with_stdio(false);
#ifdef _HOME_
	ifstream cin("input.txt");
	ofstream out("output.txt");
	//ofstream cout("output.txt");
	//freopen("output.txt", "w", stdout);
#else
	string TASK = "rvq";
	//ifstream cin(TASK + ".in");
	//ofstream cout(TASK + ".out");
	//freopen("dfsongrid.out", "w", stdout);
#endif
	cout.precision(9); cout << fixed;


	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		out << "Case #" << t + 1 << ": ";

		
		int n, m;
		cin >> n >> m;

		if ((1 << (n - 2)) < m)
		{
			out << "IMPOSSIBLE\n";
			continue;
		}
		out << "POSSIBLE\n";

		bool ok = false;
		int ans[6][6];
		for (int bm = 0; bm < 1 << (n*(n - 1) / 2) && !ok; bm++)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					ans[i][j] = 0;
			int mask = 1;
			for (int i = 0; i < n - 1; i++)
				for (int j = i + 1; j < n; j++)
				{
					if (bm & mask)
						ans[i][j] = 1;
					mask <<= 1;
				}

			int cnt = dfs(0, ans, n);
			if (cnt == m)
				ok = true;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				out << ans[i][j];
			out << endl;
		}

	}



	cout << endl;
#ifdef _HOME_
	cout.precision(3);
	cout << fixed << stopTimer() << "s\n";
	system("pause");
#endif

	return 0;
}