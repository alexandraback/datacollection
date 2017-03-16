#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


/* Prewritten code begins */
#define SCI(x)      scanf("%d",&x)
#define REP(i,n)    for(int i=0; i<(n); ++i)
/* Prewritten code ends */

vector<double> p;
int main() {
	int T, A, B;
	SCI(T);
	REP(cs,T) {
		SCI(A); SCI(B);
		p.resize(A);
		REP(i,A) scanf("%lf", &p[i]);

		double tp = 1, e, res = 1+B+1;
		REP(i,A) {
			e = A-i+B-i+1+(1-tp)*(B+1);
			if(e < res) res = e;
			tp *= p[i];
		}
	
		e = (B-A+1) + (1-tp)*(B+1);
		if(e < res) res = e;

		printf("Case #%d: %.6lf\n", cs+1, res);
	}
	return 0;
}
