#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string mul(const string& lhs, const string& rhs)
{
    string r(101, '0');

    for (int i = 0; i < lhs.length(); i++) {
        int d0 = lhs[i] - '0';
        for (int j = 0; j < rhs.length(); j++) {
            int ri = i + j;
            int d1 = rhs[j] - '0';
            int v = d0 * d1 + r[ri] - '0';
            int c = v / 10;
            r[ri] = '0' + v % 10;
            while (c) {
                ri++;
                v = r[ri] - '0' + c;
                c = v / 10;
                r[ri] = '0' + v % 10;
            }
        }
    }
    reverse(r.begin(), r.end());
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<string> pq_tab;

    pq_tab.push_back(mul("1", "1"));
    pq_tab.push_back(mul("2", "2"));
    pq_tab.push_back(mul("3", "3"));

    for (int i = 0; i < 25; i++) {
        string s2 = "2" + string(i, '0');
        string r = s2;
        reverse(r.begin(), r.end());
        
        pq_tab.push_back(mul(s2 + r, s2 + r));
        pq_tab.push_back(mul(s2 + "0" + r, s2 + "0" + r));
        pq_tab.push_back(mul(s2 + "1" + r, s2 + "1" + r));

        for (int j = 0; j < 4 && j <= i; j++) {
            string s1 = string(i - j, '0') + string(j, '1');
            do {
                string s = "1" + s1;
                string r = s;
                reverse(r.begin(), r.end());

                pq_tab.push_back(mul(s + r, s + r));
                pq_tab.push_back(mul(s + "0" + r, s + "0" + r));
                pq_tab.push_back(mul(s + "1" + r, s + "1" + r));

                if (j < 2) {
                    pq_tab.push_back(mul(s + "2" + r, s + "2" + r));
                }
            } while (next_permutation(s1.begin(), s1.end()));
        }
    }
    sort(pq_tab.begin(), pq_tab.end());

    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        string l0, r0;
        cin >> l0 >> r0;
        string l = string(101 - l0.length(), '0') + l0;
        string r = string(101 - r0.length(), '0') + r0;

        vector<string>::const_iterator li = lower_bound(pq_tab.begin(), pq_tab.end(), l);
        vector<string>::const_iterator ri = upper_bound(pq_tab.begin(), pq_tab.end(), r);

        cout << "Case #" << i << ": " << distance(li, ri) << endl;
    }
}
