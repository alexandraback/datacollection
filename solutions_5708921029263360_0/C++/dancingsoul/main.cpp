#include <bits/stdc++.h>
using namespace std;



typedef double DB;
typedef long long LL;

const int N = 1e5 + 7;

struct QNode {
    int a, b, c;
    QNode() {}
    QNode(int a_, int b_, int c_) {
        a = a_, b = b_, c = c_;
    }
} res[N], q[N];


int v[10][10][10], c1[10][10], c2[10][10], c3[10][10];

int ans, J, P, S, K, n;

void dfs(int day, int last) {
    if (day > ans) {
        ans = day;
        for (int i = 0; i < day; i++)
            res[i] = q[i];
    }
    for (int i = last; i < n; i++) {
        int a = i % J, b = i / J % P, c = i / (J * P);
        if (!v[a][b][c] && c1[a][b] < K && c2[a][c] < K && c3[b][c] < K){
            v[a][b][c] = 1;
            c1[a][b]++;
            c2[a][c]++;
            c3[b][c]++;
            q[day] = QNode(a, b, c);
            dfs(day + 1, i + 1);
            v[a][b][c] = 0;
            c1[a][b]--;
            c2[a][c]--;
            c3[b][c]--;
        }
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++) {
        printf("Case #%d: ", cas);
        scanf("%d%d%d%d", &J, &P, &S, &K);
        n = J * P * S;
        memset(v, 0, sizeof(v));
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        memset(c3, 0, sizeof(c3));
        v[0][0][0] = 1;
        c1[0][0] = c2[0][0] = c3[0][0] = 1;
        q[0] = QNode(0, 0, 0);
        ans = 0;
        dfs(1, 1);
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++) {
            printf("%d %d %d\n", res[i].a + 1, res[i].b + 1, res[i].c + 1);
        }
        cerr << cas << endl;
    }
}
