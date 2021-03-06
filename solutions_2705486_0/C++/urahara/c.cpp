#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <complex>
#include <numeric>
#include <valarray>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define inf 1061109567
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define mem(x,a) memset(x,a,sizeof(x))
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repi(i,a,b) for(int i(a),_b(b);i<_b;++i)
#define repr(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define repe(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define len(x) ((int)(x.size()))

#define DEBUG 1 
#if DEBUG && !ONLINE_JUDGE 
    #define debug(args...) (Debugger()) , args
	class Debugger { public: Debugger(const std::string& _separator = ", ") : first(true), separator(_separator){} template<typename ObjectType> Debugger& operator , (const ObjectType& v) { if(!first) std::cerr << separator; std::cerr << v; first = false; return *this; } ~Debugger() { std::cerr << endl;} private: bool first; std::string separator; }; template <typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) { bool first = true; os << "["; for(unsigned int i = 0; i < v.size(); i++) { if(!first) os << ", "; os << v[i]; first = false; } return os << "]"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) { bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) { if(!first) os << ", "; os << *ii; first = false; } return os << "]"; } template<typename T1, typename T2> inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) { bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) { if(!first) os << ", "; os << *ii ; first = false; } return os << "]"; } 
#else 
		#define debug(args...) 
#endif


int cnt;

class node{
	public:
		int id;
		char c;
		vi to;
		int en;
		node(char cc){
			c=cc;
			id=cnt++;
			to=vi(26,-1);
			en=0;
		}
};

vector<node> v;


string s;
int n;




map<pair<int,pair<int,int> >,int> dp;

int fun(int pos,int nd,int l){
	
	if(pos==len(s)){
		
		//~ if(nd==627050)cout<<"hic"<<endl;
		
		if( v[nd].en==1){
			
			return 0;
		}
		else return inf;
	}
	
	
	if(dp.count(mp(pos,mp(nd,l))))return dp[mp(pos,mp(nd,l))];
	
	int ret=inf;
	
	if(v[nd].en){
		ret=fun(pos,0,l);
	}
	
	if(v[nd].to[s[pos]-'a']==-1){
		if(l>=5)rep(i,26){
			
			if(v[nd].to[i]!=-1){
				ret=min(ret,1+fun(pos+1,v[nd].to[i],1));
			}
		}
	}
	else{
		ret=min(ret,fun(pos+1,v[nd].to[s[pos]-'a'],min(5,l+1)));
		if(l>=5)rep(i,26){
			
			if(v[nd].to[i]!=-1){
				ret=min(ret,1+fun(pos+1,v[nd].to[i],1));
			}
		}
	}
	
	return dp[mp(pos,mp(nd,l))]=ret;
	
}





int main(){
	ios_base::sync_with_stdio(0);
	
	freopen("in", "r", stdin);
	//~ freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	node nd('0');
	int cur=0;
	v.pb(nd);
	
	rep(i,521196){
		
		cin>>s;
		cur=0;
		
		rep(i,len(s)){
			
			if(v[cur].to[s[i]-'a']==-1){
				node nw(s[i]);
				v.pb(nw);
				v[cur].to[s[i]-'a']=len(v)-1;
				cur=len(v)-1;
			}
			else{
				cur=v[cur].to[s[i]-'a'];
			}
			
		}
		//~ if(s=="jam")cout<<cur<<endl;
		v[cur].en=1;
	}
	
	//~ debug(v[0].to);
	
	//~ cout<<cnt<<endl;
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		
		cin>>s;
		dp.clear();
		int ret=fun(0,0,5);
		
		cout<<ret<<endl;
		
		
	}
	
	
}









