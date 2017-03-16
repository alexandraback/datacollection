#include <bits/stdc++.h>
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
#define repi(i,a,b) for(int i(a),_b(b);i<=_b;++i)
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


bool vis[4000200];
int dis[4000200];
vi ed[4000200];


long long  toint(string s){long long  r=0;istringstream sin(s);sin>>r;return r;}
string tostr(long long  a){if(a==0) return "0";string ret;for(long long  i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(ret.begin(),ret.end());return ret;}


void dij(){
	priority_queue<pair<int,int> > pq;
	dis[1]=1;
	pq.push(mp(0,1));
	while(len(pq)){
		pair<int,int> p=pq.top();pq.pop();
		vis[p.second]=1;
		//~ debug(p.second);
		if(p.second>4000000)continue;
		rep(i,len(ed[p.second])){
			if(vis[ed[p.second][i]])continue;
			if(ed[p.second][i]>4000000)continue;
			if(dis[p.second]+1<dis[ed[p.second][i]]){
				dis[ed[p.second][i]]=dis[p.second]+1;
				pq.push(mp(-dis[ed[p.second][i]],ed[p.second][i]));
			}
		}
	}
	
}







int main(){
	ios_base::sync_with_stdio(0);
	
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	
	rep(i,4000022)vis[i]=0;
	rep(i,4000022)dis[i]=inf;
	rep(i,4000022){
		
		ed[i].clear();
		ed[i].pb(i+1);
		string s=tostr(i);
		reverse(all(s));
		int tt=toint(s);
		ed[i].pb(tt);
	}
	
	dij();
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		int n;
		
		cin>>n;
		

		cout<<dis[n]<<endl;
	}
	
	
	
}








