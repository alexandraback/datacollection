#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(int)
{
    string s;
    cin >> s;
    vector<int> cnt(256, 0);
    for (char c: s) ++cnt[c];
    vector<int> dcnt(10, 0);
    while (cnt['Z']) {
        for (char c: string("ZERO")) --cnt[c];
        ++dcnt[0];
    }
    while (cnt['X']) {
        for (char c: string("SIX")) --cnt[c];
        ++dcnt[6];
    }
    while (cnt['G']) {
        for (char c: string("EIGHT")) --cnt[c];
        ++dcnt[8];
    }
    while (cnt['H']) {
        for (char c: string("THREE")) --cnt[c];
        ++dcnt[3];
    }
    while (cnt['W']) {
        for (char c: string("TWO")) --cnt[c];
        ++dcnt[2];
    }
    while (cnt['R']) {
        for (char c: string("FOUR")) --cnt[c];
        ++dcnt[4];
    }
    while (cnt['O']) {
        for (char c: string("ONE")) --cnt[c];
        ++dcnt[1];
    }
    while (cnt['F']) {
        for (char c: string("FIVE")) --cnt[c];
        ++dcnt[5];
    }
    while (cnt['V']) {
        for (char c: string("SEVEN")) --cnt[c];
        ++dcnt[7];
    }
    while (cnt['N']) {
        for (char c: string("NINE")) --cnt[c];
        ++dcnt[9];
    }

    for (int i: cnt) assert(i == 0);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < dcnt[i]; ++j) {
            cout << i;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
