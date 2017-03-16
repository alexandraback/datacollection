#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
using namespace std;

typedef long long LL;
typedef double ld;

const int NUM=5;

char g[NUM][NUM];
int get(char a)
{
	if(a=='O')
		return 0;
	if(a=='X')
		return 1;
	if(a=='T')
		return 2;
	return 3;
}

int Test=0;

int Main()
{
	++Test;
	int i,j,k;
	REP2(i,0,4)
		scanf("%s",g[i]);
	REP2(k,0,2)
		REP2(i,0,4)
		{
			int num[4]={0,0,0};
			REP2(j,0,4)
				++num[get(k?g[i][j]:g[j][i])];
			if(num[0]+num[1]+num[2]!=4)
				continue;
			if(num[0]>=3 && num[1]==0)
			{
				printf("Case #%d: O won\n",Test);
				return 0;
			}
			if(num[1]>=3 && num[0]==0)
			{
				printf("Case #%d: X won\n",Test);
				return 0;
			}
		}
	REP2(k,0,2)
	{
		int num[4]={0,0,0};
		REP2(i,0,4)
			++num[get(k?g[i][i]:g[i][4-i-1])];
		if(num[0]+num[1]+num[2]!=4)
			continue;
		if(num[0]>=3 && num[1]==0)
		{
				printf("Case #%d: O won\n",Test);
			return 0;
		}
		if(num[1]>=3 && num[0]==0)
		{
				printf("Case #%d: X won\n",Test);
			return 0;
		}
	}
	REP2(i,0,4)
		REP2(j,0,4)
			if(g[i][j]=='.')
			{
				printf("Case #%d: Game has not completed\n",Test);
				return 0;
			}
	printf("Case #%d: Draw\n",Test);
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--)
		Main();
	return 0;
}
