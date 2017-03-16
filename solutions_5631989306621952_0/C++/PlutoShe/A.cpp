#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcase;
    scanf("%d", &testcase);
    for (int tt = 1; tt <= testcase; tt++) {
        char m[1100];
        int ans[1100];
        int ansl = 1;
        scanf("%s", m);
        int lens = strlen(m);
        ans[0] = lens; // need
        while (lens > 0) {
            char b = m[0];
            int pos = 0;
            for (int i = 1; i < lens; i++) {
                if (m[i] >= b) {
                    b = m[i];
                    pos = i;
                }
            }
            lens = pos;
            ans[ansl] = pos;
            ansl++;
        }
        string s = "";
        for (int i = ansl - 1; i >= 1; i--) {
            s = m[ans[i]] + s;
            for (int j = ans[i] + 1; j < ans[i - 1]; j++) {
                s = s + m[j];
            }
        }
        printf("Case #%d: %s\n", tt, s.c_str());
    }
}