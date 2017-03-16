#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
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

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,a) for(int i=0;i<(int)(a);i++)
#define ALL(i) i.begin(),i.end()
#define rALL(i) i.rbegin(),i.rend()
#define PB push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

template<class T> string i2a(T x) {ostringstream oss; oss<<x; return oss.str();}

void printvec(vector<int> a)
{
 cout<<"Vecteur:  ";
 REP(i,a.size()) cout<<a[i]<<"  ";
 cout<<endl;
}

int gain = 0, ee;

void solve(int e, int r, int index, int g, vector<int> v) {
	if(g > gain) { gain = g; }
	if(index != 0) e = min(ee, e + r);
	if(index == (int)v.size()) return;

	for(int i = 0; i <= e; i++) {
		solve(e - i, r, index+1, g + v[index]*i, v);
	}
}

int main()
{

   freopen("B-small-attempt1.in","r",stdin);
   freopen("B-small-attempt1.out","w",stdout);

	int cases;
	scanf("%d",&cases);
	REP(k, cases) {
		int e,rr,n;
		scanf("%d %d %d",&e,&rr,&n);
		ee = e;
		vector<int> v;
		REP(i,n) {
			int tmp;
			scanf("%d",&tmp);
			v.PB(tmp);
		}
		gain = 0;
		if(rr >= e) {
			REP(i,v.size()) {
				gain += (e * v[i]);
			}
		} else {
			solve(e, rr, 0, 0, v);
		}

		printf("Case #%d: %d\n", k + 1, gain);

	}

    return 0;
}
