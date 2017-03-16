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

int a[25];

map < int, vector <int> > m;
map < int, bool> y;

bool isSet(int mask, int i)
{
	if(mask & (1 << i)) return true;
	return false;
}

int main()
{
	int cases, n; scanf("%d", &cases); 
	FOR(c, 1, cases + 1)
	{
		scanf("%d", &n); m.clear(); y.clear();
		FOR(i, 0, n) scanf("%d", &a[i]);
		printf("Case #%d:\n", c);
		bool flag = true;
		FOR(mask, 0, (1 << n))
		{
			vector <int> v; int s = 0;
			FOR(i, 0, n) if(isSet(mask, i)) v.PB(a[i]), s += a[i];
			sort(ALL(v));
			if(y[s] && m[s] != v)
			{
				FORV(i, m[s]) printf("%d ", m[s][i]); printf("\n");
				FORV(i, v) printf("%d ", v[i]); printf("\n");
				flag = false;
				break;
			}
			m[s] = v;
			y[s] = true;
		}
		if(flag) printf("Impossible\n");
	}
	return 0;
}