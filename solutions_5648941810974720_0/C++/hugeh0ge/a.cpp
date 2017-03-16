#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n;
int T;
int ans[10];
char S[10001];

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        map<char, int> mp;
        scanf("%s", S);
        n = strlen(S);
        for (int i=0; i<n; i++) {
            mp[S[i]]++;
        }
        ans[6] = mp['X'];
        mp['S'] -= mp['X'];
        mp['I'] -= mp['X'];
        mp['X'] -= mp['X'];
        ans[8] = mp['G'];
        mp['E'] -= mp['G'];
        mp['I'] -= mp['G'];
        mp['H'] -= mp['G'];
        mp['T'] -= mp['G'];
        mp['G'] -= mp['G'];
        ans[0] = mp['Z'];
        mp['E'] -= mp['Z'];
        mp['R'] -= mp['Z'];
        mp['O'] -= mp['Z'];
        mp['Z'] -= mp['Z'];
        ans[3] = mp['H'];
        mp['T'] -= mp['H'];
        mp['R'] -= mp['H'];
        mp['E'] -= mp['H'];
        mp['E'] -= mp['H'];
        mp['H'] -= mp['H'];
        ans[2] = mp['W'];
        mp['T'] -= mp['W'];
        mp['O'] -= mp['W'];
        mp['W'] -= mp['W'];
        ans[4] = mp['U'];
        mp['F'] -= mp['U'];
        mp['O'] -= mp['U'];
        mp['R'] -= mp['U'];
        mp['U'] -= mp['U'];
        ans[5] = mp['F'];
        mp['I'] -= mp['F'];
        mp['V'] -= mp['F'];
        mp['E'] -= mp['F'];
        mp['F'] -= mp['F'];
        ans[7] = mp['V'];
        mp['S'] -= mp['V'];
        mp['E'] -= mp['V'];
        mp['E'] -= mp['V'];
        mp['N'] -= mp['V'];
        mp['V'] -= mp['V'];
        ans[9] = mp['I'];
        mp['N'] -= mp['I'];
        mp['N'] -= mp['I'];
        mp['E'] -= mp['I'];
        mp['I'] -= mp['I'];
        ans[1] = mp['O'];
        printf("Case #%d: ", Case);
        for (int i=0; i<10; i++) {
            while (ans[i]--) {
                printf("%d", i);
            }
        }
        puts("");
    }
}
