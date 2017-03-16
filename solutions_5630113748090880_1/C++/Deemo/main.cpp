#include<stdio.h>
#include<string.h>
#include<math.h>
#include<list>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int T,N;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&N);
		printf("Case #%d: ",i+1);
		int arr[3000]={0};
		int temp;
		for(int j=0;j<N*(2*N-1);j++)
		{
			scanf("%d", &temp);
			arr[temp]++;
		}
		for(int j=0;j<2501;j++)
		{
			if(arr[j]%2!=0)
				printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}