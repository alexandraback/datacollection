//
// b.cpp -- B
//
// Siwakorn Sriakaokul - ping128
// Written on Saturday, 13 April 2013.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>

#define MAXN 10005

using namespace std;

void reset(){
	// reset values for the each testcase
}

typedef long long LL;
LL V[MAXN];
int N, E, R;
int nextGreater[MAXN];
void solve(){
	reset();
	cin >> E >> R >> N;
	for(int i = 0; i < N; i++ ){
		cin >> V[i];
		nextGreater[i] = -1;
	}

	for(int i = 0; i < N; i++ ){
		nextGreater[i] = i;
		for(int j = i + 1; j < N; j++ ){
			if(V[j] >= V[i]){
				nextGreater[i] = j;
				break;
			}
		}
	}
	
	LL ans = 0;
	int now = E;
	for(int i = 0; i < N; i++ ){
//		cout << nextGreater[i] << "-" << endl;
	}

	for(int i = 0; i < N; i++ ){
		if(nextGreater[i] == i){

			ans += V[i] * (LL)now;
			now = min(R, E);
		} else {
			int more = R * (nextGreater[i] - i);
			int maxx = more + now;
			int extra = maxx - E;
			if(extra > 0){
				int used = min(now, extra);
				ans += V[i] * (LL)used;
				now -= used;
//				cout << i << " " << used << endl;
			}
			now += R;
		}
	}
	cout << ans << endl;
}


int main()
{
	int test;
	cin >> test;
	for(int tt = 0; tt < test; tt++ ){
		printf("Case #%d: ", tt + 1);
		solve();
	}
	return 0;
}
