#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#define all(a) begin(a),end(a)
#define sz(a) ((int)((a).size()))

// small case: n = 32, j = 500

int main() {
    cout << "Case #1:\n";
    vector<char> init_perm;
    for (int i=0; i<8; i++)
        init_perm.push_back('0');
    for (int i=0; i<7; i++)
        init_perm.push_back('1');
    vector<vector<char>> all_perm;
    vector<char> curr_perm = init_perm;
    do {
        all_perm.push_back(curr_perm);
    } while (next_permutation(all(curr_perm)) && sz(all_perm) < 500);
    assert(sz(all_perm) == 500);
    int num_printed = 0;
    for (const auto &a : all_perm) {
        for (const auto &b : all_perm) {
            cout << '1';
            for (int i=0; i<15; i++)
                cout << a[i] << b[i];
            cout << '1';
            for (int i=2; i<=10; i++)
                cout << ' ' << (i+1);
            cout << '\n';
            num_printed++;
            if (num_printed == 500)
                return 0;

        }
    }
    assert(false);
}
