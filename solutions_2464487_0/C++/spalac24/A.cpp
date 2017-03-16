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

int main (){
	ios::sync_with_stdio(false);
	cin>>cases;
	for (int run = 1; run <= cases; ++run) {
		cout<<"Case #"<<run<<": ";
		long long r,t;
		cin>>r>>t;
		//		t /= M_PI;
		//		D(t);
		long long total = 0;
		int ans = 0;
		for (;; r += 2, ++ans) {
			//	D(total);D(total + (r+1)*(r+1)-r*r);
			if (total + 2*r+1 > t) break;
			total += 2*r+1;
		}
		assert(ans > 0);
		cout<<ans<<endl;
	}
}
