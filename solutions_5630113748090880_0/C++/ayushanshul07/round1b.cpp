#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int T,z = 1;
	scanf("%d",&T);
	getchar();
	while(T--)
	{	
		int N,arr[2550][2]= {0},tmp = 0;
		scanf("%d",&N);
		int len = 2*N - 1;
		for(int i = 1 ; i <= len ; ++i)
		{
			for(int j = 1; j <= N; ++j)
			{
				scanf("%d",&tmp);
				arr[tmp][1] = 1;
				arr[tmp][0]++;	
			}
		}

		printf("Case #%d: ",z);
		for(int i = 1; i <= 2500; ++i)
		{
			if(arr[i][1] == 1 && arr[i][0]%2 == 1)
				printf("%d ",i);
		}
		printf("\n");
		z++;
	}

	return 0;
}