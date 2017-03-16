#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(void){
	int t;
	cin >> t;
	rep(loop,t){
		ll  a,b;
		char tmp;
		cin >> a >> tmp >> b;
		ll g=gcd(a,b);
		a/=g;
		b/=g;

		int aa=0;
		int bb=0;

		bool ok=false;

		rep(i,50){
			ll check=(1LL<<i);
			if(b==check){
				ok=true;
				bb=i;
				break;
			}
		}

		rep(i,50){
			ll check=(1LL<<i);
			if(check<=a)
				aa=i;
		}

		cout << "Case #" << loop+1 << ": " ;
		if(ok)
			cout << bb-aa << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}