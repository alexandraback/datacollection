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

int main(){
	ifstream be("B-large.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	FOR(tt, T){
		LL b, m;
		be >> b >> m;
		LL orig_m = m;

		if(m > ((1LL) << (b - 2))){
			ki << "Case #" << tt + 1 << ": " << "IMPOSSIBLE" << endl;
		} else {

			ki << "Case #" << tt + 1 << ": " << "POSSIBLE" << endl;

			VVI mat(b, VI(b));

			for(int i = 0; i <= b - 3; i++)
				for(int j = i + 1; j <= b - 2; j++)
					mat[i][j] = 1;
		
			mat[0][b - 1] = 1;
			m--;

			for(int i = 1; m; m >>= 1, i++){
				if(m & 1){
					mat[i][b-1] = 1;
				}
			}

			FOR(i, b){
				FOR(j, b){
					ki << mat[i][j];
				}
				ki << endl;
			}
					
		}

		//ki<<"Case #"<<tt+1<<": "<< <<endl;
	}

	ki.close();
	return 0;
}