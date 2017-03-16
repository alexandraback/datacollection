#include <iostream>
#include <string>

using namespace std;

using i64 = long long;

const int kMax = 1000000000;

i64 AbsDiff(const string& a, const string& b) {
    auto n = a.size();
    i64 x = 0, y = 0;
    for (size_t i = 0; i < n; i++) {
        x = 10 * x + (a[i] - '0');
        y = 10 * y + (b[i] - '0');
    }
    if (x > y) return x - y;
    return y - x;
}

void FixBrute(string& as, string& bs,
              string& a, string& b,
              i64& min,
              size_t pos) {

    if (as.size() == pos) {
        auto diff = AbsDiff(as, bs);
        if (diff < min) {
            a = as;
            b = bs;
            min = diff;
        }
        return;
    }

    const char c1 = as[pos], c2 = bs[pos];

    if (c1 == '?') {
        for (char d1 = '0'; d1 <= '9'; d1++) {
            as[pos] = d1;
            if (c2 == '?') {
                for (char d2 = '0'; d2 <= '9'; d2++) {
                    bs[pos] = d2;
                    FixBrute(as, bs, a, b, min, pos + 1);
                }
                bs[pos] = c2;
            } else {
                FixBrute(as, bs, a, b, min, pos + 1);
            }
        }
        as[pos] = c1;
    } else if (c2 == '?') {
        for (char d2 = '0'; d2 <= '9'; d2++) {
            bs[pos] = d2;
            FixBrute(as, bs, a, b, min, pos + 1);
        }
        bs[pos] = c2;
    } else {
        FixBrute(as, bs, a, b, min, pos + 1);
    }
}

void FixScores(string& as, string& bs) {
    i64 min = kMax;
    string a, b;
    FixBrute(as, bs, a, b, min, 0);
    as = a;
    bs = b;
}

int main() {
    int num_tests;
    cin >> num_tests;
    string a_scores, b_scores;
    for (int test = 1; test <= num_tests; test++) {
        cin >> a_scores >> b_scores;
        FixScores(a_scores, b_scores);
        cout << "Case #" << test << ": " << a_scores << ' ' << b_scores << "\n";
    }
    return 0;
}
