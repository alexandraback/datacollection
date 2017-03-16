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
	printf("%d", a[0]);
	for(int i = 1; i < (int)a.size();i++) printf(" %d", a[i]);
}

int main()
{


   freopen("C-small-attempt0.in","r",stdin);
   freopen("C-small-attempt0.out","w",stdout);

	int cases;
	scanf("%d",&cases);
	REP(k,cases) {
		int n; vector<int> a;
		scanf("%d",&n);
		int tmp;
		REP(i,n) { scanf("%d",&tmp); a.PB(tmp); }
		map<int, vector<int> > m;
		printf("Case #%d:", k + 1);
		bool found = false;
		//REP(i,a.size()) printf("%d ",a[i]);
		for(int i = 1; i < 1<<a.size(); i++) {
			int sum = 0;
			vector<int> ss;
			for(int j = 0; j < (int)a.size(); j++) {
				if(i & 1<<j) {
					sum += a[j];
					ss.PB(a[j]);
				}
			}
			if(m.find(sum) != m.end()) {
				printf("\n");
				printvec(ss);
		//		printf("==%d", sum);
				printf("\n");
				printvec(m[sum]);
				printf("\n");
				found = true;
				break;
			}
			m[sum] = ss;
		}
		if(!found) printf("Impossible\n");
	}

    return 0;
}
