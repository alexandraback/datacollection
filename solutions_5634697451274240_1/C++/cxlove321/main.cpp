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
        cin >> s;
        s.resize(unique(s.begin(), s.end()) - s.begin());
        int n = (int)s.size();
        if (s[n - 1] == '+') n --;
        cout << "Case #" << ++ cas << ": " << n << endl;
    }
	return 0;
}
	
