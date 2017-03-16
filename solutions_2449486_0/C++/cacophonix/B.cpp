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
#define repe(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define len(x) ((int)(x.size()))

#define DEBUG 1 
#if DEBUG && !ONLINE_JUDGE 
	#define debug(args...) (Debugger()) , args
	class Debugger { public: Debugger(const std::string& _separator = ", ") : first(true), separator(_separator){} template<typename ObjectType> Debugger& operator , (const ObjectType& v) { if(!first) std::cerr << separator; std::cerr << v; first = false; return *this; } ~Debugger() { std::cerr << endl;} private: bool first; std::string separator; }; template <typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) { bool first = true; os << "["; for(unsigned int i = 0; i < v.size(); i++) { if(!first) os << ", "; os << v[i]; first = false; } return os << "]"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) { bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) { if(!first) os << ", "; os << *ii; first = false; } return os << "]"; } template<typename T1, typename T2> inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) { bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) { if(!first) os << ", "; os << *ii ; first = false; } return os << "]"; } 
#else 
		#define debug(args...) 
#endif


int arr[111][111],n,m,t1,t2,r,c,val,f;

map<pair<int,pair<int,int> > ,int> M;


string lawn(){
	
	while(len(M)){
		
		__typeof((M).begin()) t=M.begin();
		
		val=t->first.first;
		r=(t->first).second.first;
		c=(t->first).second.second;
		
		//debug(val,r,c);
		
		f=1;
		
		rep(i,m){
			if(arr[r][i]>val)f=0;
		}
		
		if(f){
			
			//cout<<"hic1"<<endl;
			
			rep(i,m)if(M.find(mp(val,mp(r,i)))!=M.end())M.erase(mp(val,mp(r,i)));
			
			continue;
			
		}
		
		f=1;
		
		rep(i,n){
			if(arr[i][c]>val)f=0;
		}
		
		if(f){
			
			//cout<<"hic2"<<endl;
			
			rep(i,n)if(M.find(mp(val,mp(i,c)))!=M.end())M.erase(mp(val,mp(i,c)));
			continue;
		}
		
		return "NO";
		
	}
	
	return "YES";
	
}




int main(){
	ios_base::sync_with_stdio(0);
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		
		cin>>n>>m;
		M.clear();
		
		rep(i,n)rep(j,m){
			cin>>t1;
			arr[i][j]=t1;
			M[mp(t1,mp(i,j))]=1;
		}
		cout<<lawn()<<endl;
		
	}
	
	
	
}









