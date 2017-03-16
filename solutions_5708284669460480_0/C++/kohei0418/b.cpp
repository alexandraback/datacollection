#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(k,a,b) for(int k=(a); k < (b); k++)
#define FORE(k,a,b) for(int k=(a); k <= (b); k++)
#define REP(k,a) for(int k=0; k < (a); k++)

#define ALL(c) (c).begin(), (c).end()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define RANGE(lb, x, ub) ((lb) <= (x) && (x) < (ub))

#define dump(x) cerr << #x << ": " << (x) << endl;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-10;


int K, L, S; 
string keyboard, target;
int max_banana;

int dfs(string s) {
    if(s.size() == S) {
        int k = 0;
        for(int i = 0; i + L <= s.size(); i++) {
            if(s.substr(i, L) == target) {
                k++;
            }
        }

        max_banana = max(max_banana, k);
        return k;
    }

    int res = 0;
    REP(i, K) {
        res += dfs(s + keyboard[i]);
    }
    return res;
}


int main()
{
    int T; cin >> T;
    REP(tcase, T) {
        cin >> K >> L >> S;
        cin >> keyboard;
        cin >> target;

        max_banana = 0;
        double count = dfs("");
        double p = count / pow(K, S);
        double res = max_banana - p;

        //dump(max_banana); dump(count); dump(K); dump(L); dump(S);

        printf("Case #%d: %lf\n", tcase+1, res);
    }

    return 0;
}
