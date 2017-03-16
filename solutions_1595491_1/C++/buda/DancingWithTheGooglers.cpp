#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int N, S, p;
        cin >> N >> S >> p;
        int sol = 0;
        for (int i=0; i<N; ++i) {
            int total;
            cin >> total;
            if ((total+2)/3 >= p) {
                ++sol;
            } else if (S > 0) {
                int rem = total - p;
                if (rem>=0 && p-rem/2<=2) {
                    --S;
                    ++sol;
                }
            }
        }
        cout << "Case #" << t << ": " << sol << '\n';
    }
	return 0;
}
