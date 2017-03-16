#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=(n-1);i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define FORR(i,z,n) for (int (i)=(n-1);(i)>=(z);--(i))
#define FOREACH(it,c) \
  for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(x) remove(unique((x).begin(),(x).end()),(x).end())
#define CLEAR(x,v) memset((x),(v),sizeof((x)))
#define FORS(i,x) for(int i=0;i<(int)(x).size();i++)

typedef long long ll;
typedef vector<ll> VI;
const double EPS=1e-10;
const ll INF=1ll<<61;
int n;
VI s;
typedef map<ll,int> MLI;
typedef vector<MLI> VMLI;
VMLI how;

int get(int i, ll k) {
//	cerr << "*" << i << ' ' << k << endl;
	if (i==n) return -1;
	if (i==2*n+1) return (k==0?0:-1);
	MLI::iterator it=how[i].find(k);
	if (it!=how[i].end()) return it->second;
	if (get(i+1,k)!=-1) return how[i][k]=0;
	int nx=i+1;
	if(nx<=n) nx+=n+1;
//	cerr << "ieee " << s[i] << endl;
	if (get(nx,k+s[i])!=-1) return how[i][k]=1;
	if (get(nx,k-s[i])!=-1) return how[i][k]=2;
	return how[i][k]=-1;
}

int main() {
	int T;
	cin >> T;
	FORE(t,1,T) {
		cin >> n;
		s=VI(n*2+1);
		how=VMLI(n*2+1);
		REP(i,n) cin >> s[i];
		REP(i,n) s[i+n+1]=s[i];
//		FORS(i,s) cerr << ' ' << s[i]; cerr << endl;
		cout << "Case #" << t << ":" << endl;
		if (get(0,0)==-1) cout << "Impossible" << endl;
		else {
			VI s1,s2;
			ll val=0;
			for (int i=0;i<2*n+1;++i) {
				int nx=how[i][val];
//				cerr << i << ' ' << nx << endl;
				if(nx==1) {
					s1.push_back(s[i]);
					val+=s[i];
					if (i<n) i+=n+1;
				}
				else if(nx==2) {
					s2.push_back(s[i]);
					val-=s[i];
					if (i<n) i+=n+1;
				}
			}
			FORS(i,s1) {
				if (i) cout << ' ';
				cout << s1[i];
			}
			cout << endl;
			FORS(i,s2) {
				if (i) cout << ' ';
				cout << s2[i];
			}
			cout << endl;
		}
	}
}

