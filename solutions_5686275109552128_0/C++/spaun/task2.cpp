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
#define INF 999999999

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int D;
		cin >> D;
		vector<int> a(D);
		for (int i = 0; i < D; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		int ans = INF;
		for (int i = 1; i <= a[D - 1]; i++)
		{
			int s = i;
			for (int j = 0; j < D; j++)
			{
				s += (a[j] - 1) / i;
			}
			if (ans > s)
				ans = s;
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	//system("PAUSE");
	return 0;
}