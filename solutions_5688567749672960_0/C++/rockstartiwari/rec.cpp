#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int arr[1000006];
int min(int a,int b)
{
	return a>b?b:a;
}
int main()
{
	int t;
	freopen("C:\\Users\\Gaurav\\Desktop\\alk.in","r",stdin);
    freopen("C:\\Users\\Gaurav\\Desktop\\output.txt","w",stdout);
	int ca=0;
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		long long int n,i;
		scanf("%lld",&n);
		int ans=1;
		for(i=0;i<=n;i++)
			arr[i]=10000000;
		arr[1]=1;
		for(i=1;i<=n;i++)
		{
			arr[i+1]=min(arr[i+1],arr[i]+1);
			long long int cur=0,nn=i;
			while(nn!=0)
			{
				cur=cur*10+nn%10;
				nn=nn/10;
			}
			arr[cur]=min(arr[cur],arr[i]+1);
		}
		printf("Case #%d: %d\n",ca,arr[n]);
	}
	return 0;
}