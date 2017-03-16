#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, char> op;

const int maxl = 1e4 + 5;

int cases, l;
long long x;
char s[20 * maxl];

op signAndResult(op x, op y) {
    int sign = x.first * y.first;
    char product = 'x';
    switch (x.second) {
    case 'i':
        if (y.second == 'i') {
            product = 'x';
            sign *= -1;
        }
        else if (y.second == 'j') {
            product = 'k';
        }
        else if (y.second == 'k') {
            product = 'j';
            sign *= -1;
        }
        else /* y.second == 'x' */ {
            product = 'i';
        }
        break;
    case 'j':
        if (y.second == 'i') {
            product = 'k';
            sign *= -1;
        }
        else if (y.second == 'j') {
            product = 'x';
            sign *= -1;
        }
        else if (y.second == 'k') {
            product = 'i';
        }
        else /* y.second == 'x' */ {
            product = 'j';
        }
        break;
    case 'k':
        if (y.second == 'i') {
            product = 'j';
        }
        else if (y.second == 'j') {
            product = 'i';
            sign *= -1;
        }
        else if (y.second == 'k') {
            product = 'x';
            sign *= -1;
        }
        else /* y.second == 'x' */ {
            product = 'k';
        }
        break;
    case 'x':
        if (y.second == 'i') {
            product = 'i';
        }
        else if (y.second == 'j') {
            product = 'j';
        }
        else if (y.second == 'k') {
            product = 'k';
        }
        else /* y.second == 'x' */ {
            product = 'x';
        }
        break;
    }
    return make_pair(sign, product);
}

int my_min(int x, long long y) {
    if (y < (long long)x) return (int)y;
    return x;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    scanf("%d", &cases);
    int counter = 0;
    while (cases--) {
        counter++;

        scanf("%d %lld", &l, &x);
        scanf("%s", s);

        for (int i = l; i < my_min(20, x) * l; i++) s[i] = s[i - l];
        int new_l = my_min(20, x) * l;

        // try to get first i
        int left_limit_i = 0;
        int limit_i = -1;
        op curr = make_pair(1, 'x');
        for (int i = 0; i < new_l; i++) {
            curr = signAndResult(curr, make_pair(1, s[i]));
            if (curr == make_pair(1, 'i')) {
                limit_i = i;
                break;
            }
        }
        if (limit_i == -1) {
            printf("Case #%d: NO\n", counter);
            continue;
        }

        // try to get next j
        int left_limit_j = limit_i + 1;
        int limit_j = -1;
        curr = make_pair(1, 'x');
        for (int i = left_limit_j; i < new_l; i++) {
            curr = signAndResult(curr, make_pair(1, s[i]));
            if (curr == make_pair(1, 'j')) {
                limit_j = i;
                break;
            }
        }
        if (limit_j == -1) {
            printf("Case #%d: NO\n", counter);
            continue;
        }

        // try to get next k
        int left_limit_k = limit_j + 1;
        int limit_k = -1;
        curr = make_pair(1, 'x');
        for (int i = left_limit_k; i < new_l; i++) {
            curr = signAndResult(curr, make_pair(1, s[i]));
            if (curr == make_pair(1, 'k')) {
                limit_k = i;
                break;
            }
        }
        if (limit_k == -1) {
            printf("Case #%d: NO\n", counter);
            continue;
        }

        op rest = make_pair(1, 'x');
        for (int i = limit_k + 1; i < new_l; i++)
            rest = signAndResult(rest, make_pair(1, s[i]));

        x -= my_min(20, x);
        op full = make_pair(1, 'x');
        if (x > 0) {
            for (int i = 0; i < l; i++)
                full = signAndResult(full, make_pair(1, s[i]));

            vector<op> fullTimes;
            fullTimes.push_back(full);
            // won't go more then 5 times
            for (int i = 2; i <= x; i++) {
                op next = signAndResult(fullTimes.back(), full);
                if (next == fullTimes[0]) break;
                fullTimes.push_back(next);
            }

            x %= fullTimes.size();
            op new_full = make_pair(1, 'x');
            for (int i = 1; i <= x; i++)
                new_full = signAndResult(new_full, full);
            full = new_full;
        }

        if (signAndResult(rest, full) == make_pair(1, 'x'))
            printf("Case #%d: YES\n", counter);
        else printf("Case #%d: NO\n", counter);
    }
}
