#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n, m, empty;
bool isEmpty[51][51];

void output()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			if(i == 1 && j == 1)
				cout << "c";
			else if(isEmpty[i][j])
				cout << ".";
			else
				cout << "*";
		cout << endl;
	}
}

void solve()
{
	cout << endl;
	cin >> n >> m >> empty;
	empty = n * m - empty;
	memset(isEmpty, false, sizeof(isEmpty));
	if(empty == 1 || n == 1 || m == 1)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(empty > 0)
				{
					isEmpty[i][j] = true;
					empty --;
				}
		output();
	}
	else
	{
		bool haveSol = false;
		for(int N = 2; N <= n; N++)
			for(int M = 2; M <= m; M++)
			{
				if(haveSol) continue;
				int minv = N * 2 + M * 2 - 4;
				int maxv = N * M;
				if(minv <= empty && empty <= maxv)
				{
					empty -= minv;
					haveSol = true;
					for(int i = 1; i <= N; i++)
						for(int j = 1; j <= M; j++)
							if(i <= 2 || j <= 2)
								isEmpty[i][j] = true;
							else if(empty > 0)
							{
								empty --;
								isEmpty[i][j] = true;
							}

				}
			}

		if(!haveSol)
			cout << "Impossible" << endl;
		else
			output();
	}
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
