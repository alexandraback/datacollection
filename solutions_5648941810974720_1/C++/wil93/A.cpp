#include <bits/stdc++.h>

std::map<char, int> count;
int ans[10];

void add(std::string s, int inc) {
    for (char c: s) {
        count[c] += inc;
    }
}

int main() {
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++) {
        count.clear();

        std::string S;
        std::cin >> S;

        add(S, 1);

        while (count['Z'] > 0) {
            ans[0]++;
            add("ZERO", -1);
        }

        while (count['X'] > 0) {
            ans[6]++;
            add("SIX", -1);
        }

        while (count['U'] > 0) {
            ans[4]++;
            add("FOUR", -1);
        }

        while (count['W'] > 0) {
            ans[2]++;
            add("TWO", -1);
        }

        while (count['O'] > 0) {
            ans[1]++;
            add("ONE", -1);
        }

        while (count['R'] > 0) {
            ans[3]++;
            add("THREE", -1);
        }

        while (count['H'] > 0) {
            ans[8]++;
            add("EIGHT", -1);
        }

        while (count['S'] > 0) {
            ans[7]++;
            add("SEVEN", -1);
        }

        while (count['V'] > 0) {
            ans[5]++;
            add("FIVE", -1);
        }

        while (count['N'] > 0) {
            ans[9]++;
            add("NINE", -1);
        }

        for (char c = 'A'; c <= 'Z'; c++) {
            assert(count[c] == 0);
        }

        std::cout << "Case #" << t << ": ";
        for (int i = 0; i <= 9; i++) {
            while (ans[i] > 0) {
                std::cout << i;
                ans[i]--;
            }
        }
        std::cout << std::endl;
    }
}
