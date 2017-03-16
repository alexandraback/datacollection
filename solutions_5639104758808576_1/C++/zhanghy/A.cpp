#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1010;

int T,Smax;
char ch[maxn];

int main() {
    freopen("/Users/zhanghanyuan/Documents/codejam/Qualification/A2.in","r",stdin);
    freopen("/Users/zhanghanyuan/Documents/codejam/Qualification/2.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d %s",&Smax,ch);
        int len = strlen(ch);
        int sum = 0,ans = 0;
        for (int i = 0;i < len; i++) {
            int t = ch[i]-'0';
            if (sum < i) { ans += i-sum; sum = i; }
            sum += t;
        }
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
