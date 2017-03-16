#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

int s[505];
bool used[505];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
        int n;
		cin >> n;
        int x = 0;
		for (int i = 0; i < n; ++i) {
            cin >> s[i];
            x += s[i];
        }
        
        double fr = 1.0;
        vector <double> ans(n);

        while (true) {
            int mn = 1000000;
            for (int i = 0; i < n; ++i) {
                if (s[i] < mn)
                    mn = s[i];
            }
            int cnt = count(s, s + n, mn);
            
            if (cnt == n) {
                for (int i = 0; i < n; ++i)
                    ans[i] += fr / (double)(n);
                break;
            } else {
                int next = 1000000;
                for (int i = 0; i < n; ++i) {
                    if (s[i] < next && s[i] != mn)
                        next = s[i];
                }
                int val = next - mn;
                if (fr * x + 1e-9 >= val * cnt) {
                    for (int i = 0; i < n; ++i) {
                        if (s[i] == mn) {
                            ans[i] += (double)(val) / (double)(x);
                            s[i] = next;
                        }
                    }
                    fr -= (double)val * (double)cnt / (double)(x);
                } else {
                    for (int i = 0; i < n; ++i)
                        if (s[i] == mn)
                            ans[i] += fr / (double)(cnt);
                    break;
                }
            }
            
        }

        double check = 0.0;
		cout << "Case #" << test << ": ";
        for (int i = 0; i < n; ++i) {
            printf("%.12lf ", ans[i] * 100.0);
            check += ans[i];
        }
        cout << endl;
        if (fabs(check - 1.0) > 1e-7)
            cerr << check << " BAD!" << endl;
	}
	return 0;
}