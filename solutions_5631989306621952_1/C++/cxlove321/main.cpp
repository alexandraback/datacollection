#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int t, cas = 0;
    cin >> t;
    while (t --) {
        cout << "Case #" << (++ cas) << ": ";
        cin >> s;
        string e = "";
        for (int i = 0 ; i < (int)s.size() ; i ++) {
            string A = e + s[i];
            string B = s[i] + e;
            if (A > B) e = A;
            else e = B;
        }
        cout << e << endl;
    }

	return 0;
}
	
