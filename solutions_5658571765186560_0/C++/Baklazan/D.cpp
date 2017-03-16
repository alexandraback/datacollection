#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

#define inf 1023456789
#define linf 1023456789123456789ll
#define pii pair<int,int>
#define pipii pair<int, pii >
#define pll pair<long long,long long>
#define vint vector<int>
#define vvint vector<vint >
#define ll long long
#define pdd pair<double, double>

#define DEBUG
#ifdef DEBUG
#define db(x) cerr << #x << " = " << x << endl
#else
#define db(x)
#endif

int who_wins[4][4][4] = 
{
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{1,0,1,0},
		{0,0,0,0},
		{1,0,1,0},
		{0,0,0,0}
	},
	{
		{1,1,1,1},
		{1,1,0,1},
		{1,0,0,0},
		{1,1,0,1}
	},
	{
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,0},
		{1,1,0,0}
	}
};

int main()
{
	int t;
	scanf("%d",&t);
	for(int testcase=0; testcase<t; testcase++)
	{
		int x,r,c;
		scanf("%d %d %d",&x,&r,&c);
		printf("Case #%d: ",testcase+1);
		if(who_wins[x-1][r-1][c-1] == 1)printf("RICHARD\n");
		else printf("GABRIEL\n");
	}
	return 0;
}