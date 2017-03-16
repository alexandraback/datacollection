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
#include <queue>

using namespace std;

#define D(x) x
#define REP(i,a,b) for (int i = (a); i < (b); ++i)

ifstream fin ("A-large.in");
ofstream fout ("A-large.out");

int main() {
    ios_base::sync_with_stdio(false);
    cout << setprecision(12) << fixed;

    int T; fin >> T;
    REP(t,1,T+1) {
    	string s; fin >> s;
    	int freq[26];
    	fill_n(freq,26,0);
    	REP(i,0,s.length())
    		freq[s[i]-'A']++;


/*		REP(i,0,26) {
			cout << (char)('A' + i) << ", ";
		}
		cout << endl;

		REP(i,0,26) {
			cout << freq[i] << ", ";
		}
		cout << endl;*/

    	int res[10];
    	fill_n(res,10,0);
    	res[0] = freq['Z'-'A'];
    	freq['Z'-'A'] -= res[0];
    	freq['E'-'A'] -= res[0];
    	freq['R'-'A'] -= res[0];
    	freq['O'-'A'] -= res[0];

    	res[6] = freq['X'-'A'];
    	freq['S'-'A'] -= res[6];
		freq['I'-'A'] -= res[6];
		freq['X'-'A'] -= res[6];

    	res[2] = freq['W'-'A'];
    	freq['T'-'A'] -= res[2];
		freq['W'-'A'] -= res[2];
		freq['O'-'A'] -= res[2];

		res[4] =  freq['U'-'A'];
		freq['F'-'A'] -= res[4];
		freq['O'-'A'] -= res[4];
		freq['U'-'A'] -= res[4];
		freq['R'-'A'] -= res[4];

		res[3] =  freq['R'-'A'];
		freq['T'-'A'] -= res[3];
		freq['H'-'A'] -= res[3];
		freq['R'-'A'] -= res[3];
		freq['E'-'A'] -= res[3];
		freq['E'-'A'] -= res[3];

/*		REP(i,0,26) {
			cout << freq[i] << ", ";
		}
		cout << endl;*/
		res[1] =  freq['O'-'A'];
		freq['O'-'A'] -= res[4];
		freq['N'-'A'] -= res[4];
		freq['E'-'A'] -= res[4];

		res[8] =  freq['T'-'A'];
		freq['E'-'A'] -= res[8];
		freq['I'-'A'] -= res[8];
		freq['G'-'A'] -= res[8];
		freq['H'-'A'] -= res[8];
		freq['T'-'A'] -= res[8];

		res[5] =  freq['F'-'A'];
		freq['F'-'A'] -= res[5];
		freq['I'-'A'] -= res[5];
		freq['V'-'A'] -= res[5];
		freq['E'-'A'] -= res[5];

		res[7] =  freq['V'-'A'];
		freq['S'-'A'] -= res[7];
		freq['E'-'A'] -= res[7];
		freq['V'-'A'] -= res[7];
		freq['E'-'A'] -= res[7];
		freq['N'-'A'] -= res[7];

		res[9] =  freq['I'-'A'];
		freq['N'-'A'] -= res[9];
		freq['I'-'A'] -= res[9];
		freq['N'-'A'] -= res[9];
		freq['E'-'A'] -= res[9];

/*		REP(i,0,26) {
			cout << freq[i] << ", ";
		}
		cout << endl;*/

		fout << "Case #" << t << ": ";
		REP(i,0,10) {
			REP(j,0,res[i]) {
				fout << i;
			}
		}
		fout << endl;
    }



	return 0;
}
