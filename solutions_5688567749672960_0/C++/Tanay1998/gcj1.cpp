#include <iostream>
#include <queue>

#define MAX 111111
using namespace std;

int DP[MAX];

int rev(int x)
{
	int y = 0;
	while (x > 0)
	{
		y = y * 10 + (x % 10);
		x /= 10;
	}
	return y;
}

int main()
{
	freopen("test.in", "r", stdin);
	cout << "yey";
	DP[1] = 1;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty())
	{
		int x = Q.front();
		cout << x << ' ';
		Q.pop();
		if (DP[x + 1] == 0 and x + 1 < MAX)
		{
			DP[x + 1] = DP[x] + 1;
			Q.push(x + 1);
		}
		if (DP[rev(x)] == 0 and rev(x) < MAX)
		{
			DP[rev(x)] = DP[x] + 1;
			Q.push(rev(x));
		}
	}
	cout << DP[6001];
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		long long N;
		cin >> N;	
		printf("Case #%d: %d", t, DP[N]);
	}
}