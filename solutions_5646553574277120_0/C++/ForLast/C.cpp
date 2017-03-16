#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include <queue>
#include<string>
#include <sstream>
#include<list>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;


int arr[10];
bool trac[35];
bool used[10];

void findCobination(int val, int x, int limit, int v)
{
	if(val > v || x > limit) return;
	trac[val] = true;
	for(int i = 0; i<limit; i++) {
		if(!used[i]) {
			used[i] = true;
			findCobination(val+arr[i], x+1, limit, v);
			used[i] = false;
		}
	}
}

int main()
{
	
	
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	
	int T;
	scanf("%d",&T);
	
	for(int t = 1; t<=T; t++)
	{
		int c,d,v;
		scanf("%d %d %d",&c, &d, &v);
		memset(trac, false, sizeof(trac));
		memset(used, false, sizeof(used));
		for(int i = 0; i<d; i++) 
		{
			scanf("%d",&arr[i]);
		}
		
		for(int i = 0; i<d; i++)
		{
			used[i] = true;
			findCobination(arr[i], 1, d, v);
			used[i] = false;
		}

		int res = 0;
		for(int i = 1; i<= v; i++) {
			if(!trac[i]) res++;
		}
		printf("Case #%d: %d\n",t,res);
	}
	
	return 0;
}
