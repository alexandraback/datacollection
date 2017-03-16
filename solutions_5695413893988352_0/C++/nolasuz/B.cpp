#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

string a, b;
void mainmain(){
	int T;
	cin >> T;
	reep(o,1,T+1){
		cout << "Case #" << o << ": ";
		cin >> a >> b;
		queue<pair<pii,pair<string,string>>> q;
		q.push(mkp(pii(0,-1),mkp(a,b)));
		pair<ll,pair<string,string>> ans;
		ans.F=INFL;
		while(q.size()){
			auto top = q.front();
			q.pop();
			if(top.F.F==a.size()){
				auto tmp = ans;
				// cout<<top.F.S<<" "<<top.S.F<<" "<<top.S.S<<endl;
				ll aa = 0;
				ll bb = 0;
				rep(j,a.size()){
					aa*=10;
					aa+=top.S.F[j]-'0';
					bb*=10;
					bb+=top.S.S[j]-'0';
				}
				tmp.F=abs(aa-bb);
				tmp.S=top.S;
				mins(ans,tmp);
				continue;
			}
			if(top.F.S==-1){
				auto next = top;
				if(next.S.F[top.F.F]=='?'&&next.S.S[top.F.F]=='?'){
					next.S.F[top.F.F]='0';
					next.S.S[top.F.F]='0';
					next.F.F++;
					q.push(next);
					next.S.F[top.F.F]='1';
					next.S.S[top.F.F]='0';
					next.F.S=0;
					q.push(next);
					next.S.F[top.F.F]='0';
					next.S.S[top.F.F]='1';
					next.F.S=1;
					q.push(next);
				}
				else if(next.S.F[top.F.F]=='?'){
					next.S.F[top.F.F]=next.S.S[top.F.F];
					next.F.F++;
					q.push(next);
					if(next.S.S[top.F.F]!='9'){
						next.S.F[top.F.F]=next.S.S[top.F.F]+1;
						next.F.S=0;
						q.push(next);
					}
					if(next.S.S[top.F.F]!='0'){
						next.S.F[top.F.F]=next.S.S[top.F.F]-1;
						next.F.S=1;
						q.push(next);	
					}
				}
				else if(next.S.S[top.F.F]=='?'){
					next.S.S[top.F.F]=next.S.F[top.F.F];
					next.F.F++;
					q.push(next);
					if(next.S.F[top.F.F]!='9'){
						next.S.S[top.F.F]=next.S.F[top.F.F]+1;
						next.F.S=1;
						// cout<<"next "<<next.S.F<<" "<<next.S.S<<endl;
						q.push(next);
					}
					if(next.S.F[top.F.F]!='0'){
						next.S.S[top.F.F]=next.S.F[top.F.F]-1;
						next.F.S=0;
						q.push(next);	
					}
				}
				else{
					if(next.S.F[top.F.F]==next.S.S[top.F.F]){
						next.F.F++;
						q.push(next);
					}
					else if(next.S.F[top.F.F]<next.S.S[top.F.F]){
						next.F.F++;
						next.F.S=1;
						q.push(next);
					}
					else{
						next.F.F++;
						next.F.S=0;
						q.push(next);
					}
				}
			}
			else if(top.F.S){
				auto next = top;
				if(next.S.F[top.F.F]=='?') next.S.F[top.F.F]='9';
				if(next.S.S[top.F.F]=='?') next.S.S[top.F.F]='0';
				next.F.F++;
				q.push(next);
			}
			else{
				auto next = top;
				if(next.S.F[top.F.F]=='?') next.S.F[top.F.F]='0';
				if(next.S.S[top.F.F]=='?') next.S.S[top.F.F]='9';
				next.F.F++;
				q.push(next);
			}
		}
		cout<<ans.S.F<<" "<<ans.S.S<<endl;
	}
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}