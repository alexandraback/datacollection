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
#include <memory>
#include <time.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
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
const double EPS = 1e-9;
const double PI  = acos(-1.0);

ll gcd(ll a, ll b) {
  return b != 0 ? gcd(b, a % b) : a;
}

int main(){
	int num_cases;
	cin>>num_cases;
	REP(test_case,num_cases){
		ll bunshi,bumbo;
		char c;
		cin>>bunshi>>c>>bumbo;
		ll g=gcd(bunshi,bumbo);
		bunshi/=g,bumbo/=g;

		bool ok=false;
		for(ll i=1;i<10000000000000;i<<=1LL){
			if(bumbo==i){
				ok=true;
			}
		}
		if(ok){
			ll ans=0;
			while(bumbo>bunshi*2){
				bunshi*=2;
				ans++;
			}
			cout<<"Case #"<<test_case+1<<": "<<ans+1<<endl;
		}else{
			cout<<"Case #"<<test_case+1<<": impossible"<<endl;
		}
	}
}