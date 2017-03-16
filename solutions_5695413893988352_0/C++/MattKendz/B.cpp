#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void recur(vector<int> &v, string number) {
    if (number.find('?') == string::npos) {
        v.push_back(stoi(number));
        return;
    }

    int index = number.find('?');
    for (char i = '0'; i <= '9'; i++) {
        recur(v, number.substr(0, index) + i + number.substr(index + 1));
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string first, last;
        cin >> first >> last;
        vector<int> one, two;
        recur(one, first);
        recur(two, last);

        int diff = INT_MAX, sum = INT_MAX;
        int ans1, ans2;

        for (int j = 0; j < one.size(); j++) {
            for (int k = 0; k < two.size(); k++) {
                if (abs(one[j] - two[k]) < diff || (abs(one[j] - two[k]) == diff && one[j] + two[k] < sum)) {
                    diff = abs(one[j] - two[k]);
                    sum = one[j] + two[k];
                    ans1 = one[j], ans2 = two[k];
                }
            }
        }

        cout << "Case #" << i + 1 << ": " << setfill('0') << setw(first.length()) << ans1 << " " << setfill('0') << setw(first.length()) << ans2 << endl;
    }

    return 0;
}