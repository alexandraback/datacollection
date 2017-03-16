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

int main()
{

   freopen("A-small-attempt5.in","r",stdin);
   freopen("output5.out","w",stdout);

	int cases;
	scanf("%d",&cases);
	REP(k,cases) {
		int n; scanf("%d",&n);
		vector<int> a;
		int tmp;
		int sum = 0;
		bool hasZero = false;
		REP(i,n) { scanf("%d",&tmp); if(tmp == 0) hasZero = true; sum+=tmp; a.PB(tmp); }
		printf("Case #%d:", k + 1);
		vector<double> res;
		REP(i, a.size()) {
			double r = 1 - (1.0 / a.size()) - (a[i]*1.0/sum);
			if(hasZero && a[i] != 0) res.PB(0);
			else res.PB(100*r*1000000);
			//printf(" %.6lf", r*100);
		}
		int z = 0;
		REP(i,res.size()) if(res[i] == 0) z++;
		int s = 0;
		REP(i,res.size()) s+=res[i];
		int diff = 100*1000000 - s;
		int div = res.size();
		if(hasZero) div = res.size() - z;
		REP(i,res.size()) {
			if(hasZero && res[i] == 0) continue;
			res[i] += (diff/div);
		}
		REP(i,res.size()) printf(" %lf", res[i]/1000000);
		printf("\n");

	}

    return 0;
}
