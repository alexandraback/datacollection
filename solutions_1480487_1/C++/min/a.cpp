#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

const double EPS = 1e-10;
#define REP( i, n) for(int i = 0; i < n; ++ i)
#define foreach( e, v) for( __typeof(v.begin()) e = v.begin(); e != v.end(); ++ e)
int n;
int a[209];
int sum;
double ret[209];
bool judge(double val, int idx, double rate) {
	double t = 0.0;
	for( int i = 0; i < n; ++ i) if(i != idx) {
		if( a[i] < val)
		t += (val - a[i]) / (double)sum;
	}
	if( t > 1 - rate)return true;
	else return false;
}
int main() {
		freopen("A-large.in", "r", stdin);
		freopen("out","w",stdout);
	int T;
	scanf("%d", &T);

	for( int cas = 1;cas<= T; ++cas) {
		scanf("%d", &n);
		sum = 0;
		for(int i = 0; i < n; ++ i) {
			scanf("%d", a + i);
			sum += a[i];
		}
		for( int i = 0; i < n; ++ i) {
			double begin, end, mid;
			begin = 0; end = 1;
			double cur = a[i];
			while(begin + EPS <= end) {
				mid = (begin + end) / 2;
				double buf = cur + mid * sum;
				if(judge(buf, i, mid)) {	
					end = mid;
				}else begin = mid;
			}
			ret[i] = end;
		}
	
	printf("Case #%d:", cas);
	for( int i = 0; i < n; ++ i) printf(" %.6lf", ret[i] * 100);
	puts("");
	}
	return 0;
}
