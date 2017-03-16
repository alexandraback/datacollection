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

const int maxn = 100;

long long countA[maxn], countB[maxn];
int typeA[maxn], typeB[maxn];
int nA, nB;

long long solve(int a, int b) {
    if (a == nA || b == nB)
	return 0;

    if (countA[a] == 0)
	return solve(a+1, b);

    if (countB[b] == 0)
	return solve(a, b+1);

    if (typeA[a] == typeB[b]) {
	long long m = min(countA[a], countB[b]);
	countA[a] -= m;
	countB[b] -= m;
	long long r = m + solve(a, b);

	countA[a] += m;
	countB[b] += m;

	return r;
    }

    return max(solve(a+1,b), solve(a, b+1));
}

int main() {
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++) {

	cin >> nA >> nB;
	REP(i, nA)
	    cin >> countA[i] >> typeA[i];
	REP(i, nB)
	    cin >> countB[i] >> typeB[i];

	cout << "Case #" << cs << ": " << solve(0,0) << endl;
    }
}
