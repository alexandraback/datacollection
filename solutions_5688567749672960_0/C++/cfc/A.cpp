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
#include <string.h>
#include <cstring>
#define oo (int)1e9
#define fill( a , v ) memset( a , v , sizeof (a) )
#define bits( x ) __builtin_popcount( x )
#define gcd( a , b ) __gcd( a, b )
#define lcm( a , b ) (a/gcd( a, b ) ) * b
#define s(n)scanf( "%d" , &n )
#define add push_back
const int mxn = 1000000 + 10;
typedef long long ll;
#define pii pair<double,double>
using namespace std;
int cs, T;
ll n;

ll rev(ll a) {
	ll ans = 0;
	while(a) {
		ans = ans * 10 + (a%10);
		a /= 10;
	}
	return ans;
}

int main() {
	int first, second;
	s(T);

	while(T--) {
		cin >> n;
		map<ll, short> vis;
		ll res = -1;
		queue<ll>q;
		q.push(1L);
		q.push(1L);
		vis[1L] = 1;
		while(q.size()) {
			ll f = q.front();q.pop();
			ll ans = q.front();q.pop();
			if(f == n) {
				res = ans;
				break;
			}

			ll nxt = f+1;
			if(vis.find(nxt) == vis.end() && nxt <= n) {
				q.push(nxt);
				q.push(ans+1);
				vis[nxt] = 1;
			}

			nxt = rev(f);

			if(vis.find(nxt) == vis.end() && nxt <= n) {
				q.push(nxt);
				q.push(ans+1);
				vis[nxt] = 1;
			}
		}
		printf("Case #%d: %lld\n", ++cs, res);
	}
}