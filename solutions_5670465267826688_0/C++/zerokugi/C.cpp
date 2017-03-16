#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <unordered_map>
#include <iterator>
#include <functional>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int T;
ll L, X;
string s;

int succ[20][3]={
	{ 2, 4, 6},	// 1
	{ 3, 5, 7},	// -1
	{ 8,10,12},	// i
	{ 9,11,13},	// -i
	{ 7, 1, 2},	// j
	{ 6, 0, 3},	// -j
	{ 4, 3, 1},	// k
	{ 5, 2, 0},	// -k
	{ 3,12,11},	// ii
	{ 2,13,10},	// -ii
	{14,16,18},	// ij
	{15,17,19},	// -ij
	{10, 9, 3},	// ik
	{11, 8, 2},	// -ik
	{11,18,17},	// iji
	{10,19,16},	// -iji
	{19,11,14},	// ijj
	{18,10,15},	// -ijj
	{16,15,11},	// ijk
	{17,14,10},	// -ijk
};
string db[20] = {
	"1",
	"-1",
	"i",
	"-i",
	"j",
	"-j",
	"k",
	"-k",
	"ii",
	"-ii",
	"ij",
	"-ij",
	"ik",
	"-ik",
	"iji",
	"-iji",
	"ijj",
	"-ijj",
	"ijk",
	"-ijk"
};
int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin >> T; 
	REPS(t, T){
		cin >> L >> X >> s;
		vi d(20);
		REP(i, 20) d[i] = i;
		REP(i, s.size()){
			REP(j, 20) d[j] = succ[d[j]][s[i]-'i'];
		}
		int p = 0;
		while(X){
			if(X&1) p = d[p];
			vi e = d;
			REP(i, 20) d[i] = e[e[i]];
			X >>= 1;
		}
		string ans = (p == 18) ? "YES" : "NO";
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
