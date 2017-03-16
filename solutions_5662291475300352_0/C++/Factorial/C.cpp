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

struct hiker {
	double s;
	double v;
};

int main(){
	ifstream be("C-small-1-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	FOR(tt, T){
		int n; be >> n;
		vector<hiker> H;
		FOR(i, n){
			int d, h, m; be >> d >> h >> m;
			FOR(j, h) {
				H.push_back(hiker{ ((double)d) / 360, 1.0 / (m + j) });
			}
		}
		assert(SZ(H) <= 2);
		sort(ALL(H), [](hiker a, hiker b){return a.s < b.s; });

		if(H[0].v == H[1].v) {
			ki << "Case #" << tt + 1 << ": " << 0 << endl;
			continue;
		}

		// s = v*t
		// t = s/v
		if(H[1].v < H[0].v){ //kesobbi (1) a lassabb
			double t = (1 - H[1].s) / H[1].v;
			if((1 - H[0].s + 1) / H[0].v > t) {
				ki << "Case #" << tt + 1 << ": " << 0 << endl;
				continue;
			}
		} else { //korabbi (0) a lassabb
			double t = (1 - H[0].s) / H[0].v;
			if((1 - H[1].s + 1) / H[1].v > t) {
				ki << "Case #" << tt + 1 << ": " << 0 << endl;
				continue;
			}
		}

		ki<<"Case #"<<tt+1<<": "<<1<<endl;
	}

	ki.close();
	return 0;
}