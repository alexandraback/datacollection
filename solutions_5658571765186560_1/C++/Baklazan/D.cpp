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

int main()
{
	int t;
	scanf("%d",&t);
	for(int testcase = 0; testcase<t; testcase++)
	{
		printf("Case #%d: ",testcase+1);
		
		int x,r,c;
		scanf("%d %d %d",&x,&r,&c);
		if(r < c)swap(r,c);
		
		if(r*c % x != 0)
		{
			printf("RICHARD\n");
			continue;
		}
		
		bool richard_wins;
		if(x == 1)
		{
			richard_wins = 0;
		}
		if(x == 2)
		{
			richard_wins = 0;
		}
		if(x == 3)
		{
			if(c <= 1)richard_wins = 1;
			else richard_wins = 0;
		}
		if(x == 4)
		{
			if(c <= 2)richard_wins = 1;
			else richard_wins = 0;
		}
		if(x == 5)
		{
			if(c <= 2)richard_wins = 1;
			else
			{
				if(c == 3 && r == 5)richard_wins = 1;
				else richard_wins = 0;
			}
		}
		if(x == 6)
		{
			if(c <= 3)richard_wins = 1;
			else richard_wins = 0;
		}
		if(x >= 7)
		{
			richard_wins = 1;
		}
		if(richard_wins)printf("RICHARD\n");
		else printf("GABRIEL\n");
	}
	return 0;
}