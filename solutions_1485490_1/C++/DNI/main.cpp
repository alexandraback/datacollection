#include<iostream>
#include<vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>
#include <set>
#include <algorithm>

using namespace std;

const int n = 200;
const int m = 200;


long long int din[n][m];

long long int A[n];
long long int a[n];
long long int B[n];
long long int b[n];
long long int func(int aPos, int bPos)
{
	if(aPos < 0 || bPos < 0)
	{
		return 0; 
	}
	if(din[aPos][bPos] == -1)
	{
		long long int res = 0, t = 0;
		if(A[aPos] == B[bPos])
		{
			t = min(a[aPos], b[bPos]);
		}
		if(t != 0)
		{
			a[aPos] -= t;
			b[bPos] -= t;
			res = max(res, func(aPos, bPos - 1));
			res = max(res, func(aPos - 1, bPos));
			res += t;
			a[aPos] += t;
			b[bPos] += t;
		}
		else
		{
			res = max(res, func(aPos - 1, bPos));
			res = max(res, func(aPos, bPos - 1));
		}
	




		din[aPos][bPos] = res;
	}
	
	return din[aPos][bPos];
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; test++)
	{

		memset(din, -1, m*n*sizeof(long long int));
		memset(A, 0, n*sizeof(long long int));
		memset(a, 0, n*sizeof(long long int));
		memset(B, 0, m*sizeof(long long int));
		memset(b, 0, m*sizeof(long long int));
		int aPos, bPos;
		scanf("%d%d", &aPos, &bPos);
		for(int i =0 ;i <aPos;i++)
		{
			scanf("%lld%lld", a+i, A+i);
		}
		for(int i =0 ;i <bPos;i++)
		{
			scanf("%lld%lld", b+i, B+i);
		}
	//	for(int i = 0; i < aPos; i++)
		//	for(int j =0 ; j < bPos ;j++)
		//		func(i,j);
		printf("Case #%d: %lld", test+1, func(aPos-1, bPos-1));
		if(test != t-1)
			printf("\n");
	}
	return 0;
}