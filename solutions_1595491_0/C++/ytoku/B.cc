#include <cstdio>
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOREACH(i,c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int _c = 1; _c <= T; _c++) {
        int N, S, p;
        scanf("%d %d %d", &N, &S, &p);

        int y = 0;
        REP(i, N) {
            int t;
            scanf("%d", &t);
            if (t >= 3*p-2)
                y++;
            else if (S > 0 && t >= 2 && 3*p-4 <= t && t < 3*p-2)
                S--, y++;
        }

        printf("Case #%d: %d\n", _c, y);
    }
    return 0;
}
