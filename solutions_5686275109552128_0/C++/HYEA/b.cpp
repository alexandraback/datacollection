#include<cstdio>
#include<algorithm>
#define MAXN 2010
using namespace std;
int tmain()
{
	int arr[MAXN];
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int t;
		scanf("%d",arr+i);
	}
	int ans=MAXN*MAXN;
	for(int i=1;i<=MAXN;i++)
	{
		int t=i;
		for(int j=0;j<N;j++)
			t+=(arr[j]-1)/i;
		ans=min(ans,t);
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		printf("Case #%d: %d\n",i,tmain());
	return 0;
}