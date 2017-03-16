#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;


void allstrings ( vector<string>& all, string current, string& alphabet, int l ) {
	if ( current.size() == l ) {
		all.push_back(current);
		return;
	}

	for ( char c : alphabet ) allstrings(all, current + c, alphabet, l);
}

int main() {
	FILE *fin = freopen("B-small.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("B-small.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		
		int k, l, s;
		cin >> k >> l >> s;

		string alphabet;
		cin >> alphabet;
		string target;
		cin >> target;

		vector<string> visited;
		allstrings(visited, "", alphabet, s);

		int bananas = 0; // maximum number of bananas
		int total = 0;   // total given bananas

		// loop over all possible written strings, inefficiently :S
	    for ( string current : visited ) {
	    	// count how many times the target appears
	    	int found = 0;
	    	int start = 0;
	    	while ( (start = current.find(target, start)) != string::npos ) { found++; start += 1; }

	    	// statistics
	    	bananas = max(bananas, found);
	    	total += found;
	    }

	    printf("%.10lf\n", double(bananas - double(total) / visited.size()));
	}

	fclose(fout);
	exit(0);
}