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


int main(void){
	int t;
	cin >> t;
	rep(loop,t){
		int n,m,k;
		cin >> n >> m >> k;
		
		int cmin=inf;
		int ans;
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m-2;j++){
				if(i==n-2&&j==m-2)
					continue;
				int stone=2*(i+j);
				int area=stone+i*j;
				if(area>=k-2 && stone < cmin){
					ans=area;
					cmin=stone;
				}
			}
		}
		cout << "Case #" << loop+1 << ": " ;
		if(k<=4){
			cout << k << endl;
		}else if(cmin==inf){
			int stone=2*(n-2+m-2);
			int area=stone+(n-2)*(m-2);
			int res=k-area;
			cout << stone+res << endl;
		}else{
			cout << cmin+(k-ans) << endl;
		}
	}
	return 0;
}