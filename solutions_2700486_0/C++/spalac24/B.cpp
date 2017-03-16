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

const int MAXN = 30;

int mat [2*MAXN+10][2*MAXN+10];

int n;

void drop(int to, int mask, int h) {
	int x,y;
	x = 0;
	y = h+2;
	while(y > 0 and mat[x+to+MAXN][y-1+MAXN]==mask and mat[x-to+MAXN][y-1+MAXN]!=mask) {
		x -= to;
		y--;
	}
	while(y > 0 and mat[x+to+MAXN][y-1+MAXN] !=mask) {
		x += to;
		y--;
	}
	mat[x+MAXN][y+MAXN] = mask;
}

bool falls (int mask, int x, int y) {
	int h = 0;
	mat[MAXN][MAXN] = mask;
	for (int j = 1; j < n; ++j) {
		int to = ((1<<j)&mask)?1:-1;
		drop(to,mask,h);
		
		if (mat[MAXN][h+2+MAXN] == mask) h += 2;
	}
	if (abs(x) > MAXN) return false; if (abs(y) > MAXN) return false;
	return mat[x+MAXN][y+MAXN] == mask;
}

int main (){
    
	cin>>cases;
	for (int run = 1; run <= cases; ++run) {
		cout<<"Case #"<<run<<": ";
		int x,y;
		memset(mat,-1,sizeof mat);
		cin>>n>>x>>y;
		if (x == 0 and y == 0) {
		    printf("%.6lf\n",1.0);
			continue;
		}
		int mask = 1<<n;
		int times = 0;
		int total = 0;
		while(mask--) {	
			if (falls(mask,x,y)) {
				++times;
			}
			++total;
		}
	    printf("%.6lf\n",((double)times/(double)total));
	}
}
