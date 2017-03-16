#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
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

int main(int argc, char *argv[])
{
	int num_tc;
	ifstream myfile;
	myfile.open(argv[1]);
	myfile >> num_tc;

	int N, S, p, ti;
	for (int i = 0; i < num_tc; ++i) {
		myfile >> N >> S >> p;
		int res = 0;
		for (int j = 0; j < N; ++j) {
			myfile >> ti;
			int score = ti/3, left = ti % 3;
			if (score >= p) {
				++res;
			} else if (left && score + 1 >= p) {
				++res;
			} else if (left == 2 && score + 2 >= p && S) {
				++res;
				--S;
			} else if (!left && score + 1 >= p && S && ti) {
				++res;
				--S;
			}
		}
		cout << "Case #" << i + 1 << ": " << res << "\n";
	}
	myfile.close();
	return 0;
}
