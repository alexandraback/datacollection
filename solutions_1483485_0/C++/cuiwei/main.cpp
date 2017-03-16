#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

void read() {
    char c;
    while (c = getchar(), c != '\n' && c != -1) {
        if (c >= 'a' && c <= 'z')
            putchar(map[c - 'a']);
        else
            putchar(c);
    }
    putchar('\n');
}

int main() {
    //freopen("D:\\A-small-attempt0.in", "r", stdin);
    //freopen("D:\\A-small-attempt0.out", "w", stdout);
    int tc, c = 0;
    scanf("%d", &tc);
    getchar();
    map['z' - 'a'] = 'q';
    while (tc--) {
        printf("Case #%d: ", ++c);
        read();
    }
    return 0;
}