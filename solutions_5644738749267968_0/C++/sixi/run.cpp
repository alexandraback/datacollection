#include <iostream>
#include <vector>
using namespace std;

void printOutput(int idx, string text) {
    cout << "Case #" << idx << ": " << text << endl;
}

void show(const vector<double>& num) {
    cout << '[';
    for (int i = 0; i < num.size(); ++i) {
        if (i != 0) {
            cout << ',';
        }
        cout << num[i];
    }
    cout << ']';
}

void handleCase(int idx) {
    int n, result_1, result_2;
    double tmp;
    cin >> n;
    vector<double> naomi;
    vector<double> ken;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        naomi.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ken.push_back(tmp);
    }
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());
    // show(naomi);
    // cout << endl;
    // show(ken);
    // cout << endl;

    int i = n - 1;
    int j = n - 1;
    result_1 = 0;
    for (; i >= 0; --i) {
        while (true) {
            if (naomi[i] > ken[j]) {
                ++result_1;
                --j;
                break;
            } else {
                --j;
            }
            if (j == -1) {
                break;
            }
        }
        if (j == -1) {
            break;
        }
    }

    i = 0;
    j = 0;
    result_2 = n;
    for (; i < n; ++i) {
        while (true) {
            if (ken[j] > naomi[i]) {
                --result_2;
                ++j;
                break;
            } else {
                ++j;
            }
            if (j == n) {
                break;
            }
        }
        if (j == n) {
            break;
        }
    }
    cout << "Case #" << idx << ": " << result_1 << ' ' << result_2 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        handleCase(i);
    }
}
