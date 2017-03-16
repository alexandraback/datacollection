#include <cstdio>
#include <algorithm>

using namespace std;

int mote[200], t, a, n;

int rijesi(int k, int current_size) {
    if(k == n) return 0;
    if(mote[k] < current_size)
        return rijesi(++k, current_size + mote[k]);
    else {
        if( current_size - 1 > 0) {
            return min(
                       1 + rijesi(++k, current_size),
                       1 + rijesi(k, current_size + current_size - 1)
                       );
        } else {
            return 1 + rijesi(++k, current_size);
        }
    }
}

int main() {
    scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        scanf("%d %d", &a, &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &mote[i]);
        sort(mote, mote+n);

        printf("Case #%d: %d\n", test+1, rijesi(0, a));
    }
    return 0;
}
