#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long m;
char s[10001];
int a[10000][9];
int c[4][4] = {1, 2, 3, 4, 2, -1, 4, -3, 3, -4, -1, 2, 4, 3, -2, -1};

int get(char c)
{
    return c - 'i' + 2;
}

int check(int &x, int &y, int z)
{
    int num = 1, f = 1, i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 9; j++) {
            a[i][j] = 0;
        }
    }
    
    for (; x < m; x++) {
        for (; y < n; y++) {
            int p = get(s[y]);
            
            num = c[num - 1][p - 1];
            
            if (num < 0) {
                num *= -1;
                f *= -1;
            }
            
            if (num * f == z) return 1;
            
            if (a[y][num * f + 4] == 1) return 0;
            
            a[y][num * f + 4] = 1;
        }
        
        y = 0;
    }
    
    return 0;
}

int get(int x)
{
    int num = 1, f = 1;
    
    for (; x < n; x++) {
        int p = get(s[x]);
        
        num = c[num - 1][p - 1];
        
        if (num < 0) {
            num *= -1;
            f *= -1;
        }
    }
    
    return num * f;
}

int check2(int x, int y)
{
    int num = get(y), num2 = get(0), f = 1, f2 = 1;
    
    x++;
    
    if (num < 0) {
        num *= -1;
        f *= -1;
    }
    
    if (num2 < 0) {
        num2 *= -1;
        f2 *= -1;
    }
    
    m -= x;
    m %= 4;
    
    for (; m > 0; m--) {
        num = c[num - 1][num2 - 1];
        f *= f2;
        
        if (num < 0) {
            num *= -1;
            f *= -1;
        }
    }
    
    if (num * f == 4) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int x = 0, y = 0, j, k;
        
        scanf("%d %lld", &n, &m);
        scanf("%s", s);
        
        if (check(x, y, 2) == 0) {
            printf("Case #%d: NO\n", i + 1);
            
            continue;
        }
        
        y++;
        
        if (check(x, y, 3) == 0) {
            printf("Case #%d: NO\n", i + 1);
            
            continue;
        }
        
        y++;
        
        if (check2(x, y) == 0) {
            printf("Case #%d: NO\n", i + 1);
        } else {
            printf("Case #%d: YES\n", i + 1);
        }
    }
    
    return 0;
}
