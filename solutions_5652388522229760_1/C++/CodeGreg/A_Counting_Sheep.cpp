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

ifstream fin ("A-large.in");
ofstream fout ("A-large.out");

int main() {
    ios_base::sync_with_stdio(false);
    fout << setprecision(12) << fixed;

    int T; fin >> T;
	bool found[10];
    REP(t,1,T+1) {
    	long long N; fin >> N;
		long long cnum = 0;
    	fill_n(found,10,false);
    	int num_found = 0;
    	do {
    		cnum += N;
    		long long div = cnum;
    		while (div > 0) {
    			int digit = div % 10;
    			div /= 10;
    			if (!found[digit]) {
    				found[digit] = true;
    				num_found++;
    			}
    		}
    	} while (num_found < 10 && cnum < N * 100000000);

    	if (num_found == 10) {
    		fout << "Case #" << t << ": " << cnum << endl;
    	} else {
    		fout << "Case #" << t << ": " << "INSOMNIA" << endl;
    	}
    }
    return 0;
}
