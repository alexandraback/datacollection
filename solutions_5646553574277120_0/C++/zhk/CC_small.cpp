#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)

typedef uint64_t i64;

int gC, gD, gV, gA[128];
i64 gMaskAll = 0;
int bit_cc(int v) {return v==0 ? 0 : bit_cc(v & (v-1)) + 1;}

bool do_it(int deep, i64 has, i64 all) {
    if (deep == 0) return all == gMaskAll;
    i64 revAll = gMaskAll & (~all);
    F1(i, gV) if (((has>>i)&1) == 0) {
        i64 tmp = ((revAll >> i) & all) << i;
        tmp &= gMaskAll;
        if (do_it(deep-1, has | (1L<<i), tmp | all | (1L<<i))) {
            // printf(">> %d\n", i);
            return true;
        }
    }
    return false;
}

int calc() {
    gMaskAll = 0;
    F1(i, gV) gMaskAll |= 1L<<i;
    i64 ALL = 0, HAS = 0;
    F0(i, gD) HAS |= 1L<<gA[i];
    int bitEnd = 1<<gD;
    F0(bit, bitEnd) {
        int val = 0;
        F0(i, gD) if ((bit>>i) & 1) val += gA[i];
        if (val > 0 && val <= gV) {
            ALL |= (1L<<val);
        }
    }
    if (gMaskAll == ALL) return 0;
    // cout << "check\n" << bitset<32>(gMaskAll) << endl << bitset<32>(ALL) << endl;
    int ans = 1;
    for(; !do_it(ans, HAS, ALL); ++ans);
    return ans;
}

int main(int argc, char *argv[]) {
    int T; scanf("%d", &T);
    F1(iT, T) {
        scanf("%d%d%d", &gC, &gD, &gV);
        F0(i, gD) scanf("%d", gA + i);
        // puts("OK");
        printf("Case #%d: %d\n", iT, calc());
    }
    return 0;
}
