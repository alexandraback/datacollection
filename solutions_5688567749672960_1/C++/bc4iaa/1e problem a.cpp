#include <bits/stdc++.h>
using namespace std;
long long dp [1000001];
int main () {
	ios :: sync_with_stdio (false);
	cin.tie (0);
	freopen ("C:\\A-small-attempt3.in", "r", stdin);
	freopen ("D:\\output.txt", "w", stdout);
	int c;
	cin >> c;
	dp [0] = 0;
	for (int i = 1; i <= 1000000; ++i)
	    dp [i] = (int) 1e18;
	for (int i = 1; i <= 1000000; ++i) {
    	long long tn = i;
    	long long ps = 0;
    	if (tn % 10) {
	    	while (tn) {
	    		ps *= 10;
	    		ps += tn % 10;
	    		tn /= 10;
	    	}
            dp [i] = min (dp [i - 1], dp [ps]) + 1;
        }
        else dp [i] = dp [i - 1] + 1;
    }
	for (int cn = 1; cn <= c; ++cn) {
        long long n;
        cin >> n;
        cout << "Case #" << cn << ": " << dp [n] << endl;
	}
	return 0;
}
