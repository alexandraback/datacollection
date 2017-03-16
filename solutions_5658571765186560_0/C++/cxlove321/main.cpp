#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int MOD = 1000000007;
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);  
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        int x , r , c;
        scanf ("%d %d %d" , &x , &r , &c);
        if (r > c) swap (r , c);
        printf ("Case #%d: " , ++ cas);
        if ((r * c) % x) puts ("RICHARD");
        else if (x == 1) puts ("GABRIEL");
        else if (x == 2) puts ("GABRIEL");
        else if (x == 3) {if (r == 3 && c == 4) puts ("GABRIEL");
            else puts ("RICHARD");
        }
        else {
            puts ("RICHARD");
        }
        
    }
    return 0;
}