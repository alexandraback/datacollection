#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

typedef long long u64;

void preprocess() {
}

void solve() {
    string S;
    cin >> S;
    int ssz = S.size();
    int ss;
    int nums[10];
    for (ss=0; ss<10; ++ss) {
        nums[ss] = 0;
    }
    map<char, int> chars;
    for (ss=0; ss<ssz; ++ss) {
        ++chars[S[ss]];
    }
    // 1. G
    nums[8] += chars['G'];
    chars['E'] -= chars['G'];
    chars['I'] -= chars['G'];
    chars['H'] -= chars['G'];
    chars['T'] -= chars['G'];
    chars['G'] -= chars['G'];
    // 2. Z
    nums[0] += chars['Z'];
    chars['E'] -= chars['Z'];
    chars['R'] -= chars['Z'];
    chars['O'] -= chars['Z'];
    chars['Z'] -= chars['Z'];
    // 3. W
    nums[2] += chars['W'];
    chars['T'] -= chars['W'];
    chars['O'] -= chars['W'];
    chars['W'] -= chars['W'];
    // 4. U
    nums[4] += chars['U'];
    chars['F'] -= chars['U'];
    chars['O'] -= chars['U'];
    chars['R'] -= chars['U'];
    chars['U'] -= chars['U'];
    // 5. O
    nums[1] += chars['O'];
    chars['N'] -= chars['O'];
    chars['E'] -= chars['O'];
    chars['O'] -= chars['O'];
    // 6. X
    nums[6] += chars['X'];
    chars['S'] -= chars['X'];
    chars['I'] -= chars['X'];
    chars['X'] -= chars['X'];
    // 7. S
    nums[7] += chars['S'];
    chars['E'] -= chars['S'];
    chars['V'] -= chars['S'];
    chars['E'] -= chars['S'];
    chars['N'] -= chars['S'];
    chars['S'] -= chars['S'];
    // 9. R
    nums[3] += chars['R'];
    chars['T'] -= chars['R'];
    chars['H'] -= chars['R'];
    chars['E'] -= chars['R'];
    chars['E'] -= chars['R'];
    chars['R'] -= chars['R'];
    // 10. V
    nums[5] += chars['V'];
    chars['F'] -= chars['V'];
    chars['I'] -= chars['V'];
    chars['E'] -= chars['V'];
    chars['V'] -= chars['V'];
    // 8. E
    nums[9] += chars['E'];
    chars['N'] -= chars['E'];
    chars['I'] -= chars['E'];
    chars['N'] -= chars['E'];
    chars['E'] -= chars['E'];
    int kk;
    for (ss=0; ss<10; ++ss) {
        if (nums[ss] <= 0) continue;
        for (kk=0; kk<nums[ss]; ++kk) {
            cout << ss;
        }
    }
}

int main() {
    preprocess();
    int T;
    cin >> T;
    int tt;
    for (tt=1; tt<=T; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

