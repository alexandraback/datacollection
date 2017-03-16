#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(long long i=(A); i<(B); i++)
#define REP(i, N) for(long long i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

LL B, M;
int edges[51][51];

int main()
{
    int T;
    cin >> T;
    REP(caso, T) {
        cout << "Case #" << caso+1 << ": ";

        cin >> B >> M;
        CLEAR(edges);

        if(M > (1LL<<(B-2))) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        FOR(i, 1, B) {
            FOR(j, i+1, B) {
                edges[i][j] = 1;
            }
        }

        if(M == (1LL<<(B-2))) {
            FOR(i, 1, B) edges[0][i] = 1;
        } else {
            REP(i, 61) {
                if(M&(1LL<<i)) {
                    edges[0][B-2-i] = 1;
                }
            }
        }
        cout << "POSSIBLE\n";
        REP(i, B) {
            REP(j, B) {
                cout << edges[i][j];
            }
            cout << endl;
        }
    }
}
