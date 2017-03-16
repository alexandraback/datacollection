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

int main() {
	FILE *fin = freopen("A-large.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("A-large.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		
		int r, c, w;
		cin >> r >> c >> w;

		int initial = c / w;
		int best = initial * r;
		int end = (c % w ? 1 : 0) + w - 1;
		cout << best + end << endl;
		//cout << answer << endl;
	}

	fclose(fout);
	exit(0);
}