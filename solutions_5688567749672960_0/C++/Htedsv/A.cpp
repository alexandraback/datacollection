#include <iostream>
using namespace std;
int f[1000001];
int a[10];
int n;
int rev(int x)
{
    int tx = x;
    int l = 0;
    while ( x > 0 )
    {
        a[l++] = x % 10;
        x /= 10;
    }
    int res = 0;
    for (int i = 0; i < l; ++i)
        res = res * 10 + a[i];
    return res;
}
        
int main()
{
    int T;
    scanf( "%d", &T);
    for (int I = 1; I <= T; ++I)
    {
        scanf( "%d", &n);
        memset( f, 0, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            int r = rev(i);
            if (r > i && r <= n)
                f[r] = f[i] + 1;
            if (f[i+1] == 0 ) 
                f[i+1] = f[i] + 1;
            else
                f[i+1] = min(f[i+1], f[i]+1);
        }
        printf("Case #%d: %d\n", I, f[n]);
    }
}
