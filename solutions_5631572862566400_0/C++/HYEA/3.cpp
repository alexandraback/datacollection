#include<algorithm>
#include<cstdio>
using namespace std;
int tmain()
{
	int N;
	int bff[10];
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		scanf("%d",bff+i);
		bff[i]--;
	}
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	int ans = 2;
	do
	{
		for(int sz=3; sz<=N; sz++)
		{
			bool flag = true;
			for(int i=0; i<sz; i++)
				if(bff[arr[i]] != arr[(i+sz-1)%sz] && bff[arr[i]] != arr[(i+1)%sz])
				{
					flag=false;
					break;
				}
			
			if(flag)
				if(ans<sz)
					ans = sz;
		}
	}while(next_permutation(arr,arr+N));
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++)
		printf("Case #%d: %d\n",i,tmain());

}
