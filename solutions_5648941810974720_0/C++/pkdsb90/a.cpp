#include <bits/stdc++.h>

using namespace std;

int T, cas;

char ch[2005];
int cnt[50], sum[50];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while (T --) {
        printf("Case #%d: ", ++ cas);
        scanf(" %s", ch);
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        for (int i = 0, len = strlen(ch); i < len; i ++) {
            cnt[ch[i] - 'A'] ++;
        }
        sum[0] = cnt['Z' - 'A'];
        sum[2] = cnt['W' - 'A'];
        sum[6] = cnt['X' - 'A'];
        sum[8] = cnt['G' - 'A'];

        sum[3] = cnt['H' - 'A'] - sum[8];
        sum[4] = cnt['R' - 'A'] - sum[0] - sum[3];
        sum[5] = cnt['F' - 'A'] - sum[4];
        sum[7] = cnt['V' - 'A'] - sum[5];
        sum[9] = cnt['I' - 'A'] - sum[5] - sum[6] - sum[8];
        sum[1] = cnt['N' - 'A'] - sum[7] - 2 * sum[9];

//        for (int i = 0; i <= 9; i ++) {
//            cout << sum[i] << ' ';
//        } cout << endl;

        for (int i = 0; i <= 9; i ++) {
            for (int j = 1; j <= sum[i]; j ++) {
                printf("%d", i);
            }
        }
        puts("");
    }
}
