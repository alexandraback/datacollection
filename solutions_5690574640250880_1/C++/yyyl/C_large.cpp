#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 55;

int row[N], r, c, m, flag;

void Out() {
    int i, j, k;
    for(i = r; i > 0; --i) {
        //cout<<i<<"---"<<row[i]<<endl;
        int x = c - row[i];
        k = 1;
        if(i == r) putchar('c'), k = 2;
        for(j = k; j <= x; ++j) putchar('.');
        for(; j <= c; ++j) putchar('*');
        puts("");
    }
}

void dfs(int rr, int max_c, int sum) {
    if( flag ) return;
    if( sum == 0 ) { flag = 1; Out(); return; }
    if( (r-rr+1)*max_c < sum ) return;
    if( rr+1 == r ) {
        if( sum % 2 == 0 ) {
            row[rr] = row[rr+1] = sum / 2;
            if( sum / 2 != c - 1 ) {
                flag = 1;
                Out();
            }
        }
        return ;
    }

    for(int i = 1; i <= max_c && i <= sum; ++i) if(i != c - 1) {
        row[rr] = i;
        dfs(rr+1, i, sum - i);
        row[rr] = 0;
    }
}

int main() {
    int t;

    //freopen("C11.in", "r", stdin);
    //freopen("C11.out", "w", stdout);
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas) {
        scanf("%d%d%d", &r, &c, &m);

        //cout<<r<<"******"<<c<<m<<endl;

        for(int i = 0; i <= r; ++i) row[i] = 0;
        printf("Case #%d:\n", cas);
        if( m == r*c-1 ) {
            for(int i = 1; i <= r; ++i) row[i] = c;
            Out();
        }

        else if(r == 1 || c == 1) {
            if(r == 1) {
                row[r] = m;
            }
            else {
                for(int i = 1; i <= m; ++i) row[i] = 1;
            }
            Out();
        }

        else {
            flag = 0;
            dfs(1, c, m);
            if( !flag ) puts("Impossible");
        }
    }
    return 0;
}
