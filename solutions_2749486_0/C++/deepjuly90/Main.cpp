#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define pb push_back
#define FOREACH(x,y) for(typeof(y.begin()) x = y.begin() ; x != y.end() ; x++)

#define LL long long

LL MOD = 1000000007;

string getX(string ans, int sum) {
	char move[2];
	move[0] = 'W';
	move[1] = 'E';
	if(sum < 0) {
		move[0] = 'E';
		move[1] = 'W';
	}
	sum = abs(sum);
	for(int i = 0 ; i < 2 * sum ; i = i + 2) {
		ans = ans + move[0];
		ans = ans + move[1];
	}
	return ans;
}

string getY(string ans, int sum) {
	char move[2];
	move[0] = 'S';
	move[1] = 'N';
	if(sum < 0) {
		move[0] = 'N';
		move[1] = 'S';
	}
	sum = abs(sum);
	for(int i = 0 ; i < 2 * sum ; i = i + 2) {
		ans = ans + move[0];
		ans = ans + move[1];
	}
	return ans;
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	cin >> tc;
	for(int t = 1 ; t <= tc ; t++) {
		string ans;
		int x, y;
		cin >> x >> y;
		ans = getX(ans, x);
		ans = getY(ans, y);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return (0);
}