#include<cstdio>
#include<map>
#include<vector>

using namespace std;
#define pii pair<int,int>
#define ppii pair<pii,int>

int main()
{
int i,j,k,t,T,a,b,c,l;

scanf("%d",&T);
map<pii,int> ab,bc,ac;
vector<ppii> ans;


for(t=1;t<=T;t++)
	{
	scanf("%d%d%d%d",&a,&b,&c,&l);
	ab.clear();bc.clear();ac.clear();	
	ans.clear();

	for(i=1;i<=a;i++)
		for(j=1;j<=b;j++)
			for(k=1;k<=c;k++)
			{
			if(ab.find(pii(i,j))!= ab.end() && ab[pii(i,j)]>=l)
				continue;
			if(ac.find(pii(i,k))!= ac.end() && ac[pii(i,k)]>=l)
				continue;
			if(bc.find(pii(j,k))!= bc.end() && bc[pii(j,k)]>=l)
				continue;
		
			if(ab.find(pii(i,j))!= ab.end())
				ab[pii(i,j)]++;
			else	ab[pii(i,j)]=1;

			if(ac.find(pii(i,k))!= ac.end())
				ac[pii(i,k)]++;
			else	ac[pii(i,k)]=1;

			if(bc.find(pii(j,k))!= bc.end())
				bc[pii(j,k)]++;
			else	bc[pii(j,k)]=1;

			ans.push_back(ppii(pii(i,j),k));
			}

	
	printf("Case #%d: %lu\n",t,ans.size());
	for(i=0;i<ans.size();i++)
		{
		printf("%d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second);
		}
	}

return 0;
}
