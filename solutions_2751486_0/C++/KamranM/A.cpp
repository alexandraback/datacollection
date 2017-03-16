#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#define MAXN 1000100
#define NW 5
using namespace std;
typedef long long i64;
char vowel[] = {'a', 'e', 'i', 'o', 'u'};
int T, n;
string str;
int dp1[MAXN], dp2[MAXN];
bool cons[300];

void init()
{
	for (int i = 0; i < 300; ++i)
		cons[i] = true;
	for (int i = 0; i < NW; ++i)
		cons[vowel[i]] = false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A-small-attempt0.out");

	init();

	cin >> T;

	for (int ts = 1; ts <= T; ++ts)
	{
		cin >> str >> n;

		int len = str.length();

		dp1[len] = -1;
		for (int i = len-1; i >= 0; --i)
			if (cons[str[i]])
				dp1[i] = max(i, dp1[i+1]);
			else
				dp1[i] = -1;

		i64 ans = 0ll;

		dp2[len] = -1;
		for (int i = len-1; i >= 0; --i)
		{
			if (cons[str[i]])
			{
				if (dp1[i] - i + 1 >= n)
					dp2[i] = i + n - 1;
				else
					dp2[i] = dp2[i+1];
			}
			else
				dp2[i] = dp2[i+1];
			if (dp2[i] >= 0)
				ans += (len-dp2[i]);
		}

		cout << "Case #" << ts << ": " << ans << endl;

	}



	//system("PAUSE");
	cin.close(); cout.close();
	return 0;
}

