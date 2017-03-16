#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

int t;
map<char, char> mp;
char str[128];

void solve() {
    gets(str);
    for (int j = 0; str[j] != '\0'; ++j) {
        if (str[j] >= 'a' && str[j] <= 'z') {
            str[j] = mp[str[j]];
        }
    }
    printf("Case #%d: %s\n", ++t, str);
}

int main() {
    freopen("A.out", "w", stdout);
    mp['a'] = 'y';
    mp['b'] = 'h';
    mp['c'] = 'e';
    mp['d'] = 's';
    mp['e'] = 'o';
    mp['f'] = 'c';
    mp['g'] = 'v';
    mp['h'] = 'x';
    mp['i'] = 'd';
    mp['j'] = 'u';
    mp['k'] = 'i';
    mp['l'] = 'g';
    mp['m'] = 'l';
    mp['n'] = 'b';
    mp['o'] = 'k';
    mp['p'] = 'r';
    mp['q'] = 'z';
    mp['r'] = 't';
    mp['s'] = 'n';
    mp['t'] = 'w';
    mp['u'] = 'j';
    mp['v'] = 'p';
    mp['w'] = 'f';
    mp['x'] = 'm';
    mp['y'] = 'a';
    mp['z'] = 'q';
    int t;
    scanf("%d", &t);
    while (getchar() != '\n');
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
