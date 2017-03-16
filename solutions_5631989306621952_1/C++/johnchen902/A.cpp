#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

char s[1001];

string solve() {
    string t;
    for(char *c = s; *c; c++)
        t = max(*c + t, t + *c);
    return move(t);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        scanf("%s", s);
        string st = solve();
        printf("Case #%d: %s\n", i, st.c_str());
    }
}

