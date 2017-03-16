#include<cstdio>
#include<cstring>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

bool com(pair<int,int> a,pair<int,int> b)
{
	if(a.first==b.first)
		return a.second>=b.second;
	return a.first<=b.first;
}

int main()
{
	vector< pair<int,int> > v;
	int t,a,b,ans,n;
	int one[2020],two[2020];
	scanf("%d",&t);

	for(int cases=1; cases<=t; cases++)
	{
		memset(one,0,sizeof one);
		memset(two,0,sizeof two);
		v.clear();
		
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&a,&b);
			v.push_back(make_pair(a,b));
		}
		sort(v.begin(), v.end(),com);

		int over = 0,star = 0,step = 0;
		while(1)
		{	
			while(1)
			{
				int wh = 0;
				for(int i=0; i<n; i++)
				{
					if(v[i].second <= star && two[i]==0)
					{
						if(one[i] == 0)
							star += 2;
						else
							star++;
						one[i] = two[i] = 1;
						step++;
						wh = 1;
						//printf("### %d %d\n",star,step);
						break;

					}
				}
				if(wh == 0)
					break;
			}
			int check = 0;
			for(int i=0; i<n; i++)
			{
				if(two[i] == 0)
				{
					check = 1;
					break;
				}
			}
			if(check == 0)
				break;
			int flag = 0;
			for(int i=0; i<n; i++)
			{
				if(v[i].first <= star && one[i] == 0)
				{
					flag = 1;
					star++;
					one[i] = 1;
					step++;
				//	printf("### %d %d\n",star,step);
					break;
				}
			}
			if(flag == 0)
			{
				over = 1;
				break;
			}
	//		printf("### %d %d\n",star,step);

		}

		if(over == 0)
			printf("Case #%d: %d\n",cases,step);
		else
			printf("Case #%d: Too Bad\n",cases);
	}
	return 0;
}
