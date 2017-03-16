/*
 ID: aaandrew
 PROG: gcj 13 qual round 
 LANG: C++
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <fstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define PB push_back

int c[100];
bool is_palindrome(ll x) {
	int k = 0;
	while (x) {
		c[k++] = x%10;
		x /= 10;
	}
	REP(i,k) if (c[i] != c[k-1-i]) return false;
	return true;
}

int T;
ll a, b;
vector<ll> v;
int main() {
	for (ll x = 1; x <= 10000000; x++) {
		//check x
		if (is_palindrome(x) * is_palindrome(x*x)) {
			v.PB(x*x);
		}
	}
	
	cin >> T;
	REP(t,T) {
		cin >> a >> b;
		
		ll ans = upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);	
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}
}
