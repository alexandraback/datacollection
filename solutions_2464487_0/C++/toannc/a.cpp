#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <typeinfo>
#include <cmath>


#define fi first
#define se second
#define pbk push_back
#define mpr make_pair
#define ins insert
#define ii pair<int,int>
#define iii pair<int,ii>
#define fori(x,y) for(__typeof(x) i = (x),__y(y);i!=__y;i++)
#define forj(x,y) for(__typeof(x) j = (x),__y(y);j!=__y;j++)
#define fork(x,y) for(__typeof(x) k = (x),__y(y);k!=__y;k++)
#define ford(i,x,y) for(typeof(x) i = (x)-1,__y(y);i!=__y;i--)
#define openfile freopen("inp.txt","r",stdin); freopen("out.txt","w",stdout);
#define closefile fclose(stdin); fclose(stdout);
#define mset(a) memset(a,0,sizeof(a));
#define aset(a,size,val) for(int i = 0;i<size;i++) a[i] = val;
#define ll long long
#define abs(x) (x<0? -x:x)
#define sqr(x) ((x) * (x))
using namespace std;

int gcd(int a,int b) {return (!b? a:gcd(b,a%b));}
string toString(double x) {ostringstream cv; cv << x;return cv.str();}
int toInt(string x) {int n;return (istringstream(x) >> n ? n:0);}
char toChar(int x) {return char(int('0') + x);}
string toBase(ll x,int y) {string s("");while(x) {s=toChar(x%2)+s;x/=2;}return s;}
const double pi = 2*acos(0.0);
const int oo = 100000000;
const int maxn = 102;

int solve(ll r,ll t) {
	ll left(0), right(trunc(sqrt(t)));
	while (left != right) {
		ll m = (left + right+1)/2;
		if (2*m + 2*r-1 <= t/m) 
			left = m;
		else right = m - 1;
	}
	return right;
}
int main() {
	openfile
	int test;
	cin >> test;
	fori(0,test) {
		ll r,t;
		cin >> r >> t;
		cout << "Case #" << i+1 <<": ";		
		cout << solve(r,t) << endl;
	}
	closefile
	return 0;
}
