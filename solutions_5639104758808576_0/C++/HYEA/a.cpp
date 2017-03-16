#include<cstdio>
int tmain()
{
	int arr[1001];
	int N;
	scanf("%d",&N);
	for(int i=0;i<=N;i++) scanf("%1d",arr+i);
	int cnt=0;
	int ans=0;
	for(int i=0;i<=N;i++)
	{
		if(cnt<i)
		{
			cnt++;
			ans++;
		}
		cnt+=arr[i];
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