#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 1005
#define MED 502
#define DAY 205

using namespace std;
typedef long long int ll;

struct at
{
	int t;
	int s,e;
	ll h;
};
bool comp(const at&l,const at&r)
{
	return l.t<r.t;
}
at ma(int t,int s,int e,int h)
{
	at ret;
	ret.t=t;ret.s=s;ret.e=e;ret.h=h;
	return ret;
}
ll wall[SIZE];
vector <at> att[DAY];

void see()
{
	for(int j=MED;j<MED+10;j++) printf("%lld ",wall[j]);
	printf("\n");
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		memset(wall,0,sizeof(wall));
		for(int i=0;i<DAY;i++) att[i].clear();
		int n;
		scanf("%d",&n);
		vector <at> vec;
		vector <int> vx;
		for(int i=0;i<n;i++)
		{
			int d;
			scanf("%d",&d);
			int hm;
			scanf("%d",&hm);
			int s,e;
			scanf("%d %d",&s,&e);s+=MED;e+=MED;
			ll h;
			scanf("%lld",&h);
			int pd,pp,ph;
			scanf("%d %d %d",&pd,&pp,&ph);
			for(int j=0;j<hm;j++)
			{
				vx.push_back(d);
				vec.push_back(ma(d,s,e,h));
				d+=pd;
				s+=pp;e+=pp;
				h+=ph;
			}
		}
		sort(vec.begin(),vec.end(),comp);
		sort(vx.begin(),vx.end());
		vx.erase(unique(vx.begin(),vx.end()),vx.end());
		for(int i=0;i<vec.size();i++)
		{
			at a=vec[i];
			a.t=lower_bound(vx.begin(),vx.end(),a.t)-vx.begin();
			att[a.t].push_back(a);
		}
		int ret=0;
		for(int i=0;i<DAY;i++)
		{
			for(int j=0;j<att[i].size();j++)
			{
				at a=att[i][j];
				for(int k=a.s;k<a.e;k++)
				{
					if(wall[k]<a.h)
					{
						ret++;
						break;
					}
				}
			}
			for(int j=0;j<att[i].size();j++)
			{
				at a=att[i][j];
				for(int k=a.s;k<a.e;k++) wall[k]=max(wall[k],a.h);
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
