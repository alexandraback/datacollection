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


int n,m;

int mat [105][105];
int nmat [105][105];
int maxh [105];
int maxv [105];

bool solve () {
	for (int i = 0; i < m; ++i) {
		maxh[i] = -1;
		for (int j = 0; j < n; ++j) {
			maxh[i] = max(maxh[i],mat[i][j]);
		}
	}

	for (int j = 0; j < n; ++j) {
		maxv[j] = -1;
		for (int i = 0; i < m; ++i) {
			maxv[j] = max(maxv[j], mat[i][j]);
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			nmat[i][j] = min(maxv[j],maxh[i]);
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mat[i][j] != nmat[i][j]) return false;
		}
	}
	return true;
}

int main (){
	ios::sync_with_stdio(false);
	int cases;
	cin>>cases;
	for (int cas = 1; cas <= cases; ++cas) {
		cout<<"Case #"<<cas<<": ";
		cin>>m>>n;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin>>mat[i][j];
			}
		}
		if (solve()) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}
