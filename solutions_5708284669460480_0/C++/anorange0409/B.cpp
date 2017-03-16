#include <iostream>
#include <cstdio>
using namespace std;
int W, T, M;
string word, target;
double ans, posb;
char a[100];
int n;

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

void check() {
    string s;
    for (int i = 0; i < M; i++)
        s += a[i];
    int d = 0;
    for (int i = 0; i < M; i++)
        if (s.substr(i, target.size()) == target)
            d++;
    ans -= d * posb;
}

void dfs(int deep) {
    if (deep >= M) check(); else{
        for (int i = 0; i < word.size(); i++)
            {
                a[deep] = word[i];
                dfs(deep+1);
            }
    }
}

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);
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
        n = target.size();
        int p = get(target);
        int q = n - p;
        ans = 1;
        int x = n;
        while (x + q <= M) {
            x += q; ans++;
        }
        posb = 1;
        for (int i = 0; i < M; i++)
            posb *= 1./ word.size();
        dfs(0);
        printf("Case #%d: %.7lf\n", o, ans);
    }
}
