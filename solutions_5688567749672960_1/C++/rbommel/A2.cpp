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
long long opz[15] = {1, 10, 29, 138, 337, 1436, 3435, 14434, 34433, 144432, 344431, 1444430, 3444429, 14444428, 34444427};

int solve(long long L) {
	long long Lc = L;
	long long tm = 1;
	long long htm = 1;
	int digits = -1;
	while (Lc > 0) {
		Lc /= 10;
		tm *= 10;
		digits++;
		if (digits % 2 == 0)
			htm *= 10;
	}
	tm /= 10;
	long long ans = opz[digits];
	long long rechts = L % htm;
	long long links = L - rechts;
	//cout << "Links " << links << " en rechts " << rechts << "\n";
	if (rechts == 0) {
		return solve(L-1)+1;
	}
	long long lkopie = links;
	long long lomg = 0;
		do{
			lomg *= 10;
    		lomg += (lkopie % 10);
    		lkopie = lkopie/10;
   		} while(lkopie !=0);
   	if (lomg == 1) {
   		ans += rechts;
   		return ans;
   	}
	ans += lomg + rechts;
	return ans; 
}

void doit() {
	long long L;
	cin >> L;
	if (L < 100) {
		cout << fa[L] << '\n';
		return;
	}
	cout << solve(L) << '\n';
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

