#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <set>
#include <complex>
#include <iomanip>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define show(x) cerr << "# " << #x << endl
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;
typedef pair<int, int> pii;
typedef complex<double> point;

const int MAX_N = 100 * 1000 + 10;

double pr[MAX_N];

int main(){
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; test++){
		int a, b;
		scanf("%d %d", &a, &b);
		FOR(i, a)
			scanf("%lf", &pr[i]);
		double ans = b + 2;
		double mult = 1;
		FOR(i, a)
			mult *= pr[i];
		for(int i = a; i >= 0; i--){
			double cur = 0;
			cur += mult * (a - i + b - i + 1);
			cur += (1 - mult) * (a - i + b - i + 1 + b + 1);
			ans = min(ans, cur);
			if(i)
				mult /= pr[i - 1];
		}
		printf("Case #%d: %0.7lf\n", test, ans);
	}
	return 0;
}
