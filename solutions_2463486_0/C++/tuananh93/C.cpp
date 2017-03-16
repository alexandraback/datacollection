#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int core[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22};
int num = 11;
int L, R;
int cs[100], ncs;

int check(int x) {
    if (x < L || R < x) return 0;

    ncs = 0;

    while (x) {
        cs[++ncs] = x % 10;
        x /= 10;
    }


    for (int i = 1; i <= ncs; i++)
        if (cs[i] != cs[ncs + 1 - i]) return 0;

    return 1;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int ntest;
    cin >> ntest;
    for (int test = 1; test <= ntest; test++) {
        cout << "Case #" << test << ": ";

        cin >> L >> R;
        int res = 0;
        for (int i = 0; i < num; i++)
            res += check(core[i] * core[i]);
        cout << res << endl;
    }

}
