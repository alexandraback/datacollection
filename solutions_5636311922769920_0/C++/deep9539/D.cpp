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
int main()
{
	int T;
	scanf("%d",&T);
	int t = T;
//	T = 1;
	while(T--)
	{
		int K,C,S;
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d: ",t-T);
		if(S < K)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		for(int i = 0 ; i < K ; i++)
		{
			printf("%d%c",i+1,(i==K-1)?'\n':' ');
		}
	}
	return 0;
}
