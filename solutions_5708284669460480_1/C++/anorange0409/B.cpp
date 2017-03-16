#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int W, T, M, w ,t, HYC;
string word, target;
double ans, posb;
char a[100];
int n;
double F[105][105][105];
int G[105][105];

int find(char c, string s){
    for (int i = 0; i < s.size(); i++)
        if (s[i] == c) return i;
    return -1;
}

int get(string s) {
    int n = s.size();
    for (int k = n - 1; k >= 1; k--) {
        if (s.substr(0, k) == s.substr(n - k))
            return k;
    }
    return 0;
}

int get_pre(string a, string b) {
    int k = 0;
    int n = a.size(), m = b.size();
    for (int i = m; i >= 1; i--)
        if (b.substr(m-i) == a.substr(0,i))
            return i;
    return 0;
}

int main() {
    freopen("B-large.in","r",stdin);
   // freopen("B.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int Te;
    cin >> Te;
    for (int o = 1; o <= Te; o++) {
        cin >> W >> T >> M;
        cin >> word;
        cin >> target;
        bool OK = true;
        for (int i = 0; i < target.size();i++)
            if (find(target[i], word) == -1) {
                OK = false;
                break;
            }
        if (!OK) {
            printf("Case #%d: 0.0\n", o);
            continue;
        }
        w = word.size();
        t = target.size();
        HYC = get(target);
        int q = t - HYC;
        ans = 1;
        int x = t;
        while (x + q <= M) {
            x += q; ans++;
        }
        posb =  1./ word.size();;

        for (int i = 0; i < t; i++) {
            string tmp = target.substr(0, i);
            for (int j = 0; j < w; j++) {
                string tmp2 = tmp + word[j];
                int mmm = get_pre(target, tmp2);
                G[i][j] = mmm;
            }
        }
        memset(F,0,sizeof F);
        F[0][0][0] = 1;
        int maxk = ans;
        for (int i = 0; i <= M; i++)
        for (int j = 0; j < t; j++)
        for (int k = 0; k <= maxk; k++) {
            if (F[i][j][k] > 1e-8) {
                for (int p = 0; p < w; p++) {
                    int q = G[j][p];
                    if (q == t) {
                        F[i+1][HYC][k+1] += F[i][j][k] * posb;
                    } else
                        F[i+1][q][k] += F[i][j][k] * posb;
                }
                if (i == M)
                    ans -= F[i][j][k] * k;
            }

        }
        printf("Case #%d: %.8lf\n", o, ans);
    }
}
