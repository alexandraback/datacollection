#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sc, sc2;
int n, X;

// true if m is big enough
bool check(int num, double m)
{
    double left = 1 - m;
    double final = sc[num] + X * m;
    for (int i = 0; i < n - 1; ++i) {
        if (sc2[i] >= final)
            continue;
        left -= (final - sc2[i]) / (double)X;
        if (left < 0)
            return true;
    }
    return false;
}

int main(void)
{
    freopen("probA.in", "r", stdin);
    int __;
    cin >> __;
    for (int _ = 1; _ <= __; ++_) {
        sc.clear();
        sc2.clear();
        X = 0;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            sc.push_back(t);
            X += t;
        }
        printf("Case #%d:", _);

        for (int num = 0; num < n; ++num) {
            sc2 = sc;
            sc2.erase(sc2.begin() + num);
            sort(sc2.begin(), sc2.end(), greater<int>());

            double l = 0, r = 1, m;
            for (int ___ = 0; ___ < 100; ++___) {
                m = (l + r) / 2;
                if (check(num, m))
                    r = m;
                else
                    l = m;
            }
            printf(" %.10f", m * 100);
        }

        puts("");
    }
}
