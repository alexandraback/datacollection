#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <queue>
#include "string.h"
#include "assert.h"
#include "math.h"

using namespace std;

#define abs(x)		((x) > 0 ? (x) : -(x))
#define max(x,y)	((x) > (y) ? (x) : (y))
#define min(x,y)	((x) < (y) ? (x) : (y))
typedef unsigned __int64 uint64;

void solve() {
	int R, C, W;
	cin >> R >> C >> W;

	// How many mistakes can one make
	// If C % W == 0 --> (C/W - 1)
	// If C % W > 0 --> 

	int r = (C / W) * (R - 1);
	int a = 0;
	if (C % W == 0){
		a = C / W - 1;
		a += W;
	}
	else {
		a = C / W;
		a += W;
	}

	cout << a;
}


int main(int argc, char** argv) {
	int T;
	cin >> T; // number of test cases
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve();
		cout << endl;
	}
}

	