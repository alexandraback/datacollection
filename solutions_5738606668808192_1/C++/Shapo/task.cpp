#include <bits/stdc++.h>

using namespace std;

#define ve vector

typedef int64_t ll;

bool
checker(const string &x, const ve< ll > &divs)
{
    for (int i = 2; i <= 10; ++i) {
        ll base = i;
        ll cur_div = divs[i - 2];
        ll num = 0;
        for (auto c : x) {
            num = (num * base + (c - '0')) % cur_div;
        }
        if (num) {
            return false;
        }
    }
    return true;
}

ll
get_div(ll x)
{
    for (ll v = 2; v * v <= x; ++v) {
        if (x % v == 0) {
            return v;
        }
    }
    return -1;
}

ve< ll >
get_divs(const string &s)
{
    ve< ll > res(9, -1);
    for (int base = 2; base <= 10; ++base) {
        int i = base - 2;
        ll x = 0;
        for (char c : s) {
            x = x * base + (c - '0');
        }
        res[i] = get_div(x);
        if (res[i] == -1) {
            return ve< ll >(1, -1);
        }
    }
    return res;
}

int
main()
{
    int t;
    scanf("%d", &t);
    int n, j;
    scanf("%d%d", &n, &j);
    printf("Case #1:\n");
    if (n == 16) {
        for (int mask = (1 << 15) + 1, cnt = 0; cnt < j; mask += 2) {
            string val(16, '0');
            int num = mask, pos = 0;
            while (num) {
                val[pos++] = num % 2 + '0';
                num /= 2;
            }
            reverse(val.begin(), val.end());
            auto divs = get_divs(val);
            if (divs[0] != -1) {
                printf("%s", val.c_str());
                for (ll x : divs) {
                    printf(" %d", int(x));
                }
                ++cnt;
                puts("");
                cerr << checker(val, divs) << endl;
            }
        }
    } else { // n == 32
        ve< ll > divs(9);
        for (int i = 2; i <= 10; ++i) {
            divs[i - 2] = i + 1;
        }
        set< string > ans;
        string temp(32, '0');
        temp[0] = temp[31] = temp[16] = temp[15] = '1';
        for (int cnt = 0; cnt < j; ++cnt) {
            int mask = cnt * 4;
            string val = temp;
            int pos = 0;
            while (mask) {
                if (mask & 1) {
                    val[pos] = '1';
                    val[pos + 15] = '1';
                }
                mask /= 2;
                pos++;
            }
            reverse(val.begin(), val.end());
            ans.insert(val);
        }
        if (int(ans.size()) != j) {
            cerr << "Hui" << endl;
        } else {
            cerr << "ok different" << endl;
        }
        for (const auto &s : ans) {
            printf("%s", s.c_str());
            for (const auto &v : divs) {
                printf(" %d", int(v));
            }
            puts("");
            cerr << checker(s, divs) << endl;
        }
    }
    return 0;
}
