#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL cnt[10], tot;
void check(LL k) {
    char str[20];
    sprintf(str, "%lld", k);
    for (int i = 0 ; str[i] ; i ++) {
        int c = str[i] - '0';
        if (cnt[c] ++ == 0) {
            tot ++;
        }
    }
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int t, cas = 0;
    scanf ("%d", &t);
    while (t --) {
        scanf ("%lld", &n);
        printf ("Case #%d: ", ++ cas);
        if (!n) {
            puts ("INSOMNIA");
           continue;
        }
        LL m = 1;tot = 0;
        memset (cnt , 0 , sizeof (cnt));
        while (m <= 10000000) {
            check(n * m);
            if (tot == 10) {
                break;
            }
            m ++;
        }
        if(tot != 10) {
            cout << "Error" << endl;
        }
        printf ("%lld\n", n * m);
    }
	return 0;
}
	
