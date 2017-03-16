#define mset(a) memset(a,0,sizeof(a))

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

int level[2000];//0,1,2,3
int ans;
int n;
int a[2000],b[2000];
int tt;
set<long long>hash;
void dfs(int p,int done,int earn,int step)
{
	//if(tt>65)printf("%d %d %d %d\n",p,done,earn,step);
	long long c=0;
	if(done==n)
	{
		ans=min(ans,step);
		return;
	}
	for(int i=0;i<n;i++)
		c=c*10+level[i];
	if(hash.count(c)>0)return;
	hash.insert(c);
	for(int i=0;i<n;i++)
	{
		if(level[i]==0&&a[i]<=earn)
		{
			level[i]+=1;
			dfs(i,done,earn+1,step+1);
			level[i]-=1;
		}
		if(level[i]==0&&b[i]<=earn)
		{
			level[i]+=2;
			dfs(i,done+1,earn+2,step+1);
			level[i]-=2;
		}
		if(level[i]==1&&b[i]<=earn)
		{
			level[i]+=2;
			dfs(i,done+1,earn+1,step+1);
			level[i]-=2;
		}
	}

}

int main()
{
	int t;
	cin>>t;
	for(tt=1;tt<=t;tt++)
	{
		mset(level);
		cin>>n;
		ans=30000;
		hash.clear();
		for(int i=0;i<n;i++)
			cin>>a[i]>>b[i];
		for(int i=0;i<n;i++)
		{
			if(b[i]==0)
			{
				level[i]+=2;
				dfs(i,1,2,1);
				level[i]-=2;
			}
			if(a[i]==0)
			{
				level[i]+=1;
				dfs(i,0,1,1);
				level[i]-=1;
			}
		}
		printf("Case #%d: ",tt);
		if(ans>2000)
			printf("Too Bad\n");
		else printf("%d\n",ans);
	}
    return 0;
}
