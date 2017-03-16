/*
 ID: aandrew
 PROG: GCJ round 1A, problem A
 URL: 
 LANG: C++
 
 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pt;

int T, N, a[1005], b[1005];

bool more_stars() {
	
}

int main() {
	cin >> T;
	REP(t, T) {
		cin >> N;
		priority_queue<pair<int, int> > one, two;
		REP(i, N) { cin >> a[i] >> b[i]; one.push(make_pair(-a[i],i)); two.push(make_pair(-b[i],i)); }
		
		bool fail = false; int stars = 0, runs = 0;
		int state[1005]; CL(state);
		while ((two.size() || one.size()) && !fail) {
			bool done = false;
			REP(i, N) if (!done) {
				if (state[i] < 2 && b[i] <= stars) {
					//cout << i << " 2 star" << endl;
					stars += (2 - state[i]);
					state[i] = 2;
					runs++;
					done = true;
				}
			}
			
			if (!done) {
				int best = -1;
				REP(i, N) {
					if (state[i] == 0 && a[i] <= stars && (best == -1 || b[i] > b[best])) {
						best = i;
					}
				}
				//cout << best << endl;
				if (best != -1) {
					//cout << best << " 1 star" << endl;
					stars++;
					state[best] = 1;
					runs++;
				} else {
					fail = true;
				}
			}
		}
		
		fail = false;
		REP(i, N) if (state[i] < 2) fail = true;
		
		if (fail) 
			printf("Case #%d: Too Bad\n",t+1);
		else
			printf("Case #%d: %d\n",t+1,runs);
	}
}