#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++) 
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

int T;
ll r, t;

ll paint(ll n) {
	return (2*r+1) + 2 * (n-1);
}

int main() {
	cin>>T;
	rep(k,T) {
		cin>>r>>t;
		ll lower = 0;
		ll upper = 2000000000;
		while(lower < upper-1) {
			ll mid = (upper + lower) / 2;
			ll p = paint(mid);
			if(p <= (t/mid)) {
				lower = mid;
			} else {
				upper = mid;
			}
		}
		printf("Case #%d: %lld\n", k+1, lower);
	}
}
