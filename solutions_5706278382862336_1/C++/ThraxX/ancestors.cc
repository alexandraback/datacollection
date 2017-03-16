#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

#define DBG(z) cerr << #z << ": " << (z) << endl
#define NEWL cerr << endl
#define passert(x, m) {if (!(x)) {cerr << m << "  ::  ";} assert(x);}
#define err(s) cerr << "[92m" << s << "[0m" << endl
#define LINE cerr << "DEBUG LINE: " << __LINE__ << endl

#define IT(v) __typeof((v).begin())
#define mem(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define for_each(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define next_int() ({int __t; scanf("%d", &__t); __t;})

int main() {
    int T = next_int();
    for (int kase = 1; kase <= T; ++kase) {
        long long P, Q;
        scanf("%lld/%lld", &P, &Q);

        long long r = __gcd(P, Q);
        P /= r, Q /= r;
        printf("Case #%d: ", kase);
        bool impossible = true;
        if ((Q & (Q - 1)) == 0 && P > 0) {
            int r = 0;
            //while ((tmp & (tmp - 1)) != 0) tmp -= tmp & -tmp;
            while (Q > 0) Q >>= 1, ++r;
            while ((P & (P - 1)) != 0) P -= P & -P;
            while (P > 0 && (P & 1) == 0) P >>= 1, --r;
            --r;
            printf("%d", r);
            impossible = false;
        }
        if (impossible)
            printf("impossible");
        printf("\n");
    }
}

