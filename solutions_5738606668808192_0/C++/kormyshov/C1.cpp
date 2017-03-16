#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>
#include <iomanip>
#include <pthread.h>
#include <semaphore.h>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <bitset>
#include <algorithm>
#include <functional>

#define ABS(a) ((a)<0?(-(a)):(a))
#define SIGN(a) (((a)>0)-((a)<0))
#define SQR(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define PI (3.1415926535897932384626433832795)
#define INF (2147483647)
#define LLINF (9223372036854775807LL)
#define INF2 (1073741823)
#define EPS (0.00000001)

#define MOD (1000000007)

#define y1 stupid_cmath
#define y0 stupid_cmath_too

using namespace std;

typedef long long LL;
template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> &t) {return O<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &O,vector<T> &t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }
void dout(){cout<<endl;} template<typename Head, typename... Tail> void dout(Head H, Tail... T){cout<<H<<" "; dout(T...);}

inline bool isPrime(LL _n, LL &_d)
{ // {{{
	if((_n&1)==0) _d=2;
	if(_n%3==0) _d=3;
	if(_n<2 || (_n>3 && (_n%6&3)!=1)) return false;
	for(LL _i=5, _k=4; _i*_i<=_n; _i+=_k^6)
		if(_n%_i==0){
			_d = _i;
			return false;
		}
	return true;
} // }}}

string toString(LL a){
	string res = "";
	while(a){
		res += (char)('0'+(a&1));
		a>>=1;
	}
	reverse(res.begin(), res.end());
	return res;
}

void solve(int n, int k){
	LL b = 1<<(n-1) | 1;
	map<LL, vector<LL>> res;
	for(LL i = b, cnt=0; i < (1LL<<n) && res.size() < k; i += 2, cnt++){
		LL d;
		if(!isPrime(i, d)){
			vector<LL> v;
			v.push_back(d);
			for(int j=3; j<=10; ++j){
				LL a = 0, p = 1;
				for(int ii=0; ii<n; ++ii) a += p*(i>>ii&1), p*=j;
				if(isPrime(a, d)) break;
				v.push_back(d);
			}
			if(v.size() == 9) res[i] = v;
		}
	}
	cout << "Case #1:\n";
	for(auto e : res){
		cout << toString(e.first) << " " << e.second << endl;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, n, k;
	cin >> t >> n >> k;
	solve(n, k);
	return 0;
}
