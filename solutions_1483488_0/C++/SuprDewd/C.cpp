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

int digitcnt[10];
int num1[20], num2[20];

bool same_digits(int a, int b)
{
	memset(digitcnt, 0, 10 << 2);

	while (a) digitcnt[a % 10]++, a /= 10;
	while (b) digitcnt[b % 10]--, b /= 10;

	for (int i = 0; i < 10; i++) if (digitcnt[i] != 0) return false;
	return true;
}

bool recycled_pair(int a, int b)
{
	int cnt1 = 0, cnt2 = 0;
	while (a) num1[cnt1++] = a % 10, a /= 10;
	while (b) num2[cnt2++] = b % 10, b /= 10;

	for (int i = 0; i < cnt1; i++)
	{
		bool all = true;
		for (int j = 0; j < cnt2; j++)
		{
			if (num1[(i + j) % cnt1] != num2[j])
			{
				all = false;
				break;
			}
		}

		if (all) return true;
	}

	return false;
}

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int a, b, cnt = 0;
		scanf("%d %d\n", &a, &b);

		for (int n = a; n <= b; n++)
		{
			for (int m = n + 1; m <= b; m++)
			{
				// printf("%d %d %c %c\n", n, m, same_digits(n, m) ? 'T' : 'F', same_digits(n, m) && recycled_pair(n, m) ? 'T' : 'F');
				if (same_digits(n, m) && recycled_pair(n, m)) cnt++;
			}
		}

		printf("Case #%d: %d\n", t + 1, cnt);
	}

	return 0;
}