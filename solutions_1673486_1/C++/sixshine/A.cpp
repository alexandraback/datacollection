#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <list>
#include <functional>
#include <utility>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h);i>(l);--i)
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ifstream cin("D:\\in.txt");
    ofstream cout("D:\\out.txt");
//    freopen("D:\\in.txt", "r", stdin);
//    freopen("D:\\out.txt", "w", stdout);
    int T, A, B;
    cin >> T;
    REP(i, T) {
        cin >> A >> B;
        VD P(A + 1);
        P[0] = 1;
        REP(j, A) {
            double prob;
            cin >> prob;
            P[j + 1] = P[j] * prob;
        }
        double ans = B + 2;
        REP(j, A+1) {
            double exp = P[A - j] * (B - A + 1 + j * 2)
                    + (1 - P[A - j]) * (B - A + 1 + j * 2 + B + 1);
            if (exp < ans) {
                ans = exp;
            }
        }
        cout << "Case #" << i + 1 << ": " << setiosflags(ios::fixed)
                << setprecision(6) << ans << endl;
    }
    return 0;
}
