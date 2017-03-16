#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>

#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm> 

using namespace std;

long long fa[1234567];

void doit() {
	int L;
	cin >> L;
	cout << fa[L] << '\n';
}

int main () {
	for (int i = 0; i <= 1234567; i++)
		fa[i] = 0;
	queue<int> rij;
	fa[1] = 1;
	rij.push(1);
	do {
		int i = rij.front();
		rij.pop();
		if (i < 1000001) {
			if (fa[i+1] == 0) {
				rij.push(i+1);
				fa[i+1] = fa[i]+1;
			} else {
				fa[i+1] = min(fa[i+1], fa[i]+1);
			}
		}
		int ci = i;
		int oi = 0;
		do{
			oi *= 10;
    		oi += (ci % 10);
    		ci = ci/10;
   		} while(ci !=0);
   		if (fa[oi] == 0) {
   			rij.push(oi);
   			fa[oi] = fa[i] + 1;
   		} else {
   			fa[oi] = min(fa[oi], fa[i]+1);
   		}
	} while (!(rij.empty()));
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		doit();
	}
	return 0;
}

