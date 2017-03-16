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

int getNext(int prev, int ten) {
	int d = prev % 10;
	prev /= 10;
	return d * ten + prev;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;
    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
    	int A, B;
    	cin >> A >> B;
    	int ten = 1;
    	while (ten <= A || ten <= B) ten *= 10;
    	ten /= 10;
    	int res = 0;
    	for (int m = A; m <= B; ++m) {
    		for (int n = getNext(m, ten); n != m; n = getNext(n, ten)) {
    			if (A <= n && n < m)
    				++res;
    		}
    	}
        cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
