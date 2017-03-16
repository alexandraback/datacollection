#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int a, b, k;
		cin >> a >> b >> k;
		__int64 ans = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				if ((i & j) < k)
					++ans;
			}
		}

		cout << "Case #" << test <<	": ";
		
		cout << ans << endl;
		
    }
    return 0;
}

//C:\Users\Mykola\Documents\Visual Studio 2010\Projects\acm\acm