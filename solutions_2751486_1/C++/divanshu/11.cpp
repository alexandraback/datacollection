/* Divanshu Garg */
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
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
int ABS(int a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code bgins here */

int pre() {

}

bool vowel(char ch) {
	if ( ch == 'a' ) return true;
	if ( ch == 'e' ) return true;
	if ( ch == 'i' ) return true;
	if ( ch == 'o' ) return true;
	if ( ch == 'u' ) return true;
	return false;
}

int main() {
	pre();
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	ill t,tests=1,i,k,j;
	cin >> t;
	while ( t-- ) {
		string s; int n;
		cin >> s >> n;
		ill ans = 0;
		ill last = -1;
		ill cnt = 0;
		F(i,0,s.size()) {
			if ( !vowel(s[i]) ) {
				cnt++;
				if ( cnt >= n ) {
					ans += ((i-n+1)-last)*(s.size()-i);
					last = i-n+1;
				}
			} else {
				cnt = 0;
			}
			// cout << i << " " << ans << " " << last << endl;
		}
		cout << "Case #" << tests << ": " << ans << endl;
		tests++;
	}
	return 0;
}