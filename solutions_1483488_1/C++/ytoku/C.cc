#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOREACH(i,c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
using namespace std;

char r[2000001];
int solve(int A, int B)
{
    int n = 0;
    memset(r, 0, sizeof(r));
    for (int x = A; x <= B; x++) {
        if (r[x]) continue;

        vector<int> recycles;
        // generates recycle numbers
        int length = 0, base = 1;
        for (int tmp = x; tmp != 0; tmp /= 10, base *= 10, length++);
        base /= 10;
        int tmp = x;
        REP (i, length) {
            if (tmp >= base && A <= tmp && tmp <= B) {
                recycles.push_back(tmp);
                r[tmp] = 1;
            }
            tmp = tmp/10 + base*(tmp%10);
        }
        // uniq recycle numbers
        sort(recycles.begin(), recycles.end());
        recycles.erase(unique(recycles.begin(), recycles.end()), recycles.end());
        // C(recycles.size(), 2)
        int npairs = recycles.size() * (recycles.size() - 1) / 2;
        n += npairs;
    }
    return n;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int _c = 1; _c <= T; _c++) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", _c, solve(A, B));
    }
    return 0;
}
