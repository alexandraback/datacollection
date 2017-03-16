#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

ofstream out("out.txt");

map<int, int> cache;

bool contains(string s, int n, int b, int e) {
	int total = 0;
	int maxchain = 0;
	for (int i = b; i<=e; i++) {
		char c = s.at(i);
		if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U') {
			total = 0;
			continue;
		}
		else {
			total++;
			if(total > maxchain)
				maxchain = total;
		}
		if (maxchain >= n) break;
	}
	return (maxchain >= n);
}

int nvalue(string s, int n) {
	int total = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = i+n-1; j < s.size(); j++) {
			bool yes = contains(s, n, i, j);
//			cout << i << " " << j <<  ": " << yes << endl;
			total += yes;
		}
	}
	return total;
}


int main() {
	ifstream f("A-small-attempt0 (2).in");
	int T;
	f >> T;

	for (int x = 0; x < T; x++) {
		cache.clear();
		string s;
		int n;

		f >> s >> n;

		int result = nvalue(s, n);

		out << "Case #" << x + 1 << ": " << result << endl;

	}

	return 0;
}
