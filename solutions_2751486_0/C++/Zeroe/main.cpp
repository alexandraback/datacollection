/* Vladimir Burian, 2013
 *
 * vladaburian@gmail.com
 * vladaburian@seznam.cz
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include <algorithm>
#include <cmath>

#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;


#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)


static ifstream in;
static ofstream out;


void solve() {
	string name;
	int n;
	long x = 0;

	in >> name >> n;


	const char *str = name.c_str();
	long l = name.length();

	long first = 0;
	long count = 0;


	for (long i = 0; i < l; i++) {
		char c = str[i];
		if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
			count = 0;
			continue;
		}

		count++;

		if (count == n) {
			x += (i-n-first+2) * (l-i);
			first = i-n+2;
			count--;
		}
	}

	out << x;
}

int main() {
	string name = "A-small-attempt0";

	in.open((name + ".in").c_str());
	out.open((name + ".out").c_str());

    int T;
    in >> T;
    for (int i = 1; i <= T; i++) {
    	cout << "Case #" << i;

        out << "Case #" << i << ": ";
        solve();
        out << '\n';

        cout << " DONE\n";
    }

    in.close();
    out.close();

    return 0;
}
