#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int t;

vector<char> ans;
void solve(int x, int y) {
	int tx = 0, ty = 0;

	if ( x > 0 ) {
		ans.push_back('E');
		tx = 1;
		while ( tx != x ) {
			ans.push_back('W');
			ans.push_back('E');
			tx++;
		}
	} else if ( x < 0 ) {
		ans.push_back('W');
		tx = -1;
		while ( tx != x ) {
			ans.push_back('E');
			ans.push_back('W');
			tx--;
		}
	}

	if ( y > 0 ) {
		ans.push_back('N');
		ty = 1;
		while ( ty != y ) {
			ans.push_back('S');
			ans.push_back('N');
			ty++;
		}
	} else if ( y < 0 ) {
		ans.push_back('S');
		ty = -1;
		while ( ty != y ) {
			ans.push_back('N');
			ans.push_back('S');
			ty--;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d\n", &t);
	for ( int i = 0 ; i < t ; ++i ) {
		
		int x, y; scanf("%d%d", &x, &y);

		solve(x, y);

		if ( ans.size() > 500 ) throw 1;
		
		printf("Case #%d: ", i + 1);
		for ( int i = 0 ; i < ans.size() ; ++i )
			cout << ans[i];
		ans.clear(); putchar('\n');
	}

	return 0;
}