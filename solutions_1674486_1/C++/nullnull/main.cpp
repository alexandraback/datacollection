#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <math.h>
#include <cstring>
#include <complex>
using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<vector<string> > VVS;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
#define rep(i,start,m) for(int i=(int)(start);i<(int)(m);i++)
#define showarray(array,m) for(int sa_i=0;sa_i<(int)(m);sa_i++) cout << array[sa_i] <<" "; cout << endl;
#define showvector(array) for(int sa_i=0;sa_i<(int)(array.size());sa_i++) cout << array[sa_i] << " "; cout << endl;
stringstream ss;
#define cast(a,b) ss.clear(); ss<<a; ss>>b; ss.clear();
#define rev(s) (string((s).rbegin(), (s).rend()))
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;
#define clr(a) memset((a), 0, sizeof(a))
const int INF = 999999;

int dx[] = {-1,0,1,0,1,1,-1,-1};
int dy[] = {0,-1,0,1,1,-1,1,-1};

template<class T>
int pyfind(const vector<T> &vect, const T &targ){
	for(int i=0;i<vect.size();i++){
		if(vect[i] == targ) return i;
	}
	return -1;
}

int T;
int n;
vector<vector<int> > path;
bool used[2000];

bool dfs(int id){
	//finish
	//debug(id);
	if(used[id]){
		return true;
	}
	
	used[id] = true;
	if(path[id].empty()) return false;
	rep(i,0,path[id].size()){
		//showvector(path[id]);
		if(dfs(path[id][i])) return true;
	}
	return false;
}

void solve(){
	/*
	cout << endl;
	rep(i,0,path.size()){
		showvector(path[i]);
	}
	*/
	clr(used);
	rep(i,0,n){
		clr(used);
		if(dfs(i)){
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
	return;
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/A-small-attempt1.in","rt",stdin);
	//freopen("/Users/katsuma/c++/A-small-attempt1out.txt","wt",stdout);
	freopen("/Users/katsuma/c++/A-large.in","rt",stdin);
	freopen("/Users/katsuma/c++/A-largeout.txt","wt",stdout);
	cin >> T;
	rep(t,0,T){
		cin >> n;
		int tmp,tmpp;
		path.clear();
		rep(i,0,n){
			cin >> tmp;
			VI p; p.clear();
			rep(j,0,tmp){
				cin >> tmpp;
				p.push_back(tmpp-1);
			}
			path.push_back(p);
		}
		cout << "Case #" << t+1 << ": " ; 
		solve();
	}
}








