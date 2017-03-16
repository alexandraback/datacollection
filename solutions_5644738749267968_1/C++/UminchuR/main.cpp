#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef vector<LL> VLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 1000000007

double a[1111], b[1111];

int solve1(int n){
	int b0=0, b1=n-1, ret=0;
	REP(i,n){
		if(a[i]<b[b0]){
			b1--;
		}else{
			b0++;
			ret++;
		}
	}
	return ret;
}

int solve2(int n){
	int b0=0, b1=n-1, ret=0;
	REP(i,n){
		if(a[n-i-1]>b[b1]){
			ret++;
			b0++;
		}else{
			b1--;
		}
	}
	return ret;
}

void solve(){
	int n;
	cin>>n;
	REP(i,n)cin>>a[i];
	REP(i,n)cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	cout << solve1(n) << " " << solve2(n) << endl;
}


void main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin>>T;
	REP(t,T){
		printf("Case #%d: ", t+1);
		solve();
	}
}