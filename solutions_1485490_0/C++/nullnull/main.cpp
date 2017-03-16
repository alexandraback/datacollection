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
int n,m;
long long a[200],b[200];
int A[200],B[200];
unsigned long long ans;

void dfs(int aid, int bid, unsigned long long score){
	
	//finish
	if(aid>=n or bid>=m){
		ans = max(score, ans);
		return;
	}
	
	//できるだけ使う
	if(A[aid]==B[bid]){
		if(a[aid]>b[bid]){
			a[aid]-=b[bid];
			bid++;
			dfs(aid,bid,score+b[bid-1]);
			bid--;
			a[aid]+=b[bid];
		}else{
			b[bid]-=a[aid];
			aid++;
			dfs(aid,bid,score+a[aid-1]);
			aid--;
			b[bid]+=a[aid];
		}
		return;
	}
	
	//a側を進める
	dfs(aid+1,bid,score);
	
	//b側を進める
	dfs(aid,bid+1,score);
}

void solve(){
	ans = 0;
	dfs(0,0,0);
	cout << ans << endl;
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/C-small-attempt0 (1).in","rt",stdin);
	freopen("/Users/katsuma/c++/C-small-attempt0out.txt","wt",stdout);
	//freopen("/Users/katsuma/c++/C-large.in","rt",stdin);
	//freopen("/Users/katsuma/c++/C-largeout.txt","wt",stdout);
	cin >> T;
	rep(t,0,T){
		cin >> n >> m;
		rep(i,0,n){
			cin >> a[i] >> A[i];
		}
		rep(i,0,m){
			cin >> b[i] >> B[i];
		}
		cout << "Case #" << t+1 << ": " ; 
		solve();
	}
}








