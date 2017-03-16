#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 10010;

int T,L,X;
char ch[maxn];

int num[5][5];

int To(char a) {
    if (a == 'i') return 2;
    if (a == 'j') return 3;
    if (a == 'k') return 4;
}

int judge(int a,int b) {
    int t1 = abs(a),t2 = abs(b);
    int w = a*b > 0 ? 1:-1;
    return w*num[t1][t2];
}

int main() {
    freopen("/Users/zhanghanyuan/Documents/codejam/Qualification/C1.in","r",stdin);
    freopen("/Users/zhanghanyuan/Documents/codejam/Qualification/C1.out","w",stdout);
    num[1][1] = 1; num[1][2] = 2; num[1][3] = 3; num[1][4] = 4;
    num[2][1] = 2; num[2][2] = -1; num[2][3] = 4; num[2][4] = -3;
    num[3][1] = 3; num[3][2] = -4; num[3][3] = -1; num[3][4] = 2;
    num[4][1] = 4; num[4][2] = 3; num[4][3] = -2; num[4][4] = -1;
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d%d",&L,&X);
        scanf("%s",ch);
        int len = L*X;
        for (int i = L;i < len; i++)
                ch[i] = ch[i-L];
        int sum = 1;
        int ti = -1;
        bool flag = false;
        for (int i = 0;i < len; i++) {
            sum = judge(sum,To(ch[i]));
            //cout<<sum<<endl;
            if (sum == 2) ti = i;
            if (sum == 4 && ti >=0) {
                flag = true;
            }
        }
        if (sum == -1 && flag) printf("Case #%d: YES\n",kase);
        else printf("Case #%d: NO\n",kase);
    }
    return 0;
}

