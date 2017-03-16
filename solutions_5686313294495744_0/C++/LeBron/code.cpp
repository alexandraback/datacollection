/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;

const int N = 1001;

int tests;
int n;
string st1[N], st2[N];
int dp[1 << 17];
int ts;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	freopen("F:/in.txt", "r", stdin);
	freopen("F:/out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> n;
		++ts;
		for (int i = 0; i < n; i++)
		{
			cin >> st1[i] >> st2[i];
		}
		for (int i = 0; i < (1 << 16); i++)
		{
			dp[i] = 0;
		}
		for (int mask = 0; mask < (1 << 16); mask++)
		{
			for (int ad = 0; ad < n; ad++)
			{
				if (mask&(1 << ad))
					continue;
				bool ok1 = 0;
				bool ok2 = 0;
				for (int i = 0; i < n; i++)
				{
					if (!(mask&(1 << i)))
						continue;
					if (st1[ad] == st1[i])
						ok1 = 1;
					if (st2[ad] == st2[i])
						ok2 = 1;
				}
				int res = dp[mask];
				if (ok1&&ok2)
					res++;
				dp[mask | (1 << ad)] = max(dp[mask | (1 << ad)], res);
			}
		}
		cout << "Case #" << ts << ": " << dp[(1 << n) - 1] << endl;
	}

	cin.get(); cin.get();
	return 0;
}