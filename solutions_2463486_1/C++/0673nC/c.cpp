#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
//#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,j,k) for(int i=j;i<(int)(k);++i)
#define foreach(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 99999999;
const double EPS = 1e-9;
int T;
ll A,B;
vector<ll> num;

template<class T> string toA(const T& s)
{
	ostringstream sout;
	sout << s;
	return sout.str();
}

void init()
{
	string s;
	for(ll i=1;i*i<=1e14;++i){
		s=toA(i);
		int size=s.size()/2;
		if(s.size()&1) ++size;
		bool f=true;
		rep(j,size)if(s[j]!=s[s.size()-1-j]){ f=false; break; }

		if(!f) continue;
		s=toA(i*i);
		size=s.size()/2;
		if(s.size()&1) ++size;
		rep(j,size)if(s[j]!=s[s.size()-1-j]){ f=false; break; }
		if(f) num.pb(i*i);
	}
}

int main()
{
	init();
	//cout << num.size() << endl;
	//rep(i,num.size()) cout << num[i] << endl;
	cin >> T;
	rep(t,T){
		cin >> A >> B;
		int ans=0;
		rep(i,num.size())if(A<=num[i]&&num[i]<=B) ++ans;
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}
