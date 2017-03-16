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
char s[105];

int main () {
    
    freopen("B-large.in.txt", "r", stdin);
    freopen("big.txt", "w", stdout);
    
    scanf("%d", &t);
    
    for(int it = 1; it <= t; it++) {
        scanf("%s", s);
        n = strlen(s);
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '-' and ans % 2 == 0)
                ans++;
            else if(s[i] == '+' and ans % 2 == 1)
                ans++;
        }
        printf("Case #%d: ", it);
        printf("%d\n", ans);
    }
    
    return 0;
    
}