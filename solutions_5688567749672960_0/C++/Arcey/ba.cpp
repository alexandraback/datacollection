#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int v[7] = {0, 1, 11, 30, 139, 338, 1437};

long long f(long long a) {
    if (a % 10 == 0)
        return 1 + f(a - 1);

    long long ans = 0;
    int c[14], nc = 0;

    while (a > 0) {
        c[nc++] = a % 10;
        a /= 10;
    }

    long long l, r;
    l = r = 0;
    for (int i = (nc + 1) / 2; i < nc; i++)
        l = l * 10 + c[i];
    for (int i = (nc / 2) - 1; i >= 0; i--)
        r = r * 10 + c[i];
    ans += v[nc];
    if (nc % 2 == 1)
        ans += c[nc / 2] * (long long) pow(10, nc / 2);
    if (l != 1)
        ans += (l - 1) + (r - 1) + 1;
    else
        ans += (r - 1);
    return ans;
}

int main() {
    ifstream fi("a.in");
    ofstream fo("a.out");

    int totaltest;
    fi >> totaltest;
    for (int test = 1; test <= totaltest; test++) {
        long n;
        fi >> n;
        fo << "Case #" << test << ": " << f(n) << endl;
    }

    return 0;
}
