#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int maxn = 10000010;

char can[maxn];

bool palindrome(long long x)
{
    ostringstream ss;
    ss << x;
    string s = ss.str();
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length()-1-i]) return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    memset(can, 0, sizeof(can));
    for (long long k = 1; k < maxn; k++) {
        if (palindrome(k) && palindrome(k*k))
            can[k] = 1;
        can[k] += can[k-1];
    }

    int T;
    cin >> T;
    for (int sc = 1; sc <= T; sc++) {
        long long sqL, sqR;

        cin >> sqL >> sqR;

        long long L = sqrt(sqL+0.0);
        while (L*L >= sqL) L--;
        while (L*L < sqL) L++;

        long long R = sqrt(sqR+0.0);
        while (R*R <= sqR) R++;
        while (R*R > sqR) R--;

        cout << "Case #" << sc << ": ";
        if (L > R) cout << 0; else cout << can[R] - can[L-1];
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
}
