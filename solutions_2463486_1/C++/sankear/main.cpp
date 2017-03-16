#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

ll ans[39] = {1LL,4LL,9LL,121LL,484LL,
10201LL,12321LL,14641LL,40804LL,44944LL,
1002001LL,1234321LL,4008004LL,100020001LL,102030201LL,
104060401LL,121242121LL,123454321LL,125686521LL,400080004LL,
404090404LL,10000200001LL,10221412201LL,12102420121LL,12345654321LL,
40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,
1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,
1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};


inline void solve(int test){
	printf("Case #%d: ", test);
	ll A, B;
	scanf(LLD" "LLD, &A, &B);
	int pos_A = lower_bound(ans, ans + 39, A) - ans, pos_B = lower_bound(ans, ans + 39, B) - ans;
	if(pos_B == 39 || ans[pos_B] > B){
		pos_B--;
	}
	int ans = pos_B - pos_A + 1;
	printf("%d\n", ans);
}

inline bool check(ll a){
	string s = "";
	while(a > 0){
		s.pb('0' + a % 10);
		a /= 10;
	}
	string rs = s;
	reverse(rs.begin(), rs.end());
	return s == rs;
}

int main(int argc, char **argv){
	if(argc > 1){
		freopen(argv[1], "r", stdin);
		freopen("ans.txt", "w", stdout);
	}
	else{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	/*cout << "int ans[] = {";
	int cnt = 0, all = 0;
	for(int i = 1; i <= int(1e7); i++){
		if(check(i) && check(ll(i) * i)){
			cout << ll(i) * i << "LL,";
			cnt++;
			all++;
			if(cnt >= 5){
				cout << endl;
				cnt = 0;
			}
		}
	}
	cout << "};" << endl;
	cerr << all << endl;
	return 0;*/
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		solve(i + 1);
		cerr << "test " << i << " of " << t << endl;
	}
	return 0;
}
