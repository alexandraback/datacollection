#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000;

int p[size];
bool used[size];

bool could_be_bad(int s)
{
	return (s >= 2 && s <= 28);
}

bool could_good(int s, int lm)
{
	return (s + 2) / 3 >= lm;
}

bool could_bad(int s, int lm)
{
	for (int i = 0; i <= 8; i++)
		if (s - i - i - 2 >= i && s - i - i - 2 <= i + 2)
			return i + 2 >= lm;
	return false;
}

int main() {
	int sum[2][2], n, f1, f2, s, tc, h;

	freopen("problem_b.in", "r", stdin);
	freopen("problem_b.out", "w", stdout);

	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		cin >> n >> s >> h;
		sum[0][0] = 0;
		sum[0][1] = 0;
		sum[1][0] = 0;
		sum[1][1] = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
			used[i] = false;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (could_bad(p[i], h) && !could_good(p[i], h) && s > 0)
			{
				ans++;
				s--;
				used[i] = true;
			}
		for (int i = 0; i < n; i++)
			if (!could_good(p[i], h) && could_be_bad(p[i]) && s > 0)
			{
				s--;
				used[i] = true;
			}
		for (int i = 0; i < n; i++)
			if (could_be_bad(p[i]) && s > 0)
			{
				s--;
				used[i] = true;
			}
		for (int i = 0; i < n; i++)
			if (could_good(p[i], h))
			{
				ans++;
				used[i] = true;
			}
		cout << "Case #" << t + 1 << ": " << ans << endl; 
	}

	return 0;
}