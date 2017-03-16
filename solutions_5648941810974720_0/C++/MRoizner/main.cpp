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
#include <stack>
#include <assert.h>
#include <iomanip>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define mplus(x, y) ((x) == -1 || (y) == -1) ? -1 : ((x) + (y))
#define mmax(x, y) ((x) == -1 || (y) == -1) ? -1 : max((x), (y))
#define mmin(x, y) ((x) == -1) ? (y) : ((y) == -1) ? (x) : min((x), (y))

#define checkbit(n, k) (((1L << (k)) & (n)) != 0)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cerr << "> " << #x << ": " << (x) << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

string foo(string letters) {
    vector<int> count(26);
    for (auto c: letters) {
        ++count[c - 'A'];
    }

    vector<int> digits(10);
    digits[0] = count['Z' - 'A'];
    count['Z' - 'A'] -= digits[0];
    count['E' - 'A'] -= digits[0];
    count['R' - 'A'] -= digits[0];
    count['O' - 'A'] -= digits[0];

    digits[2] = count['W' - 'A'];
    count['T' - 'A'] -= digits[2];
    count['W' - 'A'] -= digits[2];
    count['O' - 'A'] -= digits[2];

    digits[4] = count['U' - 'A'];
    count['F' - 'A'] -= digits[4];
    count['O' - 'A'] -= digits[4];
    count['U' - 'A'] -= digits[4];
    count['R' - 'A'] -= digits[4];


    digits[6] = count['X' - 'A'];
    count['S' - 'A'] -= digits[6];
    count['I' - 'A'] -= digits[6];
    count['X' - 'A'] -= digits[6];

    digits[3] = count['R' - 'A'];
    count['T' - 'A'] -= digits[3];
    count['H' - 'A'] -= digits[3];
    count['R' - 'A'] -= digits[3];
    count['E' - 'A'] -= 2 * digits[3];

    digits[1] = count['O' - 'A'];
    count['O' - 'A'] -= digits[1];
    count['N' - 'A'] -= digits[1];
    count['E' - 'A'] -= digits[1];

    digits[5] = count['F' - 'A'];
    count['F' - 'A'] -= digits[5];
    count['I' - 'A'] -= digits[5];
    count['V' - 'A'] -= digits[5];
    count['E' - 'A'] -= digits[5];

    digits[7] = count['V' - 'A'];
    count['S' - 'A'] -= digits[7];
    count['V' - 'A'] -= digits[7];
    count['N' - 'A'] -= digits[7];
    count['E' - 'A'] -= 2 * digits[7];

    digits[8] = count['G' - 'A'];
    count['E' - 'A'] -= digits[8];
    count['I' - 'A'] -= digits[8];
    count['G' - 'A'] -= digits[8];
    count['H' - 'A'] -= digits[8];
    count['T' - 'A'] -= digits[8];

    digits[9] = count['I' - 'A'];
    count['N' - 'A'] -= digits[9];
    count['I' - 'A'] -= digits[9];
    count['N' - 'A'] -= digits[9];
    count['E' - 'A'] -= digits[9];

    for (int i = 0; i < 26; ++i) {
        assert(count[i] == 0);
    }

    string out;
    for (int d = 0; d < 10; ++d) {
        for (int i = 0; i < digits[d]; ++i)
            out.push_back((char)(d + '0'));
    }
    return out;
}

int main() {
     // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;

    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        string s;
        cin >> s;
        auto res = foo(s);
        cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
