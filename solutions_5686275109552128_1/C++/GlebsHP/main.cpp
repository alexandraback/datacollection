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
const int inf = 1000 * 1000 * 1000;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc, n;

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> n;
    	
    	vector <int> cakes(n);
    	for (int i = 0; i < n; i++)
    		cin >> cakes[i];

    	sort(cakes.rbegin(), cakes.rend());
    	int ans = inf;
    	for (int i = 1; i <= cakes[0]; i++) {
    		int lans = i;
    		for (int j = 0; j < (int) cakes.size(); j++)
    			if (cakes[j] > i)
    				lans += (cakes[j] - i + i - 1) / i;

    		ans = min(ans, lans);
    	}

    	cout << "Case #" << tnum + 1 << ": " << ans << endl;
    }

    return 0;
}