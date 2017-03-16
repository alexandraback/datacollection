#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int mote[200], t, a, n;
map<int, int> mem[200];

int rijesi(int k, long long current_size) {
    if(k == n) return 0;
    if( mem[k].count(current_size) > 0) return mem[k][current_size];
    if(mote[k] < current_size)
        return mem[k][current_size] = rijesi(++k, current_size + mote[k]);
    else {
        if( current_size - 1 > 0) {
            return mem[k][current_size] = min(
                       1 + rijesi(++k, current_size),
                       1 + rijesi(k, current_size + current_size - 1)
                       );
        } else {
            return mem[k][current_size]=  1 + rijesi(++k, current_size);
        }
    }
}

int main() {
    scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        for(int i = 0; i < 150; ++i) mem[i].clear();
        scanf("%d %d", &a, &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &mote[i]);
        sort(mote, mote+n);

        printf("Case #%d: %d\n", test+1, rijesi(0, a));
    }
    return 0;
}
