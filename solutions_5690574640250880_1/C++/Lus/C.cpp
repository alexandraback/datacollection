#include <cstdio>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define foreach(it, s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define X first
#define Y second

const int MAX_N = 128;
const int MAX_M = 100001;
const int MOD = 1e9 + 7.5;
const double EPS = 1e-8;

int n, m, M;
char mat[MAX_N][MAX_N];

void init(){
    cin >> n >> m >> M;
}

bool check(int n, int m){
    int rem = n * m - M;
    bool flag = false;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) mat[i][j] = '*';
    for (int x = 2; x <= n; x++){
        int k = rem / x, b = rem % x;
        if (b == 1 || k < 2) continue;
        if (b == 0 && k > m) continue;
        if (b && k + 1 > m) continue;

        flag = true;

        for (int i = 0; i < x; i++) for (int j = 0; j < k; j++) mat[i][j] = '.';
        for (int i = 0; i < b; i++) mat[i][k] = '.';
        mat[0][0] = 'c';
        break;
    }
    return flag;
}

void solve(int ca){
    printf("Case #%d:\n", ca);
    int rem = n * m - M;
    if(rem==1)
    {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) mat[i][j] = '*';
        mat[0][0]='c';
        for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) putchar(mat[i][j]);
        puts("");
        }
        return;
    }
    if (n == 1){
        putchar('c');
        for (int i = 1; i < rem; i++) putchar('.');
        for (int i = 0; i < M; i++) putchar('*');
        puts("");
        return;
    } else if (m == 1){
        puts("c");
        for (int i = 1; i < rem; i++) puts(".");
        for (int i = 0; i < M; i++) puts("*");
        return;
    }
    if(M<=(n-2)*(m-2))
    {

        for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) mat[i][j]='.';
        mat[0][0]='c';
        int row=n-1;
        while(M)
        {
            for(int j=m-1;j>1 && M;--M,--j)
            {
                mat[row][j]='*';
            }
            --row;
        }
        for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) putchar(mat[i][j]);
        puts("");
        }
        return;
    }
    bool rev = false;
    bool flag = check(n, m);
    if (!flag){
        flag = check(m, n);
        rev = true;
    }

    if (flag){
        if (!rev){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++) putchar(mat[i][j]);
                puts("");
            }
        } else{
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++) putchar(mat[j][i]);
                puts("");
            }
        }
    }

    if (!flag){
        puts("Impossible");
    }
}

int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int ca;
    cin >> ca;
    for (int i = 0; i < ca; i++){
        init();
        solve(i + 1);
    }
    return 0;
}
