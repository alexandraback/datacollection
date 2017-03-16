#include <bits/stdc++.h>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N = 2333,MOD = 7+1e9;
char s[N];
int vis[30];
int ans[10];
string name[10] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%s", s);
        int len = strlen(s);
        memset(vis, 0, sizeof vis);
        memset(ans, 0, sizeof ans);
        for(int i = 0;i < len;i ++) vis[s[i] - 'A'] ++;
        // 0
        ans[0] = vis['Z' - 'A'];
        for(int i = 0;i < name[0].length();i ++) vis[name[0][i] - 'A'] -= ans[0];

        // 2
        ans[2] = vis['W' - 'A'];
        for(int i = 0;i < name[2].length();i ++) vis[name[2][i] - 'A'] -= ans[2];

        // 4
        ans[4] = vis['U' - 'A'];
        for(int i = 0;i < name[4].length();i ++) vis[name[4][i] - 'A'] -= ans[4];

        // 5
        ans[5] = vis['F' - 'A'];
        for(int i = 0;i < name[5].length();i ++) vis[name[5][i] - 'A'] -= ans[5];

        // 6
        ans[6] = vis['X' - 'A'];
        for(int i = 0;i < name[6].length();i ++) vis[name[6][i] - 'A'] -= ans[6];

        // 7
        ans[7] = vis['S' - 'A'];
        for(int i = 0;i < name[7].length();i ++) vis[name[7][i] - 'A'] -= ans[7];

        // 8
        ans[8] = vis['G' - 'A'];
        for(int i = 0;i < name[8].length();i ++) vis[name[8][i] - 'A'] -= ans[8];

        // 1
        ans[1] = vis['O' - 'A'];
        for(int i = 0;i < name[1].length();i ++) vis[name[1][i] - 'A'] -= ans[1];

        // 3
        ans[3] = vis['R' - 'A'];
        for(int i = 0;i < name[3].length();i ++) vis[name[3][i] - 'A'] -= ans[3];

        // 9
        ans[9] = vis['I' - 'A'];
        for(int i = 0;i < name[9].length();i ++) vis[name[9][i] - 'A'] -= ans[9];
    
        printf("Case #%d: ", ++ca);

        for(int i = 0;i < 10;i ++) {
            for(int j = 0;j < ans[i];j ++) printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}