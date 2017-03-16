#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#define SET(p)	 		memset(p,-1,sizeof(p))
#define CLR(p) 			memset(p,0,sizeof(p))
#define LL 				long long int
#define ULL		 		unsigned long long int
#define S(n)			scanf("%d",&n)
#define Sl(n)			scanf("%lld",&n)
#define Sf(n)			scanf("%lf",&n)
#define Ss(n)			scanf("%s",n)
#define INF				(int)1e9
#define LINF			(long long)1e18
#define EPS				1e-9
#define FOR(i,a,b)		for(int i=a;i<b;i++)
#define REP(i,n)		FOR(i,0,n)
using namespace std;
char s[10][10];
bool check(char c)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(s[i][j]!='T'&&s[i][j]!=c)
				break;
		}
		if(j==4)
			return 1;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(s[j][i]!='T'&&s[j][i]!=c)
				break;
		}
		if(j==4)
			return 1;
	}
	for(i=0;i<4;i++)
	{
		if(s[i][i]!='T'&&s[i][i]!=c)
			break;
	}
	if(i==4)
		return 1;
	for(i=0,j=3;i<4;i++,j--)
	{
		if(s[i][j]!='T'&&s[i][j]!=c)
			break;
	}
	if(i==4)
		return 1;
	
	return 0;
}
bool check2()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(s[i][j]=='.')
				return 1;
		}
	}
	return 0;
}
int main()
{
	int t,i,j,k,n,m;
	#ifndef ONLINE_JUDGE
	freopen("example.txt","r",stdin);
	freopen("op.txt","w",stdout);
	#endif
	S(t);
	int zz=0;
	while(t--)
	{
		zz++;
		for(i=0;i<4;i++)
			Ss(&s[i][0]);
		printf("Case #%d: ",zz);
		if(check('X'))
			printf("X won\n");
		else if(check('O'))
			printf("O won\n");
		else if(check2())
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	return 0;
}
