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

int t;
double cost,f,target,curspeed,cur;
double ans;
int rep;
double res;

int main()
{
	OPENR("B-small-attempt0.in");
	OPENW("B-small-attempt0.out");
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		rep = 0;
		ans = INF;
		curspeed = 2.0;
		cur = 0;
		scanf("%lf %lf %lf",&cost,&f,&target);
		
		while(1)
		{
			curspeed = 2.0;
			res = 0;
			for (int i=0;i<rep;i++)
			{
				res+=cost/curspeed;
				curspeed+=f;
			}
			res+=target/curspeed;
			rep++;
			
			if (res<ans) ans = res;
			else break;
		}
		
		printf("Case #%d: %.7f\n",tc,ans);
	}
	
 	return 0;
}



