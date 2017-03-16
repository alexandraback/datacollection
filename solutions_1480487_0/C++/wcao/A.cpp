#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
#define FOR(i,a,b) for(__typeof(b) i=(a);i!=(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(),a.end()
#define EACH(i,a) FOR(i,a.begin(),a.end())
#define PB push_back
#define iss istringstream
#define SZ(a) (int)a.size()
#define CLEAR(a) memset(a,0,sizeof(a))
#define ll long long

const int MAXN = 205, LOOPS = 40;

int N, X, T;
int mem[MAXN]; 
double ans[MAXN];

int main() {
	scanf("%d",&T);
	for(int t = 1 ; t <= T ; t++) {
		scanf("%d", &N);
		X = 0;
		for(int i = 0 ; i < N ; i++) {
			scanf("%d",&mem[i]);
			X += mem[i];
		}
		
		for(int i = 0 ; i < N ; i++) {
			double lo = 0.0, hi = 1.0;
			for(int lv = 0 ; lv < LOOPS ; lv++) {
				double mid = (lo + hi) * 0.5;
				
				double score = mem[i] + mid * X;
				double need = 0.0;
				for(int j = 0 ; j < N ; j++) {
					if (j == i) {continue;}
					if (mem[j] < score) {
						need += (score - mem[j]);
					}
				}
				need /= X;
				if (need + mid > 1.0) {
					hi = mid;
				}	else {
					lo = mid;
				}
			}
			ans[i] = (hi + lo) * 0.5;
		}
		printf("Case #%d:",t);
		for(int i = 0 ; i < N ; i++) {
			printf(" %.8lf",(ans[i] * 100.0));
		}
		printf("\n");
	}

	return 0;
}
