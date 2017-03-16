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


ll fact(ll n){
	if(n==1)
		return 1;
	else
		return n*fact(n-1);
}

int main(void){
	int t;
	cin >> t;
	rep(loop,t){
		int n;
		cin >> n;
		string in[110];
		rep(i,n) cin >> in[i];

		sort(in,in+n);

		ll ans=0;
		ll index=0;
		do{
			index++;
			bool used[26];
			rep(i,26) used[i]=false;

			bool isvalied=true;
			string cur="";
			rep(i,n) cur+=in[i];

			int p=-1;

			rep(i,cur.size()){
				int c=cur[i]-'a';
				if(p==c)
					continue;
				if(!used[c]){
					p=c;
					used[c]=true;
				}else
					isvalied=false;
			}
			//dump(cur)
			if(isvalied)
				ans++;

		}while(next_permutation(in,in+n));
		//dump(index)
		ll mul=fact(n)/index;

		cout << "Case #" << loop+1 << ": " ;
		cout << ans*mul << endl;
	}
	return 0;
}