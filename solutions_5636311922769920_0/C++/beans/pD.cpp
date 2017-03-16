#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    freopen("inD","r",stdin);
    freopen("outD","w",stdout);
	int K,C,S,T,kase=0;
    scanf("%d",&T);
    while(T--)
	{
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d:",++kase);
	    vector< LL > ans;
        int cur=0;
	    for(int i=0;i<S;i++)
	    {
		    LL ask=0;
		    for(int p=1;p<=C;p++,cur++) ask=ask*K + (cur%K);
		    ans.push_back(ask);
	    }

		if(cur >= K) 
		{
			sort(ans.begin(),ans.end());
            ans.resize(unique(ans.begin(),ans.end())-ans.begin());
			for(int i=0;i<ans.size();i++) printf(" %lld",ans[i]+1);puts("");
		}
		else printf(" IMPOSSIBLE\n");
	}
}
