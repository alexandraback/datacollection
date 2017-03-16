#include <stdio.h>
#include <set>
#include <string>
#include <map>
using namespace std;

set<pair<int,int>>le2;
map<pair<int,int>,int>  le1;

int a[1010],b[1010];
bool used1[1010],used2[1010];
int n;

int solve()
{
	int cnt = 0, step = 0, tolnum = 0;
	memset(used1,0,sizeof(used1));
	memset(used2,0,sizeof(used2));
	set<pair<int,int>>::iterator it;
	int need;
	while(1)
	{
		it = le2.begin();
		if((*it).first<=tolnum) 
		{
			step++; tolnum+=2;
			cnt++;
			if(used1[(*it).second])
				tolnum--;
			le2.erase(it);
		}
		else
		{
			need = (*it).first;
		    while(need > tolnum)
			{
				map<pair<int,int>,int>::iterator jt = le1.begin();
				if(le1.size()==0)
				{
					return step = -1;
				}
				if(used2[(*jt).second])
				{
					 le1.erase(jt);
                     continue;
				}
                if((*jt).first.first>tolnum)
				{
					return step = -1;
				}
				tolnum++;
				step++;
				used1[(*jt).second] = true;
				le1.erase(jt);
			}
		}
		if(cnt==n)
		{
			return step;
		}
	}
	return -1;
}

int main()
{
	freopen("B-small-attempt3.in","r",stdin);
	freopen("B-small-attempt3.out","w",stdout);
	int ct,caset = 1;
	scanf("%d",&ct);

	while(ct--)
	{
		printf("Case #%d: ",caset++);
		scanf("%d",&n);
        int i;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i],&b[i]);
		le1.clear(); le2.clear();
		for(i=0;i<n;i++)
			le1.insert(make_pair(make_pair(a[i],-b[i]),i)) , le2.insert(make_pair(b[i],i));
		int step = solve();
		if(step==-1)
			printf("Too Bad\n");
		else
			printf("%d\n",step);
	}
	return 0;
}