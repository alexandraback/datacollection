#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int a[40];
int v;
uint32_t initial;

uint32_t add_denom(uint32_t pos, int val) {
    uint32_t next = pos;
    for (int s = 0; s <= v; s++)
        if ((pos & (1 << s)) and s + val <= v)
            next |= 1 << (s + val);
    return next;
}

int solve(int id, uint32_t pos) {
    if (id > v) {
        // assert(pos == ((1 << (v + 1)) - 1));
        return 0;
    }
    if (initial & (1 << id))
        return solve(id + 1, pos);
    int ans = 1 + solve(id + 1, add_denom(pos, id));
    if (pos & (1 << id))
        ans = min(ans, solve(id + 1, pos));
    return ans;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int c, d;
        scanf("%d%d%d", &c, &d, &v);
        assert(c == 1);
        initial = 0;
        for (int i = 0; i < d; i++) {
            scanf("%d", &a[i]);
            initial |= 1 << a[i];
        }
        uint32_t pos = 1;
        for (int i = 0; i < d; i++)
            pos = add_denom(pos, a[i]);
        // for (int i = 1; i <= v; i++)
        //     if (pos & (1 << i)) printf("%d ", i);
        printf("Case #%d: %d\n", cs, solve(1, pos));
    }
}
