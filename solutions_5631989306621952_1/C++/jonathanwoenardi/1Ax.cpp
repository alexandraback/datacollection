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

int main() {
	int T;
	string S,R = "";
	cin >> T;
	for(int x = 0; x < T; ++x) {
		cin >> S;
		int N = S.size();
		R = S.substr(0,1);
		for(int i = 1; i < N; ++i) {
			if(S.substr(i,1) < R.substr(0,1)) {
				R = R + S.substr(i,1);
			} else {
				R = S.substr(i,1) + R;
			}
		}
		cout << "Case #" << x+1 << ": " << R << endl;
	}

	return 0;
}