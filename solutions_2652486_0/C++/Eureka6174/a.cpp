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

int r, n, m, k;
int a[10];

bool check(int b[]){
	set<int> s;
	for (int i=0; i<2<<k; ++i){
		int p = 1;
		for (int j=0; j<k; ++j) if (i & (1 << j)) p *= b[j];
		s.insert(p);
	}
	for (int i=0; i<k; ++i){
		if (s.find(a[i]) == s.end()) return false;
	}
	return true;
}

int gao(){
	int b[10];
	if (n == 1){
		for (int i=2; i<=m; ++i){
			b[0] = i;
			if (check(b)) return i;
		}
	}else if (n == 2){
		for (int i=2; i<=m; ++i) for (int j=2; j<=m; ++j){
			b[0] = i, b[1] = j;
			if (check(b)) return i * 10 + j;
		}
	}else if (n == 3){
		for (int i=2; i<=m; ++i) for (int j=2; j<=m; ++j) for (int k=2; k<=m; ++k){
			b[0] = i, b[1] = j, b[2] = k;
			if (check(b)) return i * 100 + j * 10 + k;
		}
	}
}

int main(){
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	lld cases, r, t;
	cin >> cases;
	for (int I=1; I<=cases; ++I){
		printf("Case #%d:\n", I);
		cin >> r >> n >> m >> k;
		for (int i=0; i<r; ++i){
			for (int i=0; i<k; ++i) cin >> a[i];
			cout << gao() << endl;
		}
	}
	return 0;
}
