#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#else
#include "header.h"
#include "debug.h"
#endif
#define sz(s) int((s).size())
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef pair <int,int> pii;
typedef long long LL;
template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));}
template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
 
int arr [1000010];
 
void pre() {
	memset(arr, 0x3f, sizeof(arr));
	arr[1] = 1;
	for(int i = 1; i < 1000000; ++i) {
		string var = to_string(i);
		reverse(var.begin(), var.end());
		int reverse = stoi(var);
		arr[i+1] = min(arr[i+1], arr[i] + 1);
		arr[reverse] = min(arr[reverse], arr[i] + 1);
	}
}
 
int main() {
	pre();
  #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out2.txt", "w", stdout);
  #endif
	int tt;
  cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		int num;
		cin >> num;
		printf("Case #%d: %d\n", tc, arr[num]);
	}
}
