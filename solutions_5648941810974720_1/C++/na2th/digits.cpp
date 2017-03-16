#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int S = 4016;

int f[CHAR_MAX];
char s[S];
int n;
int ans[20];

int tc, tcn;
int main(){
    scanf(" %d", &tcn);
    while(tcn--){
        memset(f, 0, sizeof f);
        memset(ans, 0, sizeof ans);

        scanf(" %s", s);
        n = strlen(s);

        for(int i=0;i<n;i++) f[s[i]]++;
        ans[0] = f['Z']; ans[2] = f['W'];
        ans[8] = f['G']; ans[6] = f['X'];

        ans[7] = f['S'] - ans[6]; // S -> 6,7
        ans[5] = f['V'] - ans[7]; // V -> 5,7
        ans[3] = f['H'] - ans[8]; // H -> 3,8
        ans[4] = f['R'] - ans[3] - ans[0]; // R -> 0,3,4
        ans[9] = f['I'] - ans[5] - ans[6] - ans[8]; // I -> 5,6,8,9
        ans[1] = f['N'] - ans[7] - (ans[9]<<1); // N -> 1,7,9

        printf("Case #%d: ", ++tc);
        for(int i=0;i<10;i++)
            for(int j=0;j<ans[i];j++) putchar('0'+i);
        putchar('\n');
    }
}
