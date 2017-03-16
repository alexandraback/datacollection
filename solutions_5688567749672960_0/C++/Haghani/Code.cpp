#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1000005;
int d[MAX], q[MAX];
int rev(int num)
{
	int ans = 0;
	while (num)
	{
		ans = ans * 10 + num % 10;
		num /= 10;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(d, 63, sizeof(d));
	d[1] = 1;
	int h = 0, t = 0;
	q[t++] = 1;
	while (h < t)
	{
		int v = q[h++];
		if (rev(v) < MAX && d[rev(v)] > d[v] + 1)
		{
			d[rev(v)] = d[v] + 1;
			q[t++] = rev(v);
		}
		if (v + 1 < MAX && d[v + 1] > d[v] + 1)
		{
			d[v + 1] = d[v] + 1;
			q[t++] = v + 1;
		}
	}
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		int x;
		cin >> x;
		cout << "Case #" << _ << ": " << d[x] << endl;
	}
	return 0;
}
