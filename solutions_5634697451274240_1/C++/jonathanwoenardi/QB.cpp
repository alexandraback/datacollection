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

int main () {
	int T = 0;
	string S = "";

	cin >> T;
	for(int x = 0; x < T; ++x) {

		S = "";
		cin >> S;
		int N = S.size();
		int counter = 0;
		string ch = S.substr(0,1);
		for(int i = 1; i < N; ++i) {
			if(S.substr(i,1) != ch) {
				counter++;
			}
			ch = S[i];
		}
		if(S.substr(N-1,1) == "-") {
			counter++;
		}

		printf("Case #%d: %d\n", x+1, counter);
	}
}