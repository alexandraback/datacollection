#include <bits/stdc++.h> 

using namespace std;

int n;
string s;
int add;
int cnt;
int T;

int main () {
#ifdef LOCAL
	freopen ("file.in", "r", stdin);
	freopen ("file.out", "w", stdout);
#endif                                
	//freopen (".in", "r", stdin);
	//freopen (".out", "w", stdout);

	cin >> T;

	for (int t = 1; t <= T; t++) {
    	cin >> n >> s;
    	cnt = add = 0;

    	for (int i = 0; i <= n; i++) {
    		int cn = s[i] - '0';
	    	int df = max (0, i - cnt);
    		add += df;
    		cnt = max (cnt, i);
	    	cnt += cn;
    	} 
    	printf ("Case #%d: %d\n", t, add);
    }

	
	return 0;
}