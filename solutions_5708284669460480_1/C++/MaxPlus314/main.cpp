#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    cout.precision(100), cout << fixed;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char c;
    int q, k, l, s, m, pr['Z' + 1], imp;
    long double p;
    string S;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> k >> l >> s;
        p = s - l + 1;
        memset(pr, 0, sizeof(pr));
        imp = 0;
        getchar();
        while (cin.peek() != '\n')
            ++pr[cin.get()];
        getchar(), S = "";
        while (cin.peek() != '\n' && cin.peek() != EOF)
            imp |= !pr[cin.peek()], p = p * pr[c = cin.get()] / k, S += c;
        for (m = S.size() - 1; m > 0; --m)
            if (S.substr(0, m) == S.substr(S.size() - m, m))
                break;
        m = (s - l) / (l - m) + 1;
        if (imp)
            m = 0;
        if (!(p > 0) && !(p == 0) && !(p < 0))
            p = 0;
        cout << "Case #" << i + 1 << ": " << max((long double)0, m - p) << '\n';
    }
    return 0;
}
