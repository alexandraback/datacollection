#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010
int DP[MAXN],n;
bool visit[MAXN];

int main()
{
	int t;
	cin >> t;
	for(int test=1;test<=t;++test)
	{
		cin >> n;
		for(int i=0;i<=n;++i)
			visit[i] = false;
		for(int i=0;i<=n;++i)
			DP[i] = 0;
		queue<int> q;
		q.push(1);
		DP[1] = 1;
		visit[1] = true;
		while(!q.empty())
		{
			int v = q.front();
			if(v==n)
				break;
			q.pop();
			int x = v, y = 0;
			while(x)
			{
				y *= 10;
				y += (x%10);
				x /= 10;
			}
			if(!visit[v+1])
			{
				q.push(v+1);
				visit[v+1] = true;
				DP[v+1] = 1+DP[v];
			}
			if(y<=n && !visit[y])
			{
				q.push(y);
				visit[y] = true;
				DP[y] = 1+DP[v];
			}
		}
		cout << "Case #" << test << ": " << DP[n] << endl;
	}
	return 0;
}
