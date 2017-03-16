/*******************************************************************************
IF YOU ARE LOOKING THIS YOU ARE RIGHT WAY
*******************************************************************************/
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 100005
typedef pair<int,int> p;
typedef pair<int,p> pii;
#define fi first
#define se second
#define pb push_back
#define s(a) scanf("%d",&a);
#define mem(a) memset(a,0,sizeof(0))
vector<int> v;

void dofor(int A[],int t)
{
	while(t > 0)
	{
		A[t%10] = 1;
		t /= 10;
	}
}

int isvalid(int A[])
{
	for(int i = 0 ; i < 10 ; i++)
		if(A[i] == 0)
			return 0;
	return 1;
}

void solve(long long N)
{
	int A[10];
	memset(A,0,sizeof(A));
	if(N==0)
	{
		printf("INSOMNIA\n");
		return;
	}
	for(int i = 1 ; i < 1000000 ; i++)
	{
		dofor(A,i*N);
		if(isvalid(A))
		{
			printf("%lld\n",i*N);;
			return;
		}
	}
	printf("INSOMNIA\n");
}

int main()
{
	int T;
	scanf("%d",&T);
//	T = 1;
	int t = T;
	while(T--)
	{
		long long N;
		scanf("%lld",&N);
		printf("Case #%d: ",t-T);
		solve(N);
	}
	return 0;
}
