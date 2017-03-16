#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"

using namespace std;

typedef long long ll;
typedef pair < ll, ll > ii;

int t, n;
bool h[10];

int f(int x) {
    int xx = x + n;
    while(x) {
        h[x % 10] = 1;
        x /= 10;
    }
    bool flag = 0;
    for(int i = 0; i < 10; i++)
        flag |= !h[i];
    if(!flag)
        return xx - n;
    
    return f(xx);
}

int main () {
    
    //freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    scanf("%d", &t);
    
    for(int it = 1; it <= t; it++) {
        scanf("%d", &n);
        memset(h, 0, sizeof(h));
        printf("Case #%d: ", it);
        if(n)
            printf("%d\n", f(n));
        else
            puts("INSOMNIA");
    }
    
    return 0;

}