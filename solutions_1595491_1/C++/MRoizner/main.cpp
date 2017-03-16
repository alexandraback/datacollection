#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cout << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

bool bit(int64 mask, int k) {
    return ((1LL << k) & mask) != 0;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;
    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
    	int N, S, p;
    	cin >> N >> S >> p;
    	int res = 0;
    	for (int i = 0; i < N; ++i) {
    		int a;
    		cin >> a;
    		if (p == 0 || (p - 1) + (p - 1) + p <= a) {
    			++res;
    		} else if (S > 0 && p > 1 && (p - 2) + (p - 2) + p <= a) {
    			++res;
    			--S;
    		}
    	}
        cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
