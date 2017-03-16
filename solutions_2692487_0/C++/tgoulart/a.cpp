#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int T = 1;
    int t;

    scanf("%d", &t);
    while (t--) {
        int A, N;

        scanf("%d %d", &A, &N);

        vector <int> v(N);

        for (int i=0; i < N; ++i) {
            scanf("%d", &v[i]);
        }

        sort(v.begin(), v.end());

        int ans = N;
        
        if (A > 1) {
            int acc = 0;

            for (int i=0; i < N; ++i) {
                while (A <= v[i]) {
                    A += A - 1;
                    ++acc;
                }
                A += v[i];
                ans = min(ans, acc + N - i - 1);
            }
        }

        printf("Case #%d: %d\n", T++, ans);
    }
	
	return 0;
}
