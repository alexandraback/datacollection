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

char S[101];

int main()
{
	int T;
	scanf("%d",&T);
//	T = 1;
	int t = T;
	while(T--)
	{
		scanf("\n");
		gets(S);
		printf("Case #%d: ",t-T);
		int len = strlen(S) - 1;
		while(len > -1 && S[len]=='+')
			len--;
		if(len == -1)
		{
			printf("0\n");
			continue;
		}
		int cnt = 1;
		
		for(int i = 1 ; i <= len ; i++)
		{
//			printf("i : %c %c\n",S[i],S[i-1]);
			if(S[i] != S[i-1])
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
