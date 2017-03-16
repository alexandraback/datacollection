#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define foreach(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define sqr(x) ((x)*(x))
#define clr(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
#define all(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
int dcmp(double x) { if (x < -eps) return -1; else return x > eps;}
#define se(x) cout<<#x<<" = "<<x<<endl

ll num[] = {
		1LL,
		4LL,
		9LL,
		121LL,
		484LL,
		10201LL,
		12321LL,
		14641LL,
		40804LL,
		44944LL,
		1002001LL,
		1234321LL,
		4008004LL,
		100020001LL,
		102030201LL,
		104060401LL,
		121242121LL,
		123454321LL,
		125686521LL,
		400080004LL,
		404090404LL,
		10000200001LL,
		10221412201LL,
		12102420121LL,
		12345654321LL,
		40000800004LL,
		1000002000001LL,
		1002003002001LL,
		1004006004001LL,
		1020304030201LL,
		1022325232201LL,
		1024348434201LL,
		1210024200121LL,
		1212225222121LL,
		1214428244121LL,
		1232346432321LL,
		1234567654321LL,
		4000008000004LL,
		4004009004004LL,
		100000020000001LL,
		100220141022001LL,
		102012040210201LL,
		102234363432201LL,
		121000242000121LL,
		121242363242121LL,
		123212464212321LL,
		123456787654321LL,
		400000080000004LL
};

bool check(ll val) {
	char a[110];
	sprintf(a, "%lld", val);
	int len = strlen(a);
	forn (i, len / 2) {
		if (a[i] != a[len - 1 - i])
			return false;
	}
	return true;
}

void init() {
	ll lim = 100000000;
	for (ll i = 1; i < lim; ++i) {
		if (!check(i)) continue;
		ll v = i * i;
		if (check(v)) {
			//printf("%lld (%lld)\n", v, i);
			printf("%lldLL,\n", v);
		}
	}
}

int findIndex(ll val) {
	int lft = 0;
	int rht = 48;
	while (lft < rht) {
		int mid = (lft + rht) >> 1;
		if (num[mid] < val) lft = mid + 1;
		else rht = mid;
	}
	return lft - 1;
}

void solve() {
	ll A, B;
	scanf("%lld%lld", &A, &B);
	printf("%d\n", findIndex(B + 1) - findIndex(A));
}

int main() {
//	init();
//	freopen("in.txt","r",stdin);
//	freopen("D:\\in.txt","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
	freopen("C-large-1.in","r",stdin);freopen("C-large-1.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
