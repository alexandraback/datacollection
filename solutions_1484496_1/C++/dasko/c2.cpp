#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <tr1/unordered_map>
#include <ctime>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;
using namespace tr1;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

vector<LL> c;

LL rnd() {
    LL res = rand(); res <<= 31;
    res += rand();
    return res;
}

LL get(LL mask) {
    LL res = 0LL;
    while (mask > 0) {
        res += c[__builtin_ctzll(mask)];
        mask -= mask & (-mask);
    }
    return res;
}

void print(LL mask) {
    while (mask > 0) {
        printf("%lld ", c[__builtin_ctzll(mask)]);
        mask -= mask & (-mask);
    }
    puts("");
}

int main(void) {
    int T; scanf("%d", &T); srand(time(NULL));
    FOR (t, 1, T + 1) {
        int n; scanf("%d", &n);
        c.clear(); 
        REP (i, n) {
            LL x; scanf("%lld", &x);
            c.PB(x);
        }
        int rr = 1 + rand() % 100;
        REP (i, rr)
            random_shuffle(ALL(c));
        while (SZ(c) > 62)
            c.pop_back();
        unordered_map<LL, LL> H;
        LL rA, rB;
        while (1) {
            LL mask = rnd(), val = get(mask);
            unordered_map<LL, LL>::iterator it = H.find(val);
            if (it == H.end())
                H[val] = mask;
            else {
                rA = mask;
                rB = it->second;
                break;
            }
        }
        fprintf(stderr, "%d\n", t);
        assert(rA != rB && get(rA) == get(rB));
        printf("Case #%d:\n", t);
        print(rA); print(rB);
    }
    return 0;
}
