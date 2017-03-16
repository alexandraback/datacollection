#include <iostream> 
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <deque>
#include <numeric>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-10;

int main()
{
	int t;
	int a, b, k;
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");
	//ifstream fin("a.in");
	//ofstream fout("a.out");
	fin >> t;
	for (int ti = 1; ti <= t; ti++) {
		//bool isOk = true;
		fin >> a >> b >> k;
	//	string s;
		int pairs = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int m = i & j;
				if ( m < k) {
					pairs++;
				}
			}
		}

		//if ( min < l + 1) {
			fout << "Case #" << ti <<": " << pairs <<endl;
		

	}

	fout.close();
	return 0;
}



