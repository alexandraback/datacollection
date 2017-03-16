#include <bits/stdc++.h>
using namespace std;
char s1[205], s2[205], ans[205], now[205];
long long suf[20][2][2], ten[20];
int n;
long long calcmin(char s[205], int x) {
    long long ans = 0;
    for(int i = x; i < n; i ++) {
        if(s[i] == '?') ans = ans * 10 + 0;
        else ans = ans * 10 + s[i] - '0';
    }
    return ans;
}
long long calcmax(char s[205], int x) {
    long long ans = 0;
    for(int i = x; i < n; i ++) {
        if(s[i] == '?') ans = ans * 10 + 9;
        else ans = ans * 10 + s[i] - '0';
    }
    return ans;
}
pair<long long, pair<long long, long long> > ret, nowret;
void calc(long long tmp, int i1, int i2, int x, int y) {
    for(int j = 0; j < 2; j ++) {
        for(int k = 0; k < 2; k ++) {
            long long det;
            long long suf1 = suf[i2][0][j];
            long long suf2 = suf[i2][1][k];
            if(i1 + 1 != i2) {
                suf1 += x * ten[n - i2];
                suf2 += y * ten[n - i2];
            }
            det = abs(suf1 - suf2);
            nowret = make_pair(det, make_pair(tmp * ten[n - i1 - 1] + suf1, tmp * ten[n - i1 - 1] + suf2));
            if(nowret < ret) {
                ret = nowret;
            }
        }
    }
}
void print(long long x, int n) {
    for(int i = n - 1; i >= 0; i --) {
        putchar(x / ten[i] % 10 + '0');
    }
}
int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T; cin>>T;
    ten[0] = 1;
    for(int i = 1; i <= 18; i ++) {
        ten[i] = ten[i - 1] * 10;
    }
    for(int cs = 1; cs <= T; cs ++) {
        cerr << "Processing Case #" <<cs <<endl;
        scanf("%s%s", s1, s2);
        n = strlen(s1);
        ans[n] = 0;
        memset(suf, 0, sizeof suf);
        ret = make_pair(0x3f3f3f3f3f3f3f3f, make_pair(0, 0));
        for(int i = 0; i < n; i ++) {
            suf[i][0][0] = calcmax(s1, i);
            suf[i][1][0] = calcmax(s2, i);
            suf[i][0][1] = calcmin(s1, i);
            suf[i][1][1] = calcmin(s2, i);
        }
        long long tmp = 0;
        for(int i = 0; i < n; i ++) {
            int ub1, ub2, lb1, lb2;
            if(s1[i] == '?') lb1 = 0, ub1 = 9;
            else lb1 = ub1 = s1[i] - '0';
            if(s2[i] == '?') lb2 = 0, ub2 = 9;
            else lb2 = ub2 = s2[i] - '0';
            for(int j = lb1; j <= ub1; j ++) {
                for(int k = lb2; k <= ub2; k ++) {
                    calc(tmp, i - 1, i + 1, j, k);
                }
            }
            if(s1[i] == s2[i] || s1[i] == '?' || s2[i] == '?') {
                if(s1[i] == s2[i] && s1[i] == '?') {
                    now[i] = '0';
                } else if(s1[i] == '?') {
                    now[i] = s2[i];
                } else {
                    now[i] = s1[i];
                }
                tmp = tmp * 10 + now[i] - '0';
                calc(tmp, i, i + 1, 0, 0);
            } else {
                break;
            }
        }
        printf("Case #%d: ", cs);
        print(ret.second.first, n);
        putchar(' ');
        print(ret.second.second, n);
        puts("");
    }
    return 0;
}

