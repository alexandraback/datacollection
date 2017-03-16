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

bool ok(string s) {
	REP(i,s.size()) if(s[i]=='X') return false;
	return true;
}

int main()
{

   freopen("B-small-attempt0.in","r",stdin);
   freopen("B-small-attempt0.out","w",stdout);

   int cases;
   scanf("%d",&cases);
   REP(k,cases) {
	   int n; scanf("%d",&n);
	   vector<int> star1, star2;
	   vector<int> comp;
	   REP(i,n) {
		   int a,b;
		   scanf("%d %d",&a,&b);
		   star1.PB(a);
		   star2.PB(b);
		   comp.PB(0);
	   }
	   for(int i = 0; i< (int)star2.size(); i++) {
		   for(int j = i + 1; j < (int)star2.size(); j++) {
			   if(star2[j] > star2[i]) {
				   swap(star2[i], star2[j]);
				   swap(star1[i], star1[j]);
			   }
		   }
	   }
	   int played = 0, stars = 0;
	   int v=0;
	   while(v++ <= 2000) {
		   bool f2 = false;
		   REP(i,star2.size()) {
			   if(comp[i] == 2) continue;
			   if(star2[i] <= stars && comp[i] == 0) {
				   stars+=2;
				   played++;
				   comp[i] = 2;
				   f2 = true;
				   break;
			   }
		   }
		   REP(i,star2.size()) {
			   if(comp[i] == 2) continue;
			   if(star2[i] <= stars && comp[i] == 1) {
				   stars++;
				   played++;
				   comp[i] = 2;
				   f2 = true;
			   }
		   }
		   if(!f2) {
			   REP(i,star1.size()) {
				   if(comp[i] == 2) continue;
				   if(star1[i] <= stars && comp[i] == 0) {
					   stars++;
					   played++;
					   comp[i] = 1;
					   f2 = true;
					   break;
				   }
			   }
		   }
	   }

	   int all = true;
	   REP(i,comp.size()) if(comp[i] != 2) { all = false; break; }
	   printf("Case #%d: ", k + 1);
	   if(!all) printf("Too Bad\n");
	   else printf("%d\n", played);
   }

    return 0;
}
