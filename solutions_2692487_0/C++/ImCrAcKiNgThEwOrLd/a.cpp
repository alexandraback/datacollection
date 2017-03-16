#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

int sz, n;
int a[100];

__int64 rec(__int64 cur_size, int idx)
{
	if (idx >= n)
		return 0;
	if (cur_size == 1)
		return n - idx;
	__int64 cur = cur_size;
	int cnt = 0;
	while (cur <= a[idx])
	{
		cur += cur - 1;
		++cnt;
	}
	return min(__int64(n - idx), rec(cur + a[idx], idx + 1) + cnt);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		cin >> sz >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a + n);
		cout << rec(sz, 0) << endl;
	}
}