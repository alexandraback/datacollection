#pragma comment(linker, "/STACK:300000000")
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <set>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#pragma warning(disable : 4996)

using namespace std;
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007ull
#define INF 99999999999999999

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int k = 0;
		int ans = 0;
		for (int i = 0; i <= n; i++)
		{
			if (k < i)
			{
				ans += i - k;
				k = i;
			}
			k += s[i] - '0';

		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	//system("PAUSE");
	return 0;
}