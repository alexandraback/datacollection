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

const int width=100;
const int offset=width/2;

int get_index(int x){
	return x+offset;
}

pii dfs(vi &field,int num_blocks,int n,int x,int y){
	if(num_blocks==n){
		if(x%2==0){
			if((field[get_index(x)]-1)*2>=y){
				pii ret=make_pair(1,1);
				return ret;
			}else{
				pii ret=make_pair(0,1);
				return ret;
			}
		}else{
			if((field[get_index(x)]-1)*2>=y-1){
				pii ret=make_pair(1,1);
				return ret;
			}else{
				pii ret=make_pair(0,1);
				return ret;
			}
		}
	}
	pii ret=make_pair(0,0);
	bool slide=false;
	if(field[get_index(0)]>field[get_index(-1)]){
		slide=true;
		int drop_x=0;
		while(1){
			bool flag;
			if(drop_x%2==0){
				flag=(field[get_index(drop_x)]>field[get_index(drop_x-1)]);
			}else{
				flag=(field[get_index(drop_x)]>=field[get_index(drop_x-1)]);
			}
			if(!flag)break;
			drop_x--;
		}
		vi nfield(field);
		nfield[get_index(drop_x)]++;
		pii dfs_res=dfs(nfield,num_blocks+1,n,x,y);
		ret.first+=dfs_res.first;
		ret.second+=dfs_res.second;
	}
	if(field[get_index(0)]>field[get_index(+1)]){
		slide=true;
		int drop_x=0;
		while(1){
			bool flag;
			if(drop_x%2==0){
				flag=(field[get_index(drop_x)]>field[get_index(drop_x+1)]);
			}else{
				flag=(field[get_index(drop_x)]>=field[get_index(drop_x+1)]);
			}
			if(!flag)break;
			drop_x++;
		}
		vi nfield(field);
		nfield[get_index(drop_x)]++;
		pii dfs_res=dfs(nfield,num_blocks+1,n,x,y);
		ret.first+=dfs_res.first;
		ret.second+=dfs_res.second;
	}
	if(!slide){
		int drop_x=0;
		vi nfield(field);
		nfield[get_index(drop_x)]++;
		pii dfs_res=dfs(nfield,num_blocks+1,n,x,y);
		ret.first+=dfs_res.first;
		ret.second+=dfs_res.second;
	}
	return ret;
}

int main(){
	int t;
	cin>>t;
	cout.precision(16);
	REP(test,t){
		int n,x,y;
		cin>>n>>x>>y;
		double ans;
		if(get_index(x)<0||get_index(x)>=width){
			ans=0;
		}else{
			vi field(width);
			pii ans_pii=dfs(field,0,n,x,y);
			ans=(double)ans_pii.first/ans_pii.second;
		}
		cout<<"Case #"<<test+1<<": "<<ans<<endl;
	}
}