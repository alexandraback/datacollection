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
#include <ctime>
#include <cstdlib>

using namespace std;

#define D(x) x
#define REP(i,a,b) for (int i = (a); i < (b); ++i)

ifstream fin ("B-large.in");
ofstream fout ("B-large.out");

int main() {
    ios_base::sync_with_stdio(false);
    fout << setprecision(12) << fixed;

    int T; fin >> T;
    REP(t,1,T+1) {
    	string s; fin >> s;
    	int neg = 0;
    	for (int i = 0; i < s.length(); ++i)
    		if (s[i] == '-' && (i == 0 || s[i-1] == '+'))
    			neg++;
    	int result = 0;
    	if (neg > 0 && s[0] == '+')
    		result++;
    	if (neg > 0)
    		result += 2*neg - 1;
    	fout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
