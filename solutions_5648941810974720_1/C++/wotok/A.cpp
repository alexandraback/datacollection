#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

char str[12][12] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[1010];
int ans[12];
char in[2010];
int main() {
    int n;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int C = 1;
    while(n --) {
        scanf("%s",in);
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        int len = strlen(in);
        for (int i = 0;i < len;i ++) {
            cnt[in[i] - 'A'] ++;
        }
        ans[0] = cnt['Z' - 'A'];
        ans[2] = cnt['W' - 'A'];
        ans[4] = cnt['U' - 'A'];
        ans[5] = cnt['F' - 'A'] - ans[4];
        ans[6] = cnt['X' - 'A'];
        ans[8] = cnt['G' - 'A'];
        ans[1] = cnt['O' - 'A'] - ans[0] - ans[2] - ans[4];
        ans[3] = cnt['H' - 'A'] - ans[8];
        ans[7] = cnt['S' - 'A'] - ans[6];
        ans[9] = cnt['I' - 'A'] - ans[5] - ans[6] - ans[8];
        printf("Case #%d: ",C++);
        for (int i = 0;i < 10;i ++) {
            for (int j = 0;j < ans[i];j ++) {
                printf("%d",i);
            }
        }
        puts("");
    }
}




































