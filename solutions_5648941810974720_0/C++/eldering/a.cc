#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define ALL(x) ((x).begin()),((x).end())
#if __cplusplus >= 201103L
#define FOR(i,c) for(auto i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#else
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)
#endif

const int infty = 999999999;

const int dx[8] = {  1, 0,-1, 0, 1,-1,-1, 1 };
const int dy[8] = {  0, 1, 0,-1, 1, 1,-1,-1 };

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		string s;
		cin >> s;

		vector<int> freq(26), ndig(10);

		REP(i,s.length()) freq[s[i]-'A']++;

		ndig[0] = freq['Z'-'A'];
		ndig[2] = freq['W'-'A'];
		ndig[4] = freq['U'-'A'];
		ndig[5] = freq['F'-'A'] - ndig[4];
		ndig[6] = freq['X'-'A'];
		ndig[7] = freq['S'-'A'] - ndig[6];
		ndig[8] = freq['G'-'A'];

		ndig[1] = freq['O'-'A'] - ndig[0] - ndig[2] - ndig[4];
		ndig[3] = freq['H'-'A'] - ndig[8];
		ndig[9] = freq['I'-'A'] - ndig[5] - ndig[6] - ndig[8];

		string res;
		for(int i=0; i<10; i++)
			for(int j=0; j<ndig[i]; j++) res += i+'0';

		cout << "Case #" << run << ": ";
		cout << res << endl;
	}

	return 0;
}
