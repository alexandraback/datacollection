#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100005;
const int MOD = 1000000007;
int n;
char s[N];
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);  
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %s" , &n , s);
        int now = 0 , ans = 0;
        for (int i = 0 ; i <= n ; i ++) {
            int p = s[i] - '0';
            if (p) {
                if (now < i) {
                    ans += i - now;
                    now = i;
                }
                now += p;
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}