#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <cstdio>
#include <functional>
#include <cassert>
#include <array>

using namespace std;

template<class T>
string tostring(T a){ stringstream ss; ss << a; return ss.str(); }

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> II;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int rev(int x) {
	string s = tostring(x);
	reverse(ALL(s));
	return atoi(s.c_str());
}

int main(){
	ifstream be("A-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	FOR(tt, T){
		cout << tt << endl;
		int n; be >> n;
		VI v(n + 1, 1000000000);
		v[1] = 1;
		for(int i = 1; i < n; i++) {
			v[i + 1] = min(v[i + 1], v[i] + 1);
			int ri = rev(i);
			if(ri <= n){
				v[ri] = min(v[ri], v[i] + 1);
			}
		}
		ki<<"Case #"<<tt+1<<": "<<v[n]<<endl;
	}

	ki.close();
	return 0;
}