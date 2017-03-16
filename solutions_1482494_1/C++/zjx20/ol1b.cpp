#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;

int a[2000];
int b[2000];
bool use[2000];
bool lev1[2000];

bool cmpppp (const pair<int,int>& aa, const pair<int,int>& bb)
{
	if(aa.first!= bb.first) return aa.first<bb.first;
	return b[aa.second] > b[bb.second];
}

struct cmp
{
	bool operator() (const pair<int,int>& aa, const pair<int,int>& bb) const
	{
		return !cmpppp(aa,bb);
	}
};

int main()
{
	freopen("B-large.in", "r", stdin);
	//freopen("ol1b_input.txt", "r", stdin);
	freopen("ol1b_output.txt", "w", stdout);

	int t;
	int i;
	scanf("%d",&t);
	int ca=0;
	while(t--)
	{
		printf("Case #%d: ", ++ca);
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i],&b[i]);
		memset(use, 0, sizeof(use));
		memset(lev1, 0, sizeof(lev1));

		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> un;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;

		vector<pair<int,int>> st1;

		for(i=0;i<n;i++)
			un.push(make_pair(b[i], i));

		for(i=0;i<n;i++)
			st1.push_back(make_pair(a[i],i));
		sort(st1.begin(), st1.end(), cmpppp);

		int cc = 0;
		int now = 0;
		while(un.size() > 0 || p.size() > 0)
		{
			bool flag = false;

			if(p.size() > 0)
			{
				pair<int,int> x = p.top();
				if(x.first <= now)
				{
					flag = true;
					cc++;
					now+=1;
					use[x.second] = true;
					p.pop();
					continue;
				}
			}

			if(un.size() > 0)
			{
				pair<int,int> x = un.top();
				if(lev1[x.second])
				{
					un.pop();
					continue;
				}
				if(x.first <= now)
				{
					flag = true;
					cc++;
					now += 2;
					use[x.second]=true;
					un.pop();
					continue;
				}
			}

				auto be = st1.end();
				for(auto it=st1.begin();it!=st1.end();++it)
				{
					if(use[it->second])
					{
						//st1.erase(it);
						continue;
					}
					if(it->first <= now)
					{
						if(be == st1.end() || b[be->second] < b[it->second]) be = it;
						continue;
					}
					else
					{
						break;
					}
				}
				if(be != st1.end())
				{
					flag = true;
					cc++;
					now += 1;
					lev1[be->second]=true;
					p.push(make_pair(b[be->second], be->second));
					st1.erase(be);
				}
			if(!flag) break;
		}

		if(un.size()>0 || p.size()>0) printf("Too Bad\n");
		else printf("%d\n", cc);
	}
	return 0;
}