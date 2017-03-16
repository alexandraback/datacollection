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



#define chk(a,k) ((bool)(a&(1LL<<(k))))
#define off(a,k) (a&(~(1LL<<(k))))
#define on(a,k) (a|(1LL<<(k)))


int r,n,m,k,t1,t2,t3;



int main(){
	ios_base::sync_with_stdio(0);
	
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": "<<endl;
		
		cin>>r>>n>>m>>k;
		
		rep(i,r){
			
			map<int,int> M,M1;
			
			rep(j,k){
				cin>>t1;
				M[t1]=1;
			}
			
			queue<vi> q;
			vi tm;
			q.push(tm);
			
			while(len(q)){
				
				tm=q.front();
				q.pop();
				if(len(tm)==n){
					//debug(tm);
					M1=M;
					repi(kk,0,1<<n){
						t2=1;
						rep(j,n)if(chk(kk,j)){
							t2*=tm[j];
							//cout<<t2<<endl;
						}
						if(M1.find(t2)!=M1.end()){
							M1.erase(t2);
						}
						
					}
					//cout<<"hic"<<endl;
					//cout<<len(M1)<<endl;
					if(len(M1)==0){
						rep(i,n)cout<<tm[i];
						cout<<endl;
						goto lll;
					}
					
				}
				else{
					repi(kk,2,m+1){
						tm.pb(kk);
						q.push(tm);
						tm.pop_back();
					}
					
				}
				
			}
			//rep(i,n)cout<<2;
			cout<<endl;
			lll:;
		}
		
	}
	
	
	
}









