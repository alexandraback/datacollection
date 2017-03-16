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
	double c,f,x, cur, tm, gpm;
	double to_farm, to_x;

	ifstream fin("1.txt");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T){
		fout << "Case #" << t+1 << ": ";
		fin >> c >> f >> x;

		tm = 0;
		gpm = 2;

		while(1){
			to_farm = c / gpm + x / (gpm + f);
			to_x = x / gpm;
			if(to_x <= to_farm){
				tm += to_x;
				break;
			}
			tm += c / gpm;
			gpm += f;
		}

		fout << std::setprecision(15) << tm << endl;
	}

	return 0;
}


