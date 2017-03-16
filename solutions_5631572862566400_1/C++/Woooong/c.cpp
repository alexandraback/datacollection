#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int bff[1001],check[1001],party[1001];
	int t,T,n,i,j,cnt,max,hap,maxi,maxii,cur;
	vector<int> v[1001];
	queue<int> q;

	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&bff[i]);
			check[i]=party[i]=0;
			v[bff[i]].push_back(i);
		}

		max=0;
		for(i=1;i<=n;i++)
		{
			if(party[i])
				continue;
			cur=i;
			cnt=1;
			while(!party[cur])
			{
				party[cur]=i;
				check[cur]=cnt++;
				cur=bff[cur];
			}
			if(party[cur]==i)
			{
				cnt = cnt-check[cur];
				if(max<cnt)
					max=cnt;
			}
		}

		hap=0;
		for(i=1;i<=n;i++)
			if(bff[bff[i]]==i && bff[i]>i)
			{
				for(j=1;j<=n;j++)
					check[j]=0;
				check[i]=maxii=1;
				for(j=0;j<v[i].size();j++)
					if(v[i][j]!=bff[i])
						q.push(v[i][j]);
				while(!q.empty())
				{
					cur=q.front();
					q.pop();
					check[cur]=check[bff[cur]]+1;
					if(check[cur]>maxii)
						maxii=check[cur];
					for(j=0;j<v[cur].size();j++)
						q.push(v[cur][j]);
				}

				for(j=1;j<=n;j++)
					check[j]=0;
				check[bff[i]]=maxi=1;
				for(j=0;j<v[bff[i]].size();j++)
					if(v[bff[i]][j]!=i)
						q.push(v[bff[i]][j]);
				while(!q.empty())
				{
					cur=q.front();
					q.pop();
					check[cur]=check[bff[cur]]+1;
					if(check[cur]>maxi)
						maxi=check[cur];
					for(j=0;j<v[cur].size();j++)
						q.push(v[cur][j]);
				}
				hap+=maxii+maxi;
			}
		if(hap>max)
			max=hap;

		printf("Case #%d: %d\n",t,max);
		for(i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}
