#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;

int deg[10];

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int i, j, k;

    deg[0] = 1;
    for (i = 1; i < 10; i++)
        deg[i] = deg[i-1]*10;

    int tests;
    cin >> tests;
    for (int sc = 0; sc < tests; sc++) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for (i = a; i <= b; i++) {
            ostringstream ss;
            ss << i;
            int len = ss.str().length();
            set<int> st;
            for (j = 1; j < len; j++) {
                int x = i/deg[j] + (i%deg[j])*deg[len-j];
                if (i < x && x <= b) {
                    if (st.find(x) == st.end()) {
                        st.insert(x);
                        ans++;
                    }
                }
            }
        }

        cout << "Case #" << sc+1 << ": ";
        cout << ans;
        cout << endl;
    }

    fclose(stdin); fclose(stdout);
    return 0;
}
