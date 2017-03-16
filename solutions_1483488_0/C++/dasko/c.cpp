#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

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

int cnt(int a) {
    int res = 0;
    while (a > 0) {
        ++res;
        a /= 10;
    }
    return res;
}

char buf[110];

int main(void) {
    int T; scanf("%d", &T);
    FOR (t, 1, T + 1) {
        int A, B; scanf("%d%d", &A, &B);
        int len = cnt(A), res = 0;
        for (int i = A; i <= B; ++i) {
            sprintf(buf, "%d", i);
            VI x;
            FOR (j, 1, len) {
                buf[j + len - 1] = buf[j - 1];
                buf[j + len] = 0;
                int can; sscanf(buf + j, "%d", &can);
                if (can > i && can <= B)
                    x.PB(can);
            }
            sort(ALL(x));
            REP (j, SZ(x)) {
                if (j == 0 || x[j] != x[j - 1])
                    ++res;
            }
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}

        
