#include <bits/stdc++.h>

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

ll d[1010],m[1010],h[1010];

int main(void){
	int TestCase;
	cin >> TestCase;
	range(Number,1,TestCase+1){
		int n;
		cin >> n;
		rep(i,n) cin >> d[i] >> h[i] >> m[i];
		int ans=0;
		ll fd,fm;
		ll sd,sm;
		if(n==1){
			fd=sd=d[0];
			fm=sm=m[0];
			sm++;
		}else{
			fd=d[0];
			fm=m[0];
			sd=d[1];
			sm=m[1];
		}
		if(sm<fm){
			swap(sm,fm);
			swap(sd,fd);
		}
		if(fm*(720-fd)<=sm*(360-sd)) ans=1;
		cout << "Case #"<< Number << ": ";
		cout << ans << endl;
	}
	return 0;
}