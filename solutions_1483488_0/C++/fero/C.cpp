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

	int a, b;
	cin >> a >> b;

	int d = 1;
	while (10*d <= a)
	    d *= 10;

	int res = 0;
	for (int x = a; x < b; x++) {
	    int y = x;
	    do {
		if (x < y && y <= b)
		    res++;
		y = (y/10) + d*(y%10);
	    } while (y != x);
	}

	cout << "Case #" << cs << ": " << res << endl;
    }
}
