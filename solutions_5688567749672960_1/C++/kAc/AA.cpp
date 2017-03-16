//I hate this town, bacause it's too filled with memories I'd rather forget.
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
#include <cstring>

//kAc
const double pi = acos(-1.0), eps = 1e-9;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MO = (int)(1e9 + 7);

//Two becomes one,and it through all eternity.
#define ALL(x) x.begin(), x.end()
#define fr(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PIII pair<PII, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)((a).size())
#define VEC vector
#define STR string
#define ISS istringstream
#define OSS ostringstream
#define CLR(a, b) memset(a, b, sizeof(a))
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }

using namespace std;
LL reverse(LL x)
{
	LL ret = 0;
	LL t = 1;
	while(x > 0){
		ret = ret * 10+ (x % 10);
		x = x / 10;
		t = t * 10;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
#endif
int TestCase; cin >> TestCase;
for (int ti = 1; ti <= TestCase; ti++){
	printf("Case #%d: ", ti);
	LL n; cin >> n; 
	bool f = false;
	if (n % 10 == 0){
		--n;
		f = true;
	}
	LL ans = 1;
	LL t = 1, l = 1;
	LL p[1000];
	p[0] = 1;
	for (int i = 1; i <= 16; i ++) p[i] = p[i - 1] * 10;
	p[0] = 0;
	while(t * 10 <= n){
		t *= 10;
		ans += p[l / 2] + p[(l + 1) / 2] - 1;	
		++l;
	}
	p[0] = 1;
	ans += reverse(n / p[(l + 1) / 2]) + n % (p[(l+1) / 2])	;
	if (reverse(n / p[(l + 1) / 2]) <= 1) --ans;
	cout << ans  + f<< endl;
}    

}
