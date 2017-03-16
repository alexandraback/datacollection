#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int t, cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        int k, c, s;
        scanf ("%d %d %d", &k, &c, &s);
        printf ("Case #%d:", ++ cas);
        for (int i = 0 ; i < s ; i ++) {
            printf (" %d", i + 1);
        }
        puts ("");
    }
	return 0;
}
	
