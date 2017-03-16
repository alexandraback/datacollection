#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int abs(int x) {
    return x < 0 ? -x : x;
}

bool match(int x, char y[]) {
    int a = x / 100, b = x / 10 % 10, c = x % 10;
    if ((y[0] == '?' || y[0] == a + '0') && (y[1] == '?' || y[1] == b + '0') && (y[2] == '?' || y[2] == c + '0')) {
        return true;
    }
    return false;
} 

void work()
{
    char sa[20] = {0}, sb[20] = {0};
    int ans = ~0u>>1, ai = ~0u>>1, aj = ~0u>>1;
    scanf("%s%s", sa, sb);
    int n = strlen(sa);
    if (n == 1) {
        sa[2] = sa[0]; sa[0] = sa[1] = '0';
        sb[2] = sb[0]; sb[0] = sb[1] = '0';
    }
    if (n == 2) {
        sa[2] = sa[1]; sa[1] = sa[0]; sa[0] = '0';
        sb[2] = sb[1]; sb[1] = sb[0]; sb[0] = '0';
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (match(i, sa) && match(j, sb)) {
                if (abs(i - j) < ans) {
                    ai = i;
                    aj = j;
                    ans = abs(i - j);
                } else if (abs(i - j) == ans) {
                    if (i < ai) {
                        ai = i;
                        aj = j;
                    } else if (i == ai && j < aj) {
                        ai = i;
                        aj = j;
                    }
                }
            }
        }
    }
    if (n == 1) {
        printf("%d %d\n", ai, aj);
    } else if (n == 2) {
        printf("%02d %02d\n", ai, aj);        
    } else {
        printf("%03d %03d\n", ai, aj);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        work();
    }
}