#include <string>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

const long long mx = std::numeric_limits<long long>::max();
long long best_res;
pair<string, string> best_strings;

using namespace std;

void rec(string c, string j) {
    int i=0,k=0;
    for (; i<c.size(); i++) {
        if (c[i] == '?') {
            for(int z = 0; z < 10; z++) {
                c[i] = char(z + 48);
                rec(c, j);
            }
            return;
        }
    }
    for (; k<j.size(); k++) {
        if (j[k] == '?') {
            for(int z = 0; z < 10; z++) {
                j[k] = char(z + 48);
                rec(c, j);
            }
            return;
        }
    }

    if(i == c.size() && k == j.size()) {
        long long res = abs(stoll(c) - stoll(j));
        if (best_res > res) {
            best_res = res;
            best_strings.first = c;
            best_strings.second = j;
        }
        else if (best_res == res) {
            if (stoll(best_strings.first) > stoll(c)) {
                best_strings.first = c;
                best_strings.second = j;
            }
            else if (stoll(best_strings.first) == stoll(c) &&
                 stoll(best_strings.second) > stoll(j)) {
                best_strings.first = c;
                best_strings.second = j;
            }
        }
    }
}

int main() {
    int T;
    string c, j;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> c;
        cin >> j;
        best_res = mx;
        rec(c, j);
        cout << "Case #" << i << ": ";
        cout << best_strings.first << " " << best_strings.second << endl;
    }
}