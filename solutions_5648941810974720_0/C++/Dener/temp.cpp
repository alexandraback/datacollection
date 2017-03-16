#include <bits/stdc++.h>

using namespace std;

void solve(int testnum)
{
    string s;
    cin >> s;
    map<int, int> cnt;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]]++;
    }
    int res[10];
    memset(res, 0, sizeof(res));

    auto sub = [&](string s, int k) {
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]] -= k;
        }
    };

    res[0] = cnt['Z'];
    sub("ZERO", res[0]);
    res[8] = cnt['G'];
    sub("EIGHT", res[8]);
    res[2] = cnt['W'];
    sub("TWO", res[2]);
    res[4] = cnt['U'];
    sub("FOUR", res[4]);
    res[6] = cnt['X'];
    sub("SIX", res[6]);
    res[1] = cnt['O'];
    sub("ONE", res[1]);
    res[3] = cnt['T'];
    sub("THREE", res[3]);
    res[5] = cnt['F'];
    sub("FIVE", res[5]);
    res[7] = cnt['S'];
    sub("SEVEN", res[7]);
    res[9] = cnt['I'];

    cout << "Case #" << testnum + 1 << ": ";
    for (int i = 0; i < 10; i++) {
//         cerr << res[i] << ' ' ;
        for (int j = 0; j < res[i]; j++) {
            cout << char('0' + i);
        }
    }
    cout << endl;
}

int main()
{
    int T;
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int testnum = 0; testnum < T; testnum++) {
        solve(testnum);
    }
}
