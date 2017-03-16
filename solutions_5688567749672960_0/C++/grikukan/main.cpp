#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<queue>
using namespace std;
long long dp[1000007];
int digs[107], digsz = 0;
queue<int>q;
int fact(int n)
{
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}
void relax(int pos, int val)
{
	if (dp[pos] > val)
	{
		dp[pos] = val;
		q.push(pos);
	}

}
const int MAX = 1000000;
int main()
{
	for (int i = 2; i <= 1000000; i++)
	{
		dp[i] = 100000007;
	}
	dp[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == 3200)
		{
			cerr << 3200;
		}
		if (cur + 1 <= MAX)
		{
			relax(cur + 1, dp[cur] + 1);
		}
		int tmp = cur;
		digsz = 0;
		while (tmp > 0)
		{
			digs[digsz + 1] = tmp % 10;
			digsz++;
			tmp /= 10;
		}		
		int q = 1;
		while (digs[q] == 0) q++;
		swap(digs[1], digs[q]);
		int nxt = 0;
		for (int j = 1; j <= digsz; j++)
		{
			nxt = nxt * 10 + digs[j];
		}
		if (nxt <= MAX)
		{
			relax(nxt, dp[cur] + 1);
		}
	}
	cerr << "Calced" << endl;
	int n;
	cin >> n;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cout << "Case #" << i << ": " << dp[x] << endl;
	}
}
