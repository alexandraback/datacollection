#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("1AA.out");
ifstream fin ("1AA.in");

bool check(ll a,ll r,ll t) {
	unsigned ll t1 = 2*r+1;
	unsigned ll r2 = r+2*(a-1);
	unsigned ll tot = (a*(t1+2*r2+1))/2;
	if (tot <= t) return true;
	return false;
}

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		ll r,p;
		fin >> r >> p;
		ll bot = 1;
		ll top = 707106780;
		while (bot < top) {
			ll mid = (bot+top+1)/2;
			if (check(mid,r,p)) {
				bot = mid;
			}
			else top = mid-1;
		}
		fout << "Case #" << t << ": " << bot << endl;
	}
    return 0;
}