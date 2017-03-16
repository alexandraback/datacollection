#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;

bool isCons(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

vector <pair<int, int> > getConsSubstrings(string name, int n) {
    vector <pair<int, int> > result;
    bool streak = false;
    int start = -1, end = -1;
    for (int i = 0; i <= name.length(); ++i) {
        if (i < name.length() && isCons(name[i])) {
            if (streak) {
                end = i;
            } else {
                start = end = i;
                streak = true;
            }
        } else {
            if (streak) {
                if (end - start + 1 >= n) {
                    result.push_back(make_pair(start, end));
                }
            }
            streak = false;
        }
    }
    return result;
}

int main() {
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        string name;
        int n;
        cin >> name >> n;
        vector <pair<int, int> > substrs = getConsSubstrings(name, n);

        int prev = 0;
        int answ = 0;
        for (int i = 0; i < substrs.size(); ++i) {
//            cout << substrs[i].first << ' ' << substrs[i].second << '\n';
            int a = substrs[i].first - prev + 1;
            int k = substrs[i].second - substrs[i].first + 1 - n;
            int b = name.length() + k - substrs[i].second;
//            cout << "a=" << a << " b=" << b << " k=" << k << '\n';
            answ += (a + k) * b - k * (k + 1) / 2;
            prev = substrs[i].second - n + 2;
        }
        cout << "Case #" << test << ": " << answ << '\n';
    }
}