#include<cstdio>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;
int mark[3000];
vector<int> ans;
int main()
{
int ntc,N,t; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		for(int i=0;i<3000;i++) mark[i] = 0;
		printf("Case #%d: ",tc);
		scanf("%d",&N);
		for(int i=0;i<2*N - 1;i++)
		for(int j=0;j<N;j++)
		{
			scanf("%d",&t);
			mark[t] ++;
		}
		
		ans.clear();
		for(int i=0;i<3000;i++)
		{
			if(mark[i]&1) ans.push_back(i);
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]); printf("\n");
	}	
}
