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

char perm[] = "yhesocvxduiglbkrztnwjpfmaq", buf[310];

int main(void) {
    int T; scanf("%d\n", &T);
    FOR (t, 1, T + 1) {
        gets(buf);
        int n = strlen(buf);
        printf("Case #%d: ", t);
        REP (i, n) {
            if (buf[i] >= 'a' && buf[i] <= 'z')
                putchar(perm[buf[i] - 'a']);
            else
                putchar(buf[i]);
        }
        puts("");
    }
    return 0;
}


