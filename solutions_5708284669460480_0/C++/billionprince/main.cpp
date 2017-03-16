#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

//int solve() {
//    int c, d, v, ans = 0;
//    int val[100];
//    scanf("%d%d%d", &c, &d, &v);
//    for (int i = 0; i < d; i++) {
//        scanf("%d", &val[i]);
//    }
//    for (int i = 1; i <= v; i++) {
//        int flag = 0;
//        for (int j = 0; j < (1<<d); j++) {
//            int tmp = j, sum = 0, sp = 0;
//            while(tmp) {
//                if (tmp % 2) {
//                    sum += val[sp];
//                }
//                tmp /= 2;
//                sp++;
//            }
//            if (sum == i) {
//                flag = 1;
//            }
//        }
//        if (flag == 0) {
//            ans++;
//            val[d++] = i;
//        }
//    }
//    return ans;
//}

//int solve(int R, int C, int W)
//{
//    if (C == W)
//    {
//        return R - 1 + W;
//    }
//    
//    if (W == 1)
//    {
//        return R * C;
//    }
//    
//    int ans = 0;
//    ans += (R - 1) * (C / W);
//    
//    while (C > 2 * W)
//    {
//        ans++;
//        C -= W;
//    }
//    
//    ans += (W + 1);
//    
//    return ans;
//}

//int maxcal(char tar[], int s) {
//    int len = (int)strlen(tar);
//    for (int i = 0; i < len; i++) {
//        int sp = 0;
//        for (int j = i+1; j < len; j++) {
//            if (tar[j] == tar[sp]) {
//                sp++;
//            }
//        }
//        if (sp == len-(i+1)) {
//            return s/(i+1);
//        }
//    }
//    return s/len;
//}

//void dfs(int len, int vis[], int &cnt, char g[], int sp, char tar[], int &tot, int &m) {
//    if (len == sp) {
//        g[sp] = '\0';
//        printf("%s\n", g);
//        tot++;
//        int x = (int)strlen(tar);
//        int tmp = 0;
//        for (int i = 0; i < sp; i++) {
//            if(g[i] == tar[0]) {
//                int flag = 1;
//                for(int j = 0; j < x; j++) {
//                    if(i+j > sp || tar[j] != g[i+j]) {
//                        flag = 0;
//                        break;
//                    }
//                }
//                tmp += flag;
//            }
//        }
//        m = m < tmp ? tmp: m;
//        cnt += tmp;
//    }
//    for (int i = 0; i < 26; i++) {
//        if(vis[i] == 1) {
//            g[sp] = i + 'A';
//            dfs(len, vis, cnt, g, sp+1, tar, tot, m);
//        }
//    }
//}
//
double solve() {
    int k, l, s;
    scanf("%d%d%d", &k, &l, &s);
    char keys[100], tar[100];
    scanf("%s", keys);
    scanf("%s", tar);
    int vis[30];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < strlen(keys); i++) {
        vis[keys[i]-'A'] = 1;
    }
    int cnt = 0, tot=0, m=0;
    char g[100];
    dfs(s, vis, cnt, g, 0, tar, tot, m);
//    int len = (int)strlen(keys);
//    int tp[30];
//    memset(tp, 0, sizeof(tp));
//    double val[30];
//    for (int i = 0; i < len; i++) {
//        tp[keys[i]-'A']++;
//    }
//    for (int i = 0; i < 26; i++) {
//        val[i] = tp[i] * 1.0 / len;
//    }
//    double eps = 1e-10;
//    int len1 = (int)strlen(tar);
//    for (int i = 0; i < len1; i++) {
//        if (val[tar[i]-'A'] < eps) {
//            return 0;
//        }
//        ans *= val[tar[i]-'A'];
//    }
//    printf("%d %.6lf\n", maxcal(tar, s), ans);
//    ans = maxcal(tar, s) * (1.0 - ans*(1+maxcal(tar, s))/2);
    return m - cnt*1.0/tot;
}

int main()
{
    freopen("/Users/hc/Documents/project/c++ test/c++ test/out", "w", stdout);
    freopen("/Users/hc/Downloads/B-small-attempt0.in", "r", stdin);
    int ncase;
    scanf("%d", &ncase);
    for (int i = 0; i < ncase; i++) {
        double ans = solve();
        printf("Case #%d: %.6lf\n", i+1, ans);
    }
    
    return 0;
}

