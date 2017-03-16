#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
using namespace std;

typedef long long int L;
typedef unsigned long long int U;


bool pal(int n)
{
	int r = 0,c = n;
	while(c)
	{
		r = r*10 + c%10;
		c /= 10;
	}
	if(r == n)
		return 1;
	else
		return 0;
}
main()
{
	int arr[1004];
	memset(arr, 0, sizeof(arr));
	for(int i = 1;i<32;i++)
	{
		if(pal(i))
		{
			if(pal(i*i))
			{
				for(int j = i*i;j<=1000;j++)
					arr[j]++;
			}
		}
	}
	int tc;
	scanf("%d", &tc);
	for(int t =1;t<=tc;t++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n",t,arr[b]-arr[a-1]);
	}
}
