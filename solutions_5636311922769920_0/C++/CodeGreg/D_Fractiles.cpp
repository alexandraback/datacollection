#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

#define D(x) x
#define REP(i,a,b) for (int i = (a); i < (b); ++i)

ifstream fin ("D-small-attempt0.in");
ofstream fout ("D-small-attempt0.out");

int main() {
    ios_base::sync_with_stdio(false);
    fout << setprecision(12) << fixed;

    int T; fin >> T;
    REP(t,1,T+1) {
    	long long K, C, S; fin >> K >> C >> S;
    	if (S < ceil(K / 2.0) || (C == 1 && S < K)) {
    		fout << "Case #" << t << ": IMPOSSIBLE" << endl;
    	} else {
    		fout << "Case #" << t << ":";
    		if (C == 1) {
        		REP (s, 0, S)
        			fout << " " << (s + 1);
    		} else {
				long long seglength = 1;
				REP(i, 1, C)
					seglength *= K;
				REP (s, 0, S)
					fout << " " << (seglength * (s+1) - s);
    		}
    		fout << endl;
    	}
    }
    return 0;
}
