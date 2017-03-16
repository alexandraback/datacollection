#include <algorithm>
#include <bitset>
#include <cctype>
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

char  table[50][50];

double wa[1010];
double wb[1010];

int main(void){
	int t;
	cin >> t;
	rep(loop,t){
		int n;
		cin >> n;
		rep(i,n) cin >> wa[i];
		rep(i,n) cin >> wb[i];
		sort(wa,wa+n);
		sort(wb,wb+n);
		int af=0,as=n-1,bf=0,bs=n-1;
		int y=0,z=0;
		rep(i,n){
			if(wa[af]<wb[bf]){
				af++;bs--;
			}else{
				af++;bf++;y++;
			}
		}
		af=0,as=n-1,bf=0,bs=n-1;
		rep(i,n){
			if(wa[as]<wb[bs]){
				as--;bs--;
			}else{
				as--;bf++;z++;
			}
		}
		//rep(i,n) cout << " " << wa[i];	cout << endl;
		//rep(i,n) cout << " " << wb[i];   cout << endl;
		cout << "Case #" << loop+1 << ": " << y << " " << z << endl;
	}
	return 0;
}