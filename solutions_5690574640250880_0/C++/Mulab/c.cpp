#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 55, fx[] = {0, -1, -1, -1, 0, 1, 1, 1, 0}, fy[] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int n, m, c, good;
bool data[N][N];

void solve_n1(){
    for(int i = 1; i <= c; i++)
        putchar('*');
    for(int i = c + 1; i < m; i++)
        putchar('.');
    putchar('c');
    putchar('\n');
}

void solve_m1(){
    for(int i = 1; i <= c; i++){
        putchar('*');
        putchar('\n');
    }
    for(int i = c + 1; i < n; i++){
        putchar('.');
        putchar('\n');
    }
    putchar('c');
    putchar('\n');
}

void setGood(int x, int y){
    for(int i = 0; i <= 8; i++){
        int xx = x + fx[i];
        int yy = y + fy[i];
        if(xx <= 0 || xx > n || yy <= 0 || yy > m)
            continue;
        data[xx][yy] = true;
    }
}

void solve_good1(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            putchar(i == 1 && j == 1 ? 'c' : '*');
        putchar('\n');
    }
}

void solve(){
    scanf("%d%d%d", &n, &m, &c);
    if(n == 1)
        return solve_n1();
    if(m == 1)
        return solve_m1();
    good = n * m - c;
    if(good == 1)
        return solve_good1();
    if(good < 4 || (good & 1 && good < 9)){
        printf("Impossible\n");
        return;
    }
    memset(data, 0, sizeof(data));
    setGood(1, 1);
    good -= 4;
    for(int i = 2; i < n; i++)
        if(good > 1){
            setGood(i, 1);
            good -= 2;
        }else
            break;
    for(int j = 2; j < m; j++)
        if(good > 1){
            setGood(1, j);
            good -= 2;
        }else
            break;
    for(int i = 2; i < n; i++)
        for(int j = 2; j < m; j++)
            if(good){
                setGood(i, j);
                good--;
            }else
                break;
    if(good){
        printf("Impossible\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            putchar(i == 1 && j == 1 ? 'c' : data[i][j] ? '.' : '*');
        putchar('\n');
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}

