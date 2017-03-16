#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN=1000+2;

vector<int> a[MAXN];
int p[MAXN];
int m[MAXN];

int best = 0;


int dfs(int n, int h = 1)
{
	m[n] = 1;
	int max = 1;
	for(int i=0;i<a[n].size();i++)
	{
		if(m[a[n][i]]){
			if(h>best)
				best = h;
			return 0;
		}
		else
		{
			int ret = dfs(a[n][i], h+1);
			//if(ret==-1)
			//	return -1;
			if(ret+1>max)
				max = ret+1;
		}
	}
	m[n] = 0;
	return max;
}




int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;

		int d[n+1];
		
		best = 0;
		for(int j=1;j<=n;j++) {
			a[j] = vector<int>();
			p[j] = 0;
		}

		for(int j=0;j<n;j++) {
			int x;
			cin >> x;
			p[j+1] = x;
			a[x].push_back(j+1);
		}

		for(int j=1;j<=n;j++) {
			d[j] = dfs(j);
			
		}
		int cost = 0;
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(p[k]==j && p[j]==k)
					cost+=d[j]+d[k];
		if(cost>best)
			best = cost;
		cout << "Case #" << i+1 << ": ";
		cout << best << endl;
	}

	return 0;
}