#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;

#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

long long r,t;

int main() {
	int n;

	cin>>n;
	for (int caso = 1; caso <= n; caso++) {
		cin>>r>>t;
		long long left = 1, right = (t+1-2*r)/2 + 3;
		while (left + 1 < right) {
			long long med = (left + right) / 2;
			
			if (med <= t / ((2*(r+med)-1))) left = med;
			else right = med;
		}
		cout << "Case #" << caso << ": " << left << endl;
	}
	return 0;
}
