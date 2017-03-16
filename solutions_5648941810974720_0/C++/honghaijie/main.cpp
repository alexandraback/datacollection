#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>
#include <ctime>
#include <cstring>

using namespace std;

int cs = 0;
string s;
int f[1000], cnt[1000];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t;
    cin>>t;
    while (t--) {
        memset(f, 0, sizeof(f));
        memset(cnt, 0, sizeof(cnt));
        cin>>s;
        for (auto c : s) {
            f[c]++;
        }
        cnt[0] += f['Z'];
        f['E'] -= f['Z'];
        f['R'] -= f['Z'];
        f['O'] -= f['Z'];
        f['Z'] -= f['Z'];

        cnt[2] += f['W'];
        f['T'] -= f['W'];
        f['O'] -= f['W'];
        f['W'] -= f['W'];

        cnt[4] += f['U'];
        f['F'] -= f['U'];
        f['O'] -= f['U'];
        f['R'] -= f['U'];
        f['U'] -= f['U'];

        cnt[5] += f['F'];
        f['I'] -= f['F'];
        f['V'] -= f['F'];
        f['E'] -= f['F'];
        f['F'] -= f['F'];

        cnt[6] += f['X'];
        f['S'] -= f['X'];
        f['I'] -= f['X'];
        f['X'] -= f['X'];

        cnt[8] += f['G'];
        f['E'] -= f['G'];
        f['I'] -= f['G'];
        f['H'] -= f['G'];
        f['T'] -= f['G'];
        f['G'] -= f['G'];


        cnt[3] += f['H'];
        f['T'] -= f['H'];
        f['R'] -= f['H'];
        f['E'] -= f['H'];
        f['E'] -= f['H'];
        f['H'] -= f['H'];


        cnt[7] += f['S'];
        f['E'] -= f['S'];
        f['V'] -= f['S'];
        f['E'] -= f['S'];
        f['N'] -= f['S'];
        f['S'] -= f['S'];


        cnt[1] += f['O'];
        f['N'] -= f['O'];
        f['E'] -= f['O'];
        f['O'] -= f['O'];

        cnt[9] = f['I'];
        printf("Case #%d: ",++cs);
        for (int i = 0; i < 10; ++i) {
            while (cnt[i] > 0) {
                --cnt[i];
                printf("%d", i);
            }
        }
        puts("");


    }
    return 0;
}
