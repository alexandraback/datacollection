#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

ll T, a, b;

ll pal_list[] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};

int main() {
	cin >> T;
	for (long long c = 1; c <= T; c++) {
		long long cnt = 0;
		cin >> a >> b;
		cout << "Case #" << c << ": ";
		ll* low = lower_bound(pal_list, pal_list+39, a);
		ll* high = lower_bound(pal_list, pal_list+39, b);
		ll ans = high-low;
		if (*high == b) ans++;
		cout <<  ans << endl;
		
	}
	return 0;
}