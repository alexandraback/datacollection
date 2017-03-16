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

char str[1000];

bool isvowel(char ch) {
    return (ch == 'a')
    || (ch == 'e')
    || (ch == 'i')
    || (ch == 'o')
    || (ch == 'u');
}

bool iscons(char ch) {
    return isalpha(ch) && !isvowel(ch);
}

int main() {
    int TC;
    cin >> TC;
    FOR (t, 1, TC+1) {
        int n;
        scanf("%s %d\n", str, &n);
        int maincount = 0;
        int len = strlen(str);
        FOR (i,0,len) {
            FOR (j,i+n,len+1) {
                int c = 0;
                FOR (x, i, j) {
                    if (iscons(str[x])) c++;
                    else c = 0;
                    if (c >= n) {
                        maincount++;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", t, maincount);
    }
    return 0;
}

