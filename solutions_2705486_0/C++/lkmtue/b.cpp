//Written by technolt~h
 
#pragma comment(linker, "/STACK:16777216")
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
#define base 1000000007

int maxlen;
vector<string> dic;

set<int> SET[20][2000];

int BIT(int s,int i) {
	return (s>>i)&1;
}

void initDic() {
	REP(i,dic.size()) {
		
		string s=dic[i];
		int sz=s.size();
		maxlen=max(maxlen,sz);
		
		REP(mask,1<<sz) {
			ll t=0;
			int last=-10;
			bool ok=true;
			REP(i,sz) {
				if(BIT(mask,i)) {
					t=(t*27+s[i]-'a'+1)%base;	
				} else {
					if(i-last<5) ok=false;
					last=i;
				}				
			}
			if (ok)SET[sz][mask].insert(t);
		}
		
		if(i%10000==0) DEBUG(i);
	}
}

int f[5111][10];

int main() {
	//freopen("a.txt","r",stdin);
	freopen("garbled_email_dictionary.txt","r",stdin);
	char z[20];
	while(gets(z)) dic.PB(string(z));
	
	initDic();
	
	freopen("a.inp","r",stdin);
	int ntest;
	cin >> ntest;
	
	
	FOR(test,1,ntest) {
		string s;
		cin >> s;
		int sz=s.size();
		s=" "+s;
		RESET(f,-1);
		
		FOR(j,0,7) f[0][j]=0;
		
		FOR(i,0,sz) FOR(ii,0,7) if(f[i][ii]!=-1) {
			int last=i-ii;
			FOR(d,1,maxlen) {
				int j=i+d;
				
				if(j<=sz) {
					REP(mask,1<<d) {						
						int save=last;
						
						bool ok=true;ll t=0;int cnt=0;string ss="";
						
						REP(k,d) {
							int vt=i+k+1;
							char c=s[vt];
							
							if(BIT(mask,k)) {								
								t=(t*27+c-'a'+1)%base;							
								cnt++;
								ss+=c;
							} else {
								if(vt-last<5) ok=false;
								last=vt;
							}
							
						}
						
						
						if(ok) {
							
							if(SET[d][mask].find(t)==SET[d][mask].end()) cnt=0;
							int jj=j-last;
							if(jj>7) jj=7;
							f[j][jj]=max(f[j][jj],f[i][ii]+cnt);
						}
						
						last=save;
					}
				}
			}
		}
		
		int res=sz;
		FOR(i,0,7) if(f[sz][i]!=-1) res=min(res,sz-f[sz][i]);
		cout << "Case #" << test << ": " << res << endl;
	}
}

