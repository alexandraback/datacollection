#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s); sin>>v; return v;}
template<class T> inline string toString(T x) {ostringstream sout; sout << x; return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
const double EPS = 1e-10;
const double PI = acos(-1.0);

int main(){
	int t;
	cin>>t;
	REP(test,t){
		int a,n;
		cin>>a>>n;
		vi s(n);
		REP(i,n){
			cin>>s[i];
		}
		ll ans=LONG_MAX;
		sort(ALL(s));
		FOR(i,0,n+1){
			ll size=a;
			ll cnt=n-i;
			REP(j,i){
				if(s[j]<size){
					size+=s[j];
				}else{
					if(size==1){goto next;}
					cnt++;
					size+=size-1;
					j--;
				}
			}
			ans=min(ans,cnt);
			next:;
		}
		cout<<"Case #"<<test+1<<": "<<ans<<endl;
	}
}