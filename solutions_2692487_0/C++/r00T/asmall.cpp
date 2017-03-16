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

int n;
int arr[105];
		
int osmos(int i, int c)
{
	if(i == n)
		return 0;
	int x = c;
	int y = arr[i];
	int k = 0;
	if(x == 1)
		return (1+osmos(i+1,c));
	while(x<=y)
	{
		x = 2*x-1;
		k++;
	}
	return min(k+osmos(i+1,x+y), 1+osmos(i+1,c));
}
main()
{
	int tc;
	cin>>tc;
	for(int t = 1;t<=tc;t++)
	{
		int a;
		scanf("%d %d", &a, &n);
		for(int i = 0;i<n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+n);
		int x = osmos(0,a);
		printf("Case #%d: %d\n", t,x);
	}
}
