#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
template <class T> int size(T x) { return x.size(); }

int main()
{
	int ts;
	scanf("%d\n", &ts);

	int pow10[9];
	pow10[0] = 1;
	for (int i = 1; i < 9; i++) pow10[i] = pow10[i - 1] * 10;

	set<int>* cnts = new set<int>[2000000 + 1];
	for (int n = 1; n <= 2000000; n++)
	{
		int tmp = n, digits = 0, m = n;
		while (tmp) digits++, tmp /= 10;

		for (int i = 1; i < digits; i++)
		{
			m = (m / 10) + pow10[digits - 1] * (m % 10);
			if (n < m) cnts[n].insert(m);
		}
	}

	for (int t = 0; t < ts; t++)
	{
		int a, b, cnt = 0;
		scanf("%d %d\n", &a, &b);

		for (int i = a; i <= b; i++)
		{
			for (set<int>::const_iterator it = cnts[i].begin(); it != cnts[i].end(); it++)
			{
				if (*it <= b) cnt++;
				else break;
			}
		}

		printf("Case #%d: %d\n", t + 1, cnt);
	}

	return 0;
}