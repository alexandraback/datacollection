#include <bits/stdc++.h>
using namespace std;

typedef long long        ll;
typedef long double      ld;
typedef double           dbl;

#define mp               make_pair
#define pb               push_back
#define sz(x)            (int)(x).size()
#define X                first
#define Y                second
#define all(x)           x.begin(),x.end()
#define y1               y11

#ifdef ROMCHELA
    #define dout(x)        {cout<<#x<<" = ";cout<<(x)<<'\n';}
    #define darr(a, s, n)  {cout<<#a<<" = ";for(int _=s;_<=n;_++)cout<<a[_]<<' ';cout<<'\n';}
    #define dspace()       {for(int _=0;_<10;_++)cout<<'-';cout<<'\n';}
#else
    #define dout(x)        (void)42
    #define darr(a, s, n)  (void)42
    #define dspace()       (void)42
#endif

const int maxn = 100 * 2000 + 10;



int main() {
#ifdef ROMCHELA
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
        
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        dbl c, f, x;
        cin >> c >> f >> x;
        dbl speed = 2.0;
        dbl ans = 0.0;
        while ((x / speed) > (c / speed + x / (speed + f))) {
            ans += (c / speed);
            speed += f;
        }
        ans += x / speed;
        printf("Case #%d: %.10lf\n", i + 1, ans);
    }
    
    return 0;
}
