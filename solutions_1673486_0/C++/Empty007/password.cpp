#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

double prob[100005];
double bom[100005];

int main() { 
	int A, B, T;
	cin >> T;
	REP(tc, T) {
		cin >> A >> B;
		REPN(i, 1, A+1) cin >> prob[i];
		bom[0] = 1.0;
		bom[1] = prob[1]*1.0;
		REPN(i, 2, A+1) bom[i] = prob[i]*bom[i-1];
		
		double expt = B + 2;
		
		for (int i = A; i >= 0; i--) {
			int left = (B - A) + 2*(A - i) + 1;
			int again = left + B + 1;
//			dbg2(left, again);
//			dbg2(bom[i], left);
			expt = min(expt, (bom[i] * left) + (1-bom[i])*again);
		}
		
		printf("Case #%d: %.06f\n", tc+1, expt);
	}
	
	return 0;
}
