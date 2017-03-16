#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi; 
typedef vector<string> vs;

#define PB push_back
const long double PI = 3.1415926535897932384626433832795;

int place[] = {0, 0, 10, 100, 1000, 10000, 100000, 1000000};
int main(int argc, char *argv[])
{
	int num_tc, A, B;
	ifstream myfile;
	myfile.open(argv[1]);
	myfile >> num_tc;

	for (int i = 0; i < num_tc; ++i) {
		myfile >> A >> B;
		int res = 0;
		if (A < 12) A = 12;
		for (int j = A; j <= B; ++j) {
			int digits = 2;
			if (j >= 1000000) {
				digits = 7;
			} else if (j >= 100000) {
				digits = 6;
			} else if (j >= 10000) {
				digits = 5;
			} else if (j >= 1000) {
				 digits = 4;
			} else if (j >= 100) {
				digits = 3;
			}
			int x = 1;
			set <int> seen;
			for (int l = 1; l < digits; ++l) {
				x *= 10;
				int last = j % x;
				int newNum =  (place[digits - l + 1] * last) + (j / x);
				if (seen.find(newNum) != seen.end()) continue;
				seen.insert(newNum);
				if (newNum > j && newNum <= B) {
					//cout << j << " " << newNum << "\n";
					++res;
				}
			}
		}
		cout << "Case #" << i + 1 << ": " << res << "\n";
	}
	myfile.close();
	return 0;
}
