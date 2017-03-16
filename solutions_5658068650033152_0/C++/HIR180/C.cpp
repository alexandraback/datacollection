#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	
	for(int test = 1;test<=t;test++)
	{
		printf("Case #%d: ",test);
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		int res = 1000;
		int kk = (n-2)*(m-2);
		pair<int,int> p[25];
		int id=0;
		if(n<=2 || m<=2) goto nxt;
		for(int i=2;i<n;i++)
		{
			for(int j=2;j<m;j++)
			{
				p[id++] = make_pair(i,j);
			}
		}
		for(int i=0;i<(1<<kk);i++)
		{
			int dx[4]={0,1,0,-1};
			int dy[4]={1,0,-1,0};
			set<pair<int,int> >se;
			for(int j=0;j<kk;j++)
			{
				if(((i>>j)&1))
				{
					se.insert(p[j]);
					for(int k=0;k<4;k++)
					{
						if(1<=p[j].first+dx[k] && p[j].first+dx[k]<=n)
						{
							if(1<=p[j].second+dy[k] && p[j].second+dy[k]<=m)
							{
								se.insert(make_pair(p[j].first+dx[k],p[j].second+dy[k]));
							}
						}
					}
				}
			}
			if(se.size()>=k) res = min(res,(int)se.size()-(__builtin_popcount(i)));
		}
		nxt:;
		cout << min(k,res) << endl;
	}
}