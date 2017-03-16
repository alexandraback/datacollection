#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>

#define tr(c, i) for(typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define sz(c) int((c).size())
#define INF 1000000000
#define EPS 1e-9
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int T, N, A;
double D, t[2005], x[2005], a;

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		printf("Case #%d:\n", tc + 1);
		
		scanf("%lf%d%d", &D, &N, &A);
		
		for(int i = 0; i < N; ++i)
			scanf("%lf%lf", &t[i], &x[i]);
			
		while(A--) {
			scanf("%lf", &a);
			
			double ans = 0.0, vc, v0c = 0, tcar, vot, s, tot;
			
			for(int i = 0; i < N-1; ++i) {
				if(x[i] > D) break;
				
				s = min(D, x[i+1]) - x[i];
				
				// other car's
				vot = (x[i+1] - x[i])/(t[i+1] - t[i]);	// pasti
				tot = s/vot;
				
				// mobil sendiri
				if(i == 0) s += x[0];
				
				vc = sqrt(v0c*v0c + 2.0*a*s);
				tcar = (vc - v0c)/a;
//				printf("i=%d, vot=%lf, tot=%lf, vc=%lf, v0c=%lf, tcar=%lf, s=%lf\n", i, vot, tot, vc, v0c, tcar, s);
//				v0c = vc;
				
				
				if(tcar < tot) {	// nyelip
					tcar = tot;
					
					ans += tot;
				}
				else {	// ketinggalan
					ans += tcar;
				}
				
//				v0c = min(vc, vot);
				v0c = vc;
			}
			
			ans = max(ans, sqrt(2.0*a*D)/a);
			
			printf("%.7lf\n", ans);
		}	
	}
	
	return 0;
}
