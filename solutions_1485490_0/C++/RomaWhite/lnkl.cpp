//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const ll mod=1000000007;

map< pair< vector<pair<ll,int>> , vector<pair<ll,int>> >,ll > M;
vector<pair<ll,int> > a;
vector<pair<ll,int> > b;

ll f(){
	if (!a.size() || !b.size()) return 0;
	if (M[MP(a,b)]!=0) return M[MP(a,b)]-47;
	if (a[a.size()-1].second == b[b.size()-1].second){
		if (a[a.size()-1].first < b[b.size()-1].first){
			pair<ll,int> l = a[a.size()-1];
			a.pop_back();
			b[b.size()-1].first -= l.first;
			ll res = f() + l.first;
			a.push_back(l);
			b[b.size()-1].first += l.first;
			M[MP(a,b)] = res + 47;
			return res;
		}
		if (a[a.size()-1].first > b[b.size()-1].first){
			pair<ll,int> l = b[b.size()-1];
			b.pop_back();
			a[a.size()-1].first -= l.first;
			ll res = f() + l.first;
			b.push_back(l);
			a[a.size()-1].first += l.first;
			M[MP(a,b)] = res + 47;
			return res;
		}
		if (a[a.size()-1].first == b[b.size()-1].first){
			pair<ll,int> l = b[b.size()-1];
			b.pop_back();
			a.pop_back();
			ll res = f() + l.first;
			a.PB(l);
			b.PB(l);
			M[MP(a,b)] = res + 47;
			return res;
		}
	}
	ll res = 0;
	pair<ll,int> aa = a[a.size()-1];
	a.pop_back();
	res = max(res,f());
	a.push_back(aa);
	pair<ll,int> bb = b[b.size()-1];
	b.pop_back();
	res = max(res,f());
	b.push_back(bb);
	M[MP(a,b)] = res + 47;
	return res;
}



int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin >> t;
	FOR(ttt,0,t){
		cout << "Case #" << ttt + 1 << ": ";
		a.clear();
		b.clear();
		M.clear();
		int n,m;
		cin >> n >> m;
		a.resize(n);
		b.resize(m);
		FOR(i,0,n)
			cin >> a[i].first >> a[i].second;
		FOR(i,0,m)
			cin >> b[i].first >> b[i].second;
		reverse(ALL(a));
		reverse(ALL(b));
		cout << f() << endl;
		cerr<<ttt+1;
	}
	return 0;
}