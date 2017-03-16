/*********************************HEADER FILES************************************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SZ(x) ((int)(x).size())
#define FORV(i,x) FOR(i,0,SZ(x))  
#define DBG(x) cout<<(#x)<<" : "<<(x)<<endl
#define PB push_back
#define ALL(x) x.begin(),x.end()

#define ACC(x) accumulate(ALL(x)) 
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define ROFE(i,a,b) for(int i=(b);i>=(a);i--)
#define MP make_pair
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int,int>
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long
#define MAX 50010

vector < PI > v1, v2; 
int lev, x, y, one, two, cur;
bool cleared1[1010], cleared2[1010];

bool cOne()
{
	while(one < SZ(v1) && cleared2[v1[one].S]) one ++;
	if(one >= SZ(v1) || cleared2[v1[one].S]) return false;
	if(v1[one].F <= cur) {cleared1[v1[one].S] = true; cur ++; one ++; return true;}
	return false;
}

int main()
{
	int cases; scanf("%d", &cases); 
	FOR(c, 1, cases + 1)
	{
		v1.clear(); v2.clear(); 
		memset(cleared1, 0, sizeof cleared1);
		memset(cleared2, 0, sizeof cleared2);
		scanf("%d", &lev); int ret = 0; cur = 0;
		FOR(i, 0, lev) scanf("%d %d", &x, &y), v1.PB(MP(x, i)), v2.PB(MP(y, i));
		sort(ALL(v1)); sort(ALL(v2));
		one = cur = 0; bool flag = true;
		FORV(i, v2)
		{
			while(v2[i].F > cur) if(cOne() == false) {flag = false; break;}
			cur ++; cleared2[v2[i].S] = true;
			if(!cleared1[v2[i].S]) cur ++;
		}
		printf("Case #%d: ", c);
		ret = 0; FORV(i, v1) ret += cleared1[i];
		if(flag) printf("%d\n", (ret + SZ(v1)));
		else printf("Too Bad\n");
	}
	return 0;
}