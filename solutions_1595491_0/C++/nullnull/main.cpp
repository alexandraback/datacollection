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

int TT,n,S,p,t[200];
int nsup[31] = {0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10 };
int sup[31] = {-1,-1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,-1,-1};

void solve(){
	int ans=0,tmp=0;
	rep(i,0,n){
		if(nsup[t[i]]>=p){
			ans++;
		}else if(sup[t[i]]>=p){
			tmp++;
		}
	}
	ans += min(tmp,S);
	
	cout << ans << endl;
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/B-small-attempt0.in","rt",stdin);
	//freopen("/Users/katsuma/c++/output.txt","wt",stdout);
	freopen("/Users/katsuma/c++/B-small-attempt0out.txt","wt",stdout);
	
	cin >> TT;
	rep(i,0,TT){
		cin >> n >> S >> p;
		rep(j,0,n){
			cin >> t[j];
		}
		cout << "Case #" << i+1 << ": " ; 
		solve();
	}
}








