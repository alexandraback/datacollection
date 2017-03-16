#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>
#include <assert.h>
#include <time.h>
using namespace std;

int dict[2505];

int main() {

	int T;
	cin >> T;

	int N;
	int q;

	for(int x = 0; x < T; ++x) {
		for(int j = 0; j < 2505; ++j) {
			dict[j] = 0;
		}

		cin >> N;
		int bound = N*(2*N-1);

		for(int i = 0; i < bound; ++i) {
			cin >> q;
			dict[q] = (dict[q] + 1) % 2;
		}

		cout << "Case #" << x+1 << ":";

		for(int k = 1; k < 2501; ++k) {
			if(dict[k] == 1) {
				cout << " " << k;
			}
		}

		cout << endl;
	}

	return 0;
}