#include <cassert>
#include <cstdio>

#include <algorithm>
#include <set>
using namespace std;

int digit_count(int n) {
    int cnt = 0;
    do {
        ++cnt;
        n /= 10;
    } while (n > 0);
    return cnt;
}

int main() {
    assert(freopen("C.in", "r", stdin));
    assert(freopen("C.out", "w", stdout));

    int T; assert(scanf("%d", &T) == 1);

    for (int test = 1; test <= T; ++test) {
        int A, B;
        assert(scanf("%d %d", &A, &B) == 2);

        int n = digit_count(A);
        int power = 1;
        for (int i = 2; i <= n; ++i)
            power *= 10;
        
        set< pair<int, int> > mySet;

        for (int i = A; i <= B; ++i) {
            int val = i;
            int initial = val;
            for (int stp = 1; stp < n; ++stp) {
                int last_digit = val % 10;
                val /= 10;
                val += last_digit * power;
                if (A <= val && val <= B && val < initial) {
                    mySet.insert(make_pair(val, initial));
                }
            }
        }

        printf("Case #%d: %d\n", test, mySet.size());
    }
}
