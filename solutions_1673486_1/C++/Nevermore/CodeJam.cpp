#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <ctime>
using namespace std;
#define min(a,b) ((a)<(b) ? (a) :(b))

#define N 100005
double pro[N],tot[N];

int main()
{
	int i,a,b,t,times = 1;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		for (i = 1, tot[0] = 1.0; i <= a; i++)	
		{
			scanf("%lf",&pro[i]); 
			tot[i] = tot[i-1]*pro[i];
		}
		double ans = b + 2.0 ;
		ans = min(ans, tot[a]*(b-a+1)+(1.0-tot[a])*(2*b-a+2.0));
		for (i = 1; i < a; i++)
		{
			ans = min(ans,tot[a-i]*(2*i+1.0+b-a)+(1-tot[a-i])*(2.0*i+2.0+2.0*b-a));
		}
		printf("Case #%d: %.6lf\n",times++, ans+(1e-8));
	}
	return 0;
}




/*
struct st
{
	int lvl1;
	int lvl2;
}temp;

int cmpa(const st &a, const st &b)
{
	return a.lvl1 < b.lvl1;
}

int cmpb(const st &a, const st &b)
{
	return a.lvl2 < b.lvl2;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int vis1[1005];
	int vis2[1005];
	int t,j,n,i;
	scanf("%d",&t);
	while(t--)
	{
		vector<st> elem;
		scanf("%d",&n);
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		for(i = 0; i < n; i++)
		{
			scanf("%d %d",&temp.lvl1,&temp.lvl2);
			elem.push_back(temp);
		}
		int flag = 1;
		int ans = 0;
		int ok = 0;
		int cur = 0;
		while(!ok)
		{
			sort(elem.begin(),elem.end(),cmpb);
			for(i = 0; i < elem.size(); i++)
			{
				if(elem[i].lvl2 <= cur && vis1[i] == 0 && vis2[i] == 0)
				{
					ans += 1;
					cur += 2;
					vis2[i] = 1;
					break;
				}
				else if(elem[i].lvl2 <= cur && vis1[i] == 1 && vis2[i] == 0)
				{
					ans += 1;
					cur += 1;
					vis2[i] = 1;
					break;
				}
			}
			cout << i << " " << elem.size() << endl;
			if(i == elem.size())	
			{
				sort(elem.begin(),elem.end(),cmpa);
				for(j = 0; j < elem.size(); j++)
				{
					if(elem[j].lvl1 <= cur && vis1[j] == 0)
					{
						ans += 1;
						cur += 1;
						vis1[j] = 1;
						break;
					}
				}
				if(j == elem.size())
				{
					flag = 0;
					ok = 1;
				}
			}
			for(i = 0; i < n; i++)
			{
				if(!vis2[i])
				{
					ok = 0;
					break;
				}
			}
		}
		if(flag)
		{
			printf("%d\n",ans);
		}
		else
		{
			printf("Too Bad");
		}
	}
	



	return 0;
}*/