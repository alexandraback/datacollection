#include <cstdio>
#include <cstring>
#define MAXL 1000000

using namespace std;

char str[MAXL + 100];
int l;
int n;

int cc[MAXL + 100];
int f[MAXL + 100];
long long sumnv;

bool isC(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return false;
    else return true;
}

void work() {
    if (isC(str[0])) cc[0] = 1;
    else cc[0] = 0;
    for (int i = 1; i < l; i++) {
        if (isC(str[i])) cc[i] = cc[i - 1] + 1;
        else cc[i] = 0;
    }
    sumnv = 0;
    for (int i = 0; i < l; i++) {
        if (cc[i] == n) {
            f[i] = i - n + 2;
        } else if (cc[i] > n) {
            f[i] = f[i - 1] + 1;
        } else {
            if (i == 0) {
                f[i] = 0;
            } else {
                f[i] = f[i - 1];
            }
        }
        sumnv += f[i];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%s", str);
        l = strlen(str);
        scanf("%d\n", &n);
        work();
        printf("Case #%d: %lld\n", tc, sumnv);
    }
    
    return 0;
}
