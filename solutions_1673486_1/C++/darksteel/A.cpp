#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <map>
using namespace std;
int main() 
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T, i, j;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int A, B;
		cin >> A >> B;
		double ans = min(B+2, B+A+1);
		double p = 1.0;
		ans = min(ans, B+A+1+(1.0-p)*(B+1));
		for(i = A-1; i >= 0; i--) {
			double t;
			cin >> t;
			p *= t;
			ans = min(ans, 0.0+B-A+2*i+1+(1.0-p)*(B+1));
		}
		printf("Case #%d: %.06lf\n", t, ans);
	}
	return 0;
}
