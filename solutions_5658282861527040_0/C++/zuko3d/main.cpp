#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

int main(void){
	int T;
	int a,b,k, ret;

	ifstream fin("B-small-attempt0 (1).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T){
		fout << "Case #" << t+1 << ": ";
		fin >> a >> b >> k;
		
		ret = 0;
		REP(q, a){
			REP(w, b){
				if( (q&w) < k) ret++;
			}
		}
		fout << ret << endl;
	}

	fout.close();
	return 0;
}
