#pragma comment(linker,"/stack:256000000")

#include <cmath> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <cstring> 
#include <cstdlib> 
#include <queue> 
#include <cstdio> 
#include <cfloat>

using namespace std; 

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++) 
#define sz(v) (int)(v).size() 
#define all(v) (v).begin(), (v).end()

const double EPS = 1e-9;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	REP(_, T) {
		double C, F, X;
		cin >> C >> F >> X;
		double res = X / 2, cur = 0, can;
		for (int k = 1; ; k++) {
			cur += C / (2 + (k - 1) * F);
			can = cur + X / (2 + k * F);
			if (res + EPS < can) {
				break;
			} else {
				res = can;
			}
		}
		printf("Case #%d: %.10lf\n", _ + 1, res);
	}
	return 0;
}