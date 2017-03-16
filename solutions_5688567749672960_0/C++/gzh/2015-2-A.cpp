#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>

using namespace std;
int n, test;
int dist[1000010];

int rev(int x)
{
	int ret = 0, last;
	while (x)
	{
		last = x % 10;
		ret = ret * 10 + last;
		x /= 10;
	}
	return ret;
}

int main()
{
	scanf("%d",&test);
	memset(dist, 127, sizeof dist);
	dist[1] = 1;
	for (int i = 1; i <= 1e6; ++ i)
	{
		dist[i+1] = min(dist[i+1], dist[i] + 1);
		int r = rev(i);
		dist[r] = min(dist[r], dist[i] + 1);
	}
	for (int T = 1; T <= test; ++ T)
	{
		printf("Case #%d: ", T);
		cin >> n;
		cout << dist[n] << endl;
	}
	return 0;
}