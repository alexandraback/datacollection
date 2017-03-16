//compiler: MSVC 2010 (C++ obviously)
//one template to rule them all

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

typedef unsigned long long ull;
typedef long long ll;

#define FN "gcj_a"

using namespace std;

int main() {
	//freopen("in.in", "r", stdin);
    //freopen("in.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;

	for(int tn = 0; tn < t; tn++) {
		int n;
		in >> n;
		string s;
		in >> s;

		int have = 0;
		int add = 0;
		for(int i = 0; i < s.length(); i++) {
			if(have < i) {
				add += (i - have);
				have = i;
			}
			have += s[i] - '0';
		}
		out << "Case #" << tn + 1 << ": " << add << "\n";
	}

	return 0;
}