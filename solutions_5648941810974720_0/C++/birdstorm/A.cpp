#include <bits/stdc++.h>
using namespace std;
string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[300];
bool vis[300];
int num[20];
void update(int x, int y) {
    int u = cnt[y];
    num[x] += u;
    cnt[y] = 0;
    for(int i = 0; i < digits[x].length(); i ++) if(digits[x][i] != y){
        cnt[digits[x][i]] -= u;
    }
}
char s[2005];
int main() {
    freopen("A-small-attempt3.in", "r", stdin);
    freopen("A-small-attempt3.out", "w", stdout);
    int T; cin>>T;
    for(int cs = 1; cs <= T; cs ++) {
        cerr << "Processing Case #" <<cs <<endl;
        scanf("%s", s);
        memset(cnt, 0, sizeof cnt);
        memset(num, 0, sizeof num);
        int len = strlen(s);
        for(int i = 0; i < len; i ++) {
            cnt[s[i]] ++;
        }
        update(0, 'Z');
        update(6, 'X');
        update(8, 'G');
        update(7, 'S');
        update(5, 'V');
        update(4, 'F');
        update(9, 'I');
        update(3, 'R');
        update(2, 'T');
        update(1, 'O');
        printf("Case #%d: ", cs);
        for(int i = 0; i <= 9; i ++) {
            while(num[i] > 0) {
                putchar(i + '0');
                -- num[i];
            }
        }
        puts("");
    }
    return 0;
}
