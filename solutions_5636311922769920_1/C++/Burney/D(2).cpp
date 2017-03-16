#include<cstdio>
#include<cassert>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
vector<LL>ANS;
int K,C,S;
bool Solve()
{
	ANS.clear();
	int cur=0;
	for(int i=0;i<S;i++)
	{
		LL ans=0LL;
		for(int p=1;p<=C;p++)
		{
			ans=ans*K+(cur++)%K;
		}
		ANS.push_back(ans+1LL);
	}
	return cur>=K;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int testcount;scanf("%d",&testcount);
	while(testcount--)
	{
		scanf("%d%d%d",&K,&C,&S);
		static int kase=0;
		printf("Case #%d:",++kase);
		if(!Solve())puts(" IMPOSSIBLE");
		else
		{
			sort(ANS.begin(),ANS.end()),ANS.resize(unique(ANS.begin(),ANS.end())-ANS.begin());
			for(int i=0;i<(int)ANS.size();i++)printf(" %lld",ANS[i]);puts("");
		}
	}
	return 0;
}
