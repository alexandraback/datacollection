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
int a,b;
double dd[200000],d[200000];
int rem,all;

void solve(){
	//showarray(d,a);
	d[0]=1;
	rep(i,1,a+1){
		d[i]=d[i-1]*dd[i-1];
	}
	all = b+1; rem = b-a+1;
	double ans = (double) all+1; //enter
	rep(i,0,a){
		double tmp = (1-d[a-i])*(2*i+rem+all) + d[a-i]*(2*i+rem);
		ans = min(ans,tmp);
	}
	//cout << ans << endl;
	printf("%0.7f\n",ans);
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/A-small-attempt0.in","rt",stdin);
	//freopen("/Users/katsuma/c++/A-large.in","rt",stdin);
	freopen("/Users/katsuma/c++/A-small-attempt0out.txt","wt",stdout);
	//freopen("/Users/katsuma/c++/A-largeout.txt","wt",stdout);
	cin >> T;
	rep(t,0,T){
		cout << "Case #" << t+1 << ": " ; 
		cin >> a >> b;
		rep(i,0,a){
			cin >> dd[i];
		}
		solve();
	}
}








