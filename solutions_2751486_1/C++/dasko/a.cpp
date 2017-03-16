#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

const int MAXL = 1000100;
char c[MAXL], wov[] = "aeiou";

bool cons(char a) {
    REP (i, 5) {
        if (a == wov[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int K; scanf("%s%d", c, &K);
        int n = strlen(c);
        int last = -1, cur = 0;
        LL res = 0LL;
        REP (i, n) {
            if (cons(c[i])) {
                ++cur;
            } else {
                cur = 0;
            }
            if (cur >= K) {
                last = i;
            }
            if (last != -1) {
                res += last - K + 2;
            }
        }
        printf("Case #%d: %lld\n", t, res);
    }
    return 0;
}


