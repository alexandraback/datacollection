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

    const char fake[] = "abcdefghijklmnopqrstuvwxyz";
    const char perm[] = "yhesocvxduiglbkrztnwjpfmaq";

    int testCount;
    cin >> testCount;
    string line;
    getline(cin, line);
    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
    	getline(cin, line);
    	for (int i = 0; i < line.length(); ++i) {
    		if (line[i] == ' ') continue;
    		line[i] = perm[line[i] - 'a'];
    	}
        cout << "Case #" << testNumber << ": " << line << endl;
    }

    return 0;
}

//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <bitset>
//#include <set>
//#include <sstream>
//#include <stdlib.h>
//#include <map>
//#include <queue>
//#include <assert.h>
//
//using namespace std;
//
//#define sz(x) ((int)x.size())
//#define all(x) (x).begin(), (x).end()
//#define pb(x) push_back(x)
//#define mp(x, y) make_pair(x, y)
//
//#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)
//
//#define debug(x) cout << '>' << #x << ':' << x << endl;
//
//typedef long long int64;
//
//typedef vector <int> vi;
//typedef vector < vi > vvi;
//
//bool bit(int64 mask, int k) {
//    return ((1LL << k) & mask) != 0;
//}
//
//int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};
//
//int get(char c, bool b) {
//    switch (c) {
//        case '-':
//            return b ? 0 : 4;
//        case '|':
//            return b ? 2 : 6;
//        case '/':
//            return b ? 1 : 5;
//        case '\':
//            return b ? 3 : 7;
//    }
//    return -1;
//}
//
//int main() {
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//
//    int testCount;
//    cin >> testCount;
//    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
//        cerr << "Case #" << testNumber << "..." << endl;
//
//        int n, m;
//        cin >> n >> m;
//        vector<string> table(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> table[i];
//        }
//
//        for (int64 mask = 0; mask < (1LL << (n * m)); ++mask) {
//            vvi use(n, vi(m));
//            for (int i = 0; i < n; ++i) {
//                for (int j = 0; j < m; ++j) {
//                    int k = get(table[i][j], bit(mask, m * i + j
//                }
//            }
//        }
//        res %= 1000003;
//
//        /*printf("Case #%d:\n", testNumber);
//        for (int i = 0; i < sz(res); ++i) {
//            printf("%.8lf\n", res[i]);
//        }*/
//        cout << "Case #" << testNumber << ": " << res << endl;
//    }
//
//    return 0;
//}
