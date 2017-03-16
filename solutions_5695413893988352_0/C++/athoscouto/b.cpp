#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int t, T, c;
char u[N], v[N];

int main() {
    scanf("%d", &T);
    while(t++ <T) {
        scanf("%s %s", u, v);
        c = 0;
        for(int i=0; u[i]; ++i) {
            if (u[i] == '?') {
                if (c == 1) u[i] = '0';
                else if (c == 2) u[i] = '9';
                else {
                    if (u[i+1] and u[i+1] != '?' and v[i+1] != '?')
                        u[i] = v[i] + (v[i+1] - u[i+1] > 5) - (u[i+1] - v[i+1] >= 5);
                    else u[i] = v[i];

                    int x = min(v[i], u[i]);
                    if (v[i] == '?') v[i] += '0' - x, u[i] += '0' - x;

                    u[i] = min('9', u[i]);
                    u[i] = max('0', u[i]);
                }
            }
            if (v[i] == '?') {
                if (c == 2) v[i] = '0';
                else if (c == 1) v[i] = '9';
                else {
                    if (u[i+1] and u[i+1] != '?' and v[i+1] != '?')
                        v[i] = u[i] - (v[i+1] - u[i+1] >= 5) + (u[i+1] - v[i+1] > 5);
                    else v[i] = u[i];

                    v[i] = min('9', v[i]);
                    v[i] = max('0', v[i]);
                }
            }

            if (!c and u[i] > v[i]) c = 1;
            if (!c and u[i] < v[i]) c = 2;
        }
        printf("Case #%d: %s %s\n", t, u, v);
    }

    return 0;
}
