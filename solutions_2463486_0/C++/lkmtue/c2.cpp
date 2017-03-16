//Written by technolt~h
 
#pragma comment(linker, "/STACK:1 777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
 
#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
 
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 

struct big {
	int n;
	ll digit[211];
};

big mul(big a,big b) {
	big c;
	RESET(c.digit,0);
	c.n=a.n+b.n-1;
	FOR(i,1,a.n) FOR(j,1,b.n) c.digit[i+j-1]+=a.digit[i]*b.digit[j];
	
	ll r=0;
	FOR(i,1,c.n) {
		c.digit[i]+=r;
		r=c.digit[i]/10;
		c.digit[i]%=10;
	}
	
	while(r) {
		c.digit[++c.n]=r%10;
		r/=10;
	}
	
	return c;
}

string conv(ll x) {
	string s="";
	while(x) {
		s=char(x%10+48)+s;
		x/=10;		
	}
	return s;
}

string rev(ll x) {
	string s="";
	while(x) {
		s+=char(x%10+48);
		x/=10;		
	}
	return s;
}

big toBig(string s) {
	big a;
	RESET(a.digit,0);
	a.n=s.size();
	REP(i,s.size()) a.digit[i+1]=s[i]-48;
	return a;
}

string toStr(big a) {
	string s="";
	FORD(i,a.n,1) s+=char(a.digit[i]+48);
	return s;
}

void print(big a) {
	cerr << toStr(a) << endl;
}

bool isPalin(big b) {
	FOR(i,1,b.n) if(b.digit[i]!=b.digit[b.n-i+1]) return false;
	return true;
}

bool smaller(string a,string b) {
	if(a.size()!=b.size()) return a.size()<b.size();
	return a<b;
}

string reverse(string s) {
	string ss="";
	REP(i,s.size()) ss=s[i]+ss;
	return ss;
}

vector<string> res;
vector<string> core[111];

void chk(string s) {
	if(isPalin(mul(toBig(s),toBig(s)))) {
		if(s.size()%2==0) core[(s.size()+1)/2].PB(s.substr(0,(s.size()+1)/2));
		res.PB(toStr(mul(toBig(s),toBig(s))));
	}
}

int count(string a) {
	int cnt=0;
	REP(i,res.size()) if(smaller(res[i],a)) cnt++;
	return cnt;
}

int ok(string a) {
	REP(i,res.size()) if(res[i]==a) return 1;
	return 0;
}

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
		
	core[0].PB("");
	FOR(i,1,25) {
		REP(j,core[i-1].size()){
			FOR(c,0,3) if(!(i==1 && c==0)) {
				string s=core[i-1][j]+char(c+48);
				string ss=s+reverse(s);
				chk(ss);
				ss=core[i-1][j]+char(c+48)+reverse(core[i-1][j]);
				chk(ss);
			}
		}
		cerr << i << endl;
	}
	
	sort(res.begin(),res.end(),smaller);
	//REP(i,res.size()) cout << res[i] << endl;
	
	int ntest;
	cin >> ntest;
	FOR(test,1,ntest) {
		string a,b;
		cin >> a >> b;
		cout << "Case #" << test << ": " << count(b)-count(a)+ok(b) << endl;
	}
}
