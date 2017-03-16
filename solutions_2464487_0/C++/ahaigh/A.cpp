/*
 ID: aandrew
 PROG: gcj 2013, round 1a
 URL:
 LANG: C++
 
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cassert>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MP make_pair
#define PB push_back

ll r, t;
const double pi = acos(-1.0); 

bool has_enough(ll k) {
	//can do x rings?
	//cout << k << " " << (pi * (2*r*(k+1) + k*(k+1) + (k+1))) << endl;
	//cout << k << " " << 2*r*k + k + 2*k*(k-1) << endl;
	return 2*r + 1 + 2*(k-1) < 1.*t/k + 1e-8;
}

int main() {
	int T;
	cin >> T;
	REP(qqq,T) {
		cin >> r >> t;
		
		ll low = 1, high = t/(2*r+1) + 5;
		//cout << "!!!" << high << endl;
		
		//for (int k = high-5; k <= high+5; k++) {
		//	cout << (2*r*k + k + 2*k*(k-1)) << endl;
		//}
		
		while (low < high) {
			//cout << low << " " << high << endl;
			ll mid = (low+high+1)/2;
			//cout << mid << endl;
			if (has_enough(mid)) {
				low = mid;
			} else {
				high = mid-1;
			}
		}
		
		cout << "Case #" << (qqq+1) << ": " << low;
		cout << endl;
		
		//return 0;
	}
}
