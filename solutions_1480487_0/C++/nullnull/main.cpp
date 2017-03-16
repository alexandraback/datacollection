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

int T,n;
int s[400];
int sum;

bool isok(double x, int id,int cid){
	int c = s[cid];
	double xx = s[id] + x * sum;
	double X = 1-x, y;
	y = (double)( double(X + (  (sum-s[id]-(n-1)*c) / double(sum)) ) / (double)(n-1));
	//debug(double(X + (  (sum-s[id]-(n-1)*c) / double(sum)) )) ;
	double yy = s[cid] + y * sum;
	/*cout << endl; 
	cout << s[id] << " " << x << " " << sum << endl;
	debug(X);debug(y);
	debug(xx); debug(yy);*/
	if(xx>=yy) return true;
	return false;
}

void solve(){
	sum = 0;
	rep(i,0,n){
		sum += s[i];
	}
	
	
	rep(id,0,n){
		double lower=0, upper=1.0;
		int cid = 0;
		if(id==0) cid = 1;
		rep(j,0,1000000){
			if(isok( (lower+upper)/2.0 ,id,cid)){
				upper = (lower+upper)/2.0;
			}else{
				lower = (lower+upper)/2.0;
			}
		}
		//cout << lower*100 << endl;
		printf("%0.7f ",lower*100);
	}
	cout << endl;
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/A-small-attempt0.in","rt",stdin);
	//freopen("/Users/katsuma/c++/A-small-attempt0out.txt","wt",stdout);
	//freopen("/Users/katsuma/c++/A-large.in","wt",stdout);
	//freopen("/Users/katsuma/c++/A-largeout.txt","wt",stdout);
	cin >> T;
	rep(t,0,T){
		cout << "Case #" << t+1 << ": " ; 
		cin >> n;
		rep(i,0,n){
			cin >> s[i];
		}
		solve();
	}
}








