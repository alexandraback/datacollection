#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <ctime>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#include <iostream>
using namespace std;

const int MAXN = 40;

long long gcd(long long a, long long b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int solve(long long p, long long q)
{
	if (p == 0) return -1;
	long long g = gcd(p, q);
	p /= g;
	q /= g;
	
	if (__builtin_popcount(q) != 1) return -1;
	int r =__builtin_ctz(q);
	for (int i = 1; i <= r; ++i) {
		if ( (1ll << (r - i) ) & p) return i;
	}
	
	return -1;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int t = 1; t <= T; ++t) {
		string x;
		cin >> x;
		
		long long p, q;
		p = 0;
		q = 0;
		int idx = 0;
		for (;idx < x.size(); ++idx) {
			if (x[idx] == '/') break;
			p = p * 10 + x[idx] - '0';
		}
		++idx;
		for (; idx < x.size(); ++idx) {
			if (x[idx] == '/') break;
			q = q * 10 + x[idx] - '0';
		}
		
		int ans = solve(p, q);
		if (ans < 0) {
			printf("Case #%d: impossible\n", t);
		} else {
			printf("Case #%d: %d\n", t, ans);
		}
		
		
	}
	
    return 0;
}
