#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a[2505];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int t, cas = 0;
    cin >> t;
    while (t --) {
        cout << "Case #" << (++ cas) << ":";
        cin >> n;
        memset (a , 0 , sizeof (a));
        for (int i = 0 ; i < 2 * n - 1 ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
            int k;cin >> k;
            a[k] ++;

            }
        }
        for(int i = 0 ; i <= 2500 ; i ++) {
            if (a[i] & 1) cout << " " << i;
        }
        cout << endl;
    }

	return 0;
}
	
