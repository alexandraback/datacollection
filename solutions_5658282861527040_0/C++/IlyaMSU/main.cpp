#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;

const ll mod = 1000 * 1000 * 1000 + 7;

ll solve() {
	ll a, b, k;
	cin >> a >> b >> k;
	ll res = 0;
	/*ll res = a * b;
	--a;
	--b;
	--k;
	for (int i = 30; i >= 0; --i) {
		if ((a < (1 << i)) || (b < (1 << i)))
			continue;
		if ((k >> i) % 2 == 0) {
			ll aa = a - (((k >> i) + 1) << i) + 1;
			aa = max(aa, (ll)0);
			aa = min(aa, (ll)(1 << i));
			ll bb = b - (((k >> i) + 1) << i) + 1;
			bb = max(bb, (ll)0);
			bb = min(bb, (ll)(1 << i));
			res -= aa * bb;
		}
	}*/
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			if ((i & j) < k)
				++res;
	return res;
	
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	//scanf("%d\n", &tt);
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		cout << "Case #" << i + 1 << ": " << solve() << endl;
		std::cerr << i << endl;
	}
	return 0;
}
