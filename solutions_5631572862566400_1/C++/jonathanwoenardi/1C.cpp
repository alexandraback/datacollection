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

int dict[1005];
int temp[1005];
int res[1005];

int main() {
	int T;
	cin >> T;
	int N, q;
	int counter = 0;
	int circ = 0;

	for(int x = 0; x < T; ++x) {
		circ = 0;
		for(int y = 0; y < 1005; ++y) {
			dict[y] = 0;
			res[y] = 0;
		}

		cin >> N;

		for(int z = 1; z <= N; ++z) {
			cin >> q;
			dict[z] = q;
		}

		for(int i = 1; i <= N; ++i) {
			for(int w = 0; w < 1005; ++w) {
				temp[w] = 0;
			}

			int piece = i;
			counter = 1;
			temp[piece] = counter;
			while(temp[dict[piece]] == 0) {
				piece = dict[piece];
				counter++;
				temp[piece] = counter;
			}

			if(temp[dict[piece]] == (counter-1)) {
				res[dict[piece]] = max(res[dict[piece]],counter -1);
				res[piece] = max(res[piece],1);
			} else {
				int newcirc = counter - temp[dict[piece]] + 1;
				circ = max(circ,newcirc);
			}
		}

		int result = 0;
		for(int p = 1; p <= N; ++p) {
			result += res[p];
		}

		result = max(result, circ);

		cout << "Case #" << x+1 << ": " << result << endl;		
	}

	return 0;
}