#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_p(int i)
{
    bool p = true;
    string s = to_string(i);
    int ix1 = 0, ix2 = s.length() - 1;
    while (ix2 > ix1) {
        if (s[ix1] != s[ix2]) {
            p = false;
            break;
        }
        ++ix1, --ix2;
    }
    return p;
}

pair<bool, int> is_s(int i)
{
    int sq = (int)sqrt(i + 1);
    if (sq * sq == i)
        return {true, sq};
    else
        return {false, sq};
}

bool fs(int i)
{
    if (!is_p(i))
        return false;
    auto p = is_s(i);
    if (!p.first)
        return false;
    int sq = p.second;
    if (!is_p(sq))
        return false;
    //cout << i << " " << sq << endl;
    return true;
}

int main()
{
    int T, tcnt = 0;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;
        int cnt = 0;
        for (int i = A; i <= B; ++i)
            if (fs(i))
                ++cnt;

        cout << "Case #" << ++tcnt << ": " << cnt << endl;
    }
}

