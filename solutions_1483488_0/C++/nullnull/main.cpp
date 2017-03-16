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
using namespace std;

#define rep(i,start,m) for(int i=(int)(start);i<(int)(m);i++)
#define showarray(array,m) for(int sa_i=0;sa_i<(int)(m);sa_i++) cout << array[sa_i] <<" "; cout << endl;
#define showvector(array) for(int sa_i=0;sa_i<(int)(array.size());sa_i++) cout << array[sa_i] << " "; cout << endl;
stringstream ss;
#define cast(a,b) ss.clear(); ss<<a; ss>>b; ss.clear();
#define rev(s) (string((s).rbegin(), (s).rend()))
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;
#define clr(a) memset((a), 0, sizeof(a))

int dx[] = {-1,0,1,0,1,1,-1,-1};
int dy[] = {0,-1,0,1,1,-1,1,-1};

template<class T>
int pyfind(const vector<T> &vect, const T &targ){
	for(int i=0;i<vect.size();i++){
		if(vect[i] == targ) return i;
	}
	return -1;
}

int T,a,b;

void solve(){
	int sz,m; string mstr,nstr;
	int ans=0;
	map<int,bool> used;
	rep(n,a,b+1){
		cast(n,nstr);
		sz = nstr.size();
		used.clear();
		rep(i,1,sz){ //i文字前へやる
			mstr = "";
			rep(j,0,sz){
				mstr+=nstr[(i+j)%sz];
			}
			cast(mstr,m);
			if(n<m and m<=b and (not used[m])) {
				//cout << nstr << " " << mstr << endl;
				ans++;
				used[m] = true;
			}
		}
	}
	cout << ans << endl;
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/C-small-attempt0.in","rt",stdin);
	freopen("/Users/katsuma/c++/C-small-attempt0out.txt","wt",stdout);
	cin >> T;
	rep(i,0,T){
		cin >> a >> b;
		cout << "Case #" << i+1 << ": " ; 
		solve();
	}
}








