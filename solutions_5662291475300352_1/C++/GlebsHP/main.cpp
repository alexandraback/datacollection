#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 * 1000;

int tc, n;
long long d[size], h[size], m[size];

long long tryspeed(long long rt) {
	long long sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < h[i]; j++) {
			long long c = (m[i] + 720 * j) * d[i];
			if (rt <= c)
				sum++;
			else {
				sum += (rt - c) / (360 * (m[i] + 720 * j));
			}
		}

	cerr << rt << ' ' << sum << endl;

	return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		cin >> d[i] >> h[i] >> m[i];
    		d[i] = 360 - d[i];

    		m[i] *= 720;
    	}

    	long long ans = 0;
    	for (int i = 0; i < n; i++)
    		ans += h[i];

    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < h[i]; j++) {
    			ans = min(ans, tryspeed((m[i] + 720 * j) * d[i] + 1));
    		}

    	cout << "Case #" << tnum + 1 << ": " << ans << endl;
    }

    return 0;
}