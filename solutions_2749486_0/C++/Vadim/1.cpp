#include <cstdio>
#include <memory.h>
#include <string>
#include <iostream>

#define N 3011111
#define right R
#define abs(x) ((x)<0?-(x):(x))

using namespace std;

int n;
bool right[N];
int f[N], K, ttt, p[N], W;
string ans;

        inline void solve(int n)
        {
                int k;
                for (k = 1;; k++)
                {
                        int s = k*(k-1)/2;
                        if (s >= n && (s-n)%2 == 0) break;
                }
                k--;
                int need = ((k*(k+1)/2)-n)/2;
                memset(f, 0, sizeof(f));
                memset(p, 0, sizeof(p));
                f[0] = 1;
                int x = 0;
                for (int i = 1; i<=k; i++)
                {
                        for (int j = x; j>=0; j--)
                                if (f[j] && j+i <= need) 
                                {
                                        f[j+i] = true;
                                        p[j+i] = i;
                                }
                        x += i;                        
                }
                
                memset(right, 0, sizeof(right));
                int o = need;
                while (o)
                {
                        right[p[o]] = true;
                        o -= p[o];
                }                  
                K = k;      
        }

int main()
{
        freopen("1.in", "r", stdin);
        freopen("1.txt", "w", stdout);
        scanf("%d\n", &ttt);
        for (int test = 1; test <= ttt; test++)
        {
                printf("Case #%d: ", test);
                bool q = false;
                ans = "";
                int x, y;
                scanf("%d%d\n", &x, &y);
                x *= -1; 
                if (x < 0) q = true;
                x = abs(x);
                solve(x);
                for (int i = 1; i<=K; i++)
                        if (q) right[i] ^= 1;
                for (int i = 1; i<=K; i++)
                        if (right[i]) ans += 'E'; else ans += 'W';
                
                q = false;
                if (y < 0) q = true;
                y = abs(y);
                int yy = 0;
                for (int i = K+1;y;i += 2)
                {
                        yy -= i;
                        if (q) ans += 'N'; else ans += 'S';
                        yy += i+1;
                        if (q) ans += 'S'; else ans += 'N';
                        if (yy == y) break;                        
                }
                cout << ans << endl;
        }
        return 0;
}
