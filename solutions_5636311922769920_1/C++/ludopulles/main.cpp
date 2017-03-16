#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

//string extend(const string &s, const string &orig, const string &gold)
//{
//    string ret("");
//    for (char ch : s) {
//        if (ch == 'G') ret += gold;
//        else ret += orig;
//    }
//    return ret;
//}

//bool usedRows[100];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//    freopen("check.txt", "w", stderr);
#endif // LOCAL

    ll t, k, c, s;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        cin >> k >> c >> s;
        ll needed = (k + c - 1) / c; // ceil[k/c]
        if (needed <= s) {

            cout << "Case #" << tc << ":";
            ll base = 1, curnum = 0;
            for (ll num = 0; num < k; num++) {
                curnum += 1LL * num * base;
                base *= k;
                if ((num + 1) % c == 0 || num + 1 == k) {
                    cout << " " << (curnum + 1) ;
                    base = 1;
                    curnum = 0;
                }
            }
            cout << endl;
        } else {
            cout << "Case #" << tc << ": " << "IMPOSSIBLE" << endl;
        }
    }

    /*
    vector<string> strs;

    int t, k, c, s;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> k >> c >> s;

        for (ll num = 1; num < (1 << k); num <<= 1) {
            string str = "";
            ll nnum = num;
            for (int i = k; i--; ) {
                str = (nnum & 1 ? "G" : "L") + str;
                nnum /= 2;
            }

            string orig = str;
            string gold(orig.size(), 'G');
            for (int cc = c; --cc; ) {
                str = extend(str, orig, gold);
            }

            strs.push_back(str);
//            cout << orig << "\t" << str << endl;
        }

        for (unsigned int i = 0; i < strs[0].size(); i++) {
//            if (i % k == 0) cout << endl;
            for (string &ss : strs) {
                cout << ss[i];
            }
            cout << endl;

            int j = i;
            // bool *usedRows = new bool[k];
            fill_n(usedRows, k, false);

            for (int tt = c; tt--; ) {
                usedRows[j % k] = true;
                j /= k;
            }

            for (int l = 0; l < k; l++) {
                cerr << (usedRows[k - 1 - l] ? 'G' : 'L');
            }
            cerr << endl;

            delete[] usedRows;
        }
    }
    */
    return 0;
}
