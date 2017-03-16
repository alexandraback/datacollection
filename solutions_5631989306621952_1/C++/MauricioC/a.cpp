#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int z = 1; z <= t; z++) {
        string ans, ans2, str;
        cin >> str;
        int pos = str.size() - 1;

        while (pos >= 0) {
            int npos = pos;
            for (int i = pos-1; i >= 0; i--)
                if (str[i] > str[npos])
                    npos = i;
            ans += str[npos];
            for (int i = pos; i > npos; i--)
                ans2 += str[i];
            pos = npos - 1;
        }

        reverse(ans2.begin(), ans2.end());
        ans += ans2;
        printf("Case #%d: %s\n", z, ans.c_str());
    }
}
