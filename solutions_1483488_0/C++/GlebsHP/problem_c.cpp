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

int length(int num)
{
	int a = 0;
	while (num > 0)
		a++, num /= 10;
	return a;
}

int main() {
	int pw, l1, tc, a, b, pwb, res;
	set <int> used;

	freopen("problem_c.in", "r", stdin);
	freopen("problem_c.out", "w", stdout);
	
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		cin >> a >> b;
		int ans = 0;
		for (int i = a; i <= b; i++)
		{
			used.clear();
			l1 = length(i);
			pw = 10;
			pwb = 1;
			for (int j = 0; j < l1 - 1; j++)
				pwb *= 10;
			for (int j = 1; j < l1; j++)
			{
				res = i / pw + (i % pw) * pwb;
				if (used.count(res) == 1)
					continue;
				used.insert(res);
				if (res <= b && res > i && length(res) == l1)
					ans++;
				pw *= 10;
				pwb /= 10;
			}
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	

	return 0;
}