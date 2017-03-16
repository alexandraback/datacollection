#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int K, L, S;
string KEY;
string TARGET;

vector<string> all;

void permu(string curr) {
    if (curr.size() == S) {
        all.push_back(curr);
        return;
    }

    for (int i = 0; i < KEY.size(); ++i) {
        permu(curr + KEY[i]);
    }
}


int pay(string str) {
    int result = 0;
    for (int i = 0; i < str.size() - TARGET.size() + 1; ++i) {
        if (0 == str.compare(i, TARGET.size(), TARGET))
            result++;
    }
    return result;
}


double solve() {
    all = vector<string>();

    permu("");

    int all_pay = 0;
    int max_pay = 0;

    for (auto str : all) {
        int r = pay(str);
        all_pay += r;
        max_pay = max(max_pay, r);
    }

    double avg = (double)all_pay / all.size();

    if (max_pay == 0)
        return 0.0;

    return max_pay - avg;
}


int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> K >> L >> S;

        cin >> KEY;
        cin >> TARGET;

        printf("Case #%d: %lf\n", i, solve());
    }

    return 0;
}
