using namespace std;
#include <iostream>
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
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define PB push_back
#define ALL(x) ((x).begin()),((x).end())
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)

const int infty = 999999999;

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

//          "abcdefghijklmnopqrstuvwxyz"
string tr = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int run, nruns;
	string orig, trans;

	for(int i=0; i<tr.length(); i++)
		for(int j=0; j<i; j++)
			if ( tr[i]==tr[j] ) return 1;

	cin >> nruns;
	getline(cin,orig);

	for(run=1; run<=nruns; run++) {

		getline(cin, orig);

		trans = orig;
		for(int i=0; i<trans.length(); i++) {
			if ( trans[i]!=' ' ) trans[i] = tr[trans[i]-'a'];
		}

		cout << "Case #" << run << ": ";
		cout << trans << endl;
	}

	return 0;
}
