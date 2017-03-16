#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }

int unit = 1;

int x, y;

void N() { y -= unit; unit++; fputc('N', stdout); }
void S() { y += unit; unit++; fputc('S', stdout); }
void E() { x -= unit; unit++; fputc('E', stdout); }
void W() { x += unit; unit++; fputc('W', stdout); }


int main() {
    int TC;
    cin >> TC;
    FOR (t, 1, TC+1) {
        cin >> x >> y;
        printf("Case #%d: ", t);
        unit = 1;
        while (y >= unit) N();
        while (y <= -unit) S();
        while (x >= unit) E();
        while (x <= -unit) W();
        while (y > 0) { S(); N(); }
        while (y < 0) { N(); S(); }
        while (x > 0) { W(); E(); }
        while (x < 0) { E(); W(); }
        printf("\n");
    }
    return 0;
}

