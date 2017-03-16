#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define FOREACH(iter, cont) for(__typeof((cont).begin()) iter = (cont).begin(); iter != (cont).end(); iter++)
#define REP(i, end) for(int i = 0; i < (end); i++)
#define CLEAR(arr) memset(arr, 0, sizeof(arr))
#define ALL(cont) (cont).begin(),(cont).end()

int main() {
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++) {
	int n, s, p;
	cin >> n >> s >> p;

	int t, res = 0;
	REP(i, n) {
	    cin >> t;

	    int a = (t+2)/3;
	    int b = (t+4)/3;

	    if (t < 2 || t > 29)
		res += (a >= p);

	    else {
		if (a >= p)
		    res++;
		else if (b >= p && s > 0) {
		    res++;
		    s--;
		}
	    }
	}

	cout << "Case #" << cs << ": " << res << endl;
    }
}
