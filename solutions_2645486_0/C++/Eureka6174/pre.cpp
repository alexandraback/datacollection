#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
using namespace std;
typedef long long lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
double eps=1e-8;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define shl(i)      ((lld)1 << (i))
#define MP make_pair
#define PB push_back

const int N = 11000;
lld v[N];
lld e, r, n;
lld up[N], now[N], sum[N], tr[N];

lld ans;

void cost(lld n, lld m){
	tr[n+1] = up[n+1];
	while(m > 0){
		for (int i=1; i<=n; ++i) sum[i] = sum[i-1] + now[i];
		for (int i=n; i>=1; --i) tr[i] = min(tr[i+1], up[i] - sum[i]);
		if (sum[n] == up[n]) return;
		int p = 1;
		for (int i=2; i<=n; ++i){
			if (tr[p] == 0 || now[p] == e){
				p = i;
			}else if (now[i] != e && v[i] > v[p]){
				p = i;
			}
		}
		int c = min(min(tr[p], e - now[p]), m);
		m -= c;
		now[p] += c;
		ans += c * v[p];
	}
}

lld gao(){
	mem(now, 0);
	mem(sum, 0);
	ans = 0;
	up[1] = e;
	for (int i=1; i<=n; ++i){
		up[i+1] = up[i] + r;
		if (i != n) cost(i, r);
		else cost(i, e);
	}
	return ans;
}

int main(){
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	lld cases;
	cin >> cases;
	for (int I=1; I<=cases; ++I){
		printf("Case #%d: ", I);
		cin >> e >> r >> n;
		for (int i=1; i<=n; ++i){
			cin >> v[i];
		}
		cout << gao() << endl;
	}
	return 0;
}
