#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define sr(x) (int)x.size()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; For(_,a,b) cout << x[_] << ' '; cout << endl;}
#define Bit(s,i) (((s)&(1<<(i)))>0)
#define Two(x) (1<<(x))
const int MOD = 1000000007;
const int nmax = 10000;
const double E = 1e-8;
const double PI = acos(-1);
typedef long long LL;
typedef pair<int,int> pii;
int stest;
LL n;

bool WellForm(LL u) {
	if ( u % 10 != 1 ) return false;
	int v;
	u/=10;
	while ( u > 0 ) {
		v = u % 10;
		u /= 10;
		if ( u > 0 && v !=0 ) return false;
	} 
	if ( v != 1 ) return false;
	return true;
}

LL rev(LL u) {
	LL v = 0;
	while ( u > 0) {
		v = v * 10 + u % 10;
		u/=10;
	}
	return v;
}

int leng(LL u) {
	int v = 0;
	while ( u > 0) {
		v++;
		u/=10;
	}
	return v;
}

LL Cal(LL n) {
	//BUG(n);
	if ( n < 10 ) return n;
	if ( n % 10 == 0 ) return Cal(n - 1) + 1;
	if ( WellForm(n) ) return Cal(n - 2) + 2;
	int l = leng(n);
	LL m = n;
	LL cur = 1;
	LL res = 0;
	int t = l / 2 + l % 2;
	
	For(i,1, t) {
		
		res += ( m % 10 ) * cur;
		cur *= 10;
		m /= 10;
	}
	
	if ( res - 1 == 0 ) return Cal( rev(n) ) + 1;
	return Cal( n - res +1 ) + res - 1;  
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> stest;
	//BUG(WellForm(11));
	For(test,1,stest) {
		cin >> n;
		LL res = Cal(n);
		cout << "Case #" << test << ": " << res << endl; 
	}
	return 0;
}