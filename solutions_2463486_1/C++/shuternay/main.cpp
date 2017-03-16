#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool isPalindrom(long long n) {
    vector <short> c;
    while (n) {
        c.push_back((short) (n % 10ll));
        n /= 10ll;
    }

    for (int i = 0; i < c.size() / 2; ++i)
        if (c[i] != c[c.size() - 1 - i])
            return false;

    return true;
}

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector <long long> v;
    for (long long i = 1; i * i <= (1000000ll * 1000000ll * 100ll); ++i)
        if (isPalindrom(i) && isPalindrom(i * i))
            v.push_back(i * i);

    long T;
    cin >> T;

    for (long t = 0; t < T; ++t) {
        long long a, b;
        long ans = 0;
        cin >> a >> b;
        for (long i = 0; i <= v.size(); ++i)
            if (a <= v[i] && v[i] <= b)
                ans++;

        printf("Case #%ld: %ld\n", t + 1, ans);
    }

}