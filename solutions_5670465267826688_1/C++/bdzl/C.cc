#include <bits/stdc++.h>
using namespace std;

int FromReprToInt(char repr)
{
    if (repr == '1') {
        return 0;
    }
    if (repr == 'i') {
        return 1;
    }
    if (repr == 'j') {
        return 2;
    }
    if (repr == 'k') {
        return 3;
    }
}

const int kNextVal[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

const int kNextSign[4][4] = {
    {+1, +1, +1, +1},
    {+1, -1, +1, -1},
    {+1, -1, -1, +1},
    {+1, +1, -1, -1}
};

struct Quaternion
{
    int sign;
    int val;

    Quaternion() :
        sign(+1),
        val(0)
    {
    }

    Quaternion(int sign, int val) :
        sign(sign),
        val(val)
    {
    }

    Quaternion(int sign, char val_repr) :
        sign(sign),
        val(FromReprToInt(val_repr))
    {
    }
};

Quaternion operator * (const Quaternion& lhs,
                       const Quaternion& rhs)
{
    return Quaternion(lhs.sign * rhs.sign * kNextSign[lhs.val][rhs.val],
                      kNextVal[lhs.val][rhs.val]);
}

bool operator == (const Quaternion& lhs,
                  const Quaternion& rhs)
{
    return lhs.sign == rhs.sign && lhs.val == rhs.val;
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        int len;
        long long amount;
        cin >> len >> amount;
        string s;
        cin >> s;
        Quaternion all(+1, '1');
        for (int i = 0; i < len; ++i) {
            all = all * Quaternion(+1, s[i]);
        }
        vector<Quaternion> q;
        q.push_back(Quaternion(+1, '1'));
        while (true) {
            Quaternion nxt = q.back() * all;
            bool found = false;
            for (const auto& x : q) {
                if (x == nxt) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                q.push_back(nxt);
            } else {
                break;
            }
        }
        int max_r = q.size();
        if (!(q[amount % max_r] == Quaternion(-1, '1'))) {
            cout << "NO" << endl;
            continue;
        }
        long long min_len_left = 1LL * len * amount;
        Quaternion cur_left = Quaternion(+1, '1');
        for (int i = 0; i < len; ++i) {
            cur_left = cur_left * Quaternion(+1, s[i]);
            for (int ir = 0; ir < max_r; ++ir) {
                if (q[ir] * cur_left == Quaternion(+1, 'i')) {
                    min_len_left = min(min_len_left, (long long) len * ir + i + 1);
                }
            }
        }
        long long min_len_right = len * amount;
        Quaternion cur_right = Quaternion(+1, '1');
        for (int i = len - 1; i >= 0; --i) {
            cur_right = Quaternion(+1, s[i]) * cur_right;
            for (int ir = 0; ir < max_r; ++ir) {
                if (cur_right * q[ir] == Quaternion(+1, 'k')) {
                    min_len_right = min(min_len_right, (long long) len * ir + len - i);
                }
            }
        }
        if (min_len_left + min_len_right < len * amount) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
