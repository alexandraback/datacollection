#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string s;
        cin >> s;
        int len = 0;
        char last = '$';
        for (char ch : s) {
            if (ch == last) continue;
            len++;
            last = ch;
        }
        cout << "Case #" << tc << ": " << (len - (last == '+')) << endl;
    }

    return 0;
}
