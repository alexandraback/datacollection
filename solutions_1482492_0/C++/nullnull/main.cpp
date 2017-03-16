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
int N,A;
double D,a[20],x[20],t[20];


void solve(){
	//showarray(x,N);
	//showarray(a,A);
	rep(i,0,A){
		double aa = a[i];
		double time = sqrt(2*D/aa);
		//debug(time);
		if(N==1){
			printf("%0.9f\n",time);
			continue;
		}
		double ctime = (D-x[0]) * (t[1]-t[0])/(x[1]-x[0]);
		//debug(time);debug(ctime);
		time = max(ctime,time);
		printf("%0.9f\n",time);
	}
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/B-small-attempt0.in","rt",stdin);
	freopen("/Users/katsuma/c++/B-small-attempt0out.txt","wt",stdout);
	//freopen("/Users/katsuma/c++/B-large.in","rt",stdin);
	//freopen("/Users/katsuma/c++/B-largeout.txt","wt",stdout);
	cin >> T;
	rep(tt,0,T){
		cin >> D >> N >> A;
		rep(i,0,N){
			cin >> t[i] >> x[i];
		}
		rep(i,0,A){
			cin >> a[i];
		}
		cout << "Case #" << tt+1 << ": " << endl ; 
		solve();
	}
}








