#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <bitset>
#include <list>

#define EPS 1e-11
#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define swap(a,b) a=a^b, b=a^b, a=a^b;
#define OPENR(a) freopen(a,"r",stdin)
#define OPENW(a) freopen(a,"w",stdout)

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
int xhorse[8] = {1,2,1,2,-1,-2,-1,-2};
int yhorse[8] = {2,1,-2,-1,2,1,-2,-1};

using namespace std;

#define MAXN 1005

int t,n;
deque<double> naomi,ken;
double arNaomi[MAXN],arKen[MAXN];
bool gone[MAXN];
int ans;

void solve1()
{
	sort(naomi.begin(),naomi.end());
	sort(ken.begin(),ken.end());
	
	ans = 0;
	for (int i=0;i<n;i++)
	{
		if (naomi.front() > ken.front())
		{
			ans++;
			naomi.pop_front();
			ken.pop_front();
		}
		else
		{
			naomi.pop_front();
			ken.pop_back();
		}
	}
	printf(" %d",ans);
}

void solve2()
{
	sort(arNaomi,arNaomi+n);
	sort(arKen,arKen+n);
	
	bool found;
	ans = 0;
	memset(gone,false,sizeof(gone));
	
	for (int i=0;i<n;i++)
	{
		found = false;
		for (int j=0;j<n;j++)
		{
			if (gone[j]) continue;
			if (arKen[j]>arNaomi[i])
			{
				found = true;
				gone[j] = true;
				break;
			}
		}
		
		if (!found)
		{
			ans++;
			for (int j=0;j<n;j++)
			{
				if (gone[j]) continue;
				gone[j] = true;
				break;
			}
		}
	}
	
	printf(" %d",ans);
}

int main()
{
	OPENR("D-small-attempt0.in");
	OPENW("D-small-attempt0.out");
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		naomi.clear(); ken.clear();
		ans = 0;
		
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%lf",&arNaomi[i]);
			naomi.PB(arNaomi[i]);
		}
		for (int i=0;i<n;i++)
		{
			scanf("%lf",&arKen[i]);
			ken.PB(arKen[i]);
		}
		
		printf("Case #%d:",tc);
		solve1();
		solve2();
		printf("\n");
	}
	
 	return 0;
}



