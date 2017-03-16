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

   freopen("A-small-attempt0.in","r",stdin);
   freopen("A-small-attempt0.out","w",stdout);


	int cases;
	scanf("%d",&cases);
	REP(k, cases) {
		int r, t, count = 0;
		scanf("%d %d",&r,&t);
		int d = t;
		for(int i = r; ; i += 2) {
			int s = (i+1) * (i+1) - i*i;
			d -= s;
			if(d >= 0) count++;
			else break;
		}
		printf("Case #%d: %d\n", k + 1, count);
	}


    return 0;
}
