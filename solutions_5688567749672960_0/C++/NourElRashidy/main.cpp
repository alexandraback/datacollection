#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

#define oo 1e9
#define pi 3.1415926536
#define all(x) x.begin(),x.end()
#define sorta(x) sort(all(x))
#define sortam(x,comp) sort(all(x),comp)
#define sortd(x) sort(x.rbegin(),x.rend())
#define pb push_back
#define mp make_pair
#define sf(x) scanf("%d", &x);
#define sfll(x) scanf("%I64d", &x);
#define pr(x) printf("%d ", x);

typedef long long ll;
using namespace std;

ll rev(ll n) {
	ll ret = 0;
	while(n) {
		ret = ret * 10 + (n % 10);
		n /= 10;
	}
	return ret;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	sf(t);
	for(int tc = 1; tc <= t; tc++) {
		ll n;
		sfll(n);
		ll tmp=1, res = 1;
		if(n % 10 && rev(n) < n) n = rev(n), res++;
		while(tmp != n) {
			ll t = rev(tmp);
			res++;
			if(t>tmp && t <= n) tmp = t;
			else tmp++;
		}
		printf("Case #%d: ", tc);
		cout << res << endl;
	}
	return 0;
}
