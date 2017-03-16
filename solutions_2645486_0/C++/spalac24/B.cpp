using namespace std;
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iterator>
#include <bitset>
#include <cstdlib>
#include <set>

template <class T> string toStr (T x){stringstream ss;ss << x;return ss.str();}
template <class T> long long toInt (T x){stringstream ss; ss << x; long long r; ss >> r; return r;}


#define FOR(i,a,b) for(int i = (a); i <(b); ++i)
#define foreach(x,v) for(typeof (v).begin() x = v.begin(); x != v.end(); ++x)
#define sz(x) (int)(x).size()
#define DEBUG
#ifdef DEBUG
#define REACH  cout<<" reached line "<<__LINE__<<endl
#define D(x) cout<<#x " is "<<(x)<<endl
#else
#define REACH
#define D(x)
#endif	
#define D2(x) cout<<#x " is "<<(x)<<endl
typedef unsigned long long ull; 

int cases = 0;


int v [15];
int e,r,n;

int f (int fr, int en) {
	assert(en >= 0);
	if (fr > n) return 0;

	int ans = 0;
	for (int i = 0; i <= en; ++i) {
		ans=  max(ans,f(fr+1,min(e,en-i+r))+v[fr]*i);
	}
	return ans;
}

int main (){
	ios::sync_with_stdio(false);
	cin>>cases;
	for (int run = 1; run <= cases; ++run) {
		cout<<"Case #"<<run<<": ";

		cin>>e>>r>>n;
		for (int i = 1; i <= n; ++i) {
			cin>>v[i];
		}
		cout<<f(0,e)<<endl;
		
	}
}
