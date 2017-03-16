#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

int n,num[25];
map< int, pair<int,int> > mp;
int done;

void bktk(int lev,int sum,int mask)
{
	if(done)
		return;
	if(lev==n)
	{
		if(mp.find(sum)==mp.end())
			mp[sum] = make_pair(1,mask);
		else
		{
			int i, v = mp[sum].second;
			int printed = 0;
			for(i=0;i<n;i++)
				if(v & 1<<i)
				{
					if(printed) printf(" %d",num[i]);
					else printf("%d",num[i]);
					printed = 1;
				}
			printf("\n");
			v = mask;
			printed = 0;
			for(i=0;i<n;i++)
				if(v & 1<<i)
				{
					if(printed) printf(" %d",num[i]);
					else printf("%d",num[i]);
					printed = 1;
				}
			printf("\n");

			done = 1;
		}
		return;
	}
	bktk(lev+1,sum,mask);
	bktk(lev+1,sum+num[lev],mask | (1<<(lev)));
}

int main()
{
	int t,i,cs;
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		mp.clear();
		done = 0;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		printf("Case #%d:\n",cs+1);
		bktk(0,0,0);
		if(!done)
			printf("Impossible\n");
	}
	return 0;
}