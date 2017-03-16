#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define ll long long

int k, c, s;
vector<ll> questions;

ll power(int x, int y) {
    ll result = 1;
    for (int i = 0; i < y; ++i)
        result *= x;
    return result;
}

void Solve() {
    questions.clear();
    cin >> k >> c >> s;
    int offset;
    for (offset = 0; offset < k; offset += c) {
        ll question = offset * power(k, c - 1) + 1;
        for (int j = 1; j < min(k - offset, c); ++j) {
            question += (j + offset) * power(k, c - j - 1);
        }
        questions.push_back(question);
    }
    if (questions.size() > s) {
        puts("IMPOSSIBLE");
        return;
    }
    for (int i = 0; i < (int)questions.size(); ++i) {
        cout << questions[i] << (i == (int)questions.size() - 1 ? "\n" : " ");
    }
}

int main() {
    int z;
    cin >> z;
    for (int i = 1; i <= z; ++i) {
        cout << "Case #" << i << ": ";
        Solve();
    }
}
