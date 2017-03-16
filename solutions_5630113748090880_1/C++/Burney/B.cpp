#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;
int N,CNT[2501];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int testcount;scanf("%d",&testcount);
	while(testcount--)
	{
		scanf("%d",&N);
		for(int i=1;i<=2500;i++)CNT[i]=0;
		for(int i=0;i<2*N-1;i++)for(int j=0,h;j<N;j++)scanf("%d",&h),CNT[h]++;
		vector<int>ans;
		for(int i=1;i<=2500;i++)if(CNT[i]&1)ans.push_back(i);
		assert((int)ans.size()==N);
		static int kase=0;
		printf("Case #%d:",++kase);
		for(int i=0;i<N;i++)printf(" %d",ans[i]);puts("");
	}
	return 0;
}
