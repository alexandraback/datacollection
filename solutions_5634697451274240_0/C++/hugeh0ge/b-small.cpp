#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3fffffff

int T;
int n;
char S[1000];
int mind[10000];
queue<int> q;

int flip(int x, int len) {
    int ret = 0;
    for (int i=0; i<len; i++) {
        ret = (ret << 1) + ((x%2)^1);
        x /= 2;
    }
    return ret;
}

void print_binary(int x) {
    while (x > 0) {
        printf("%d", x%2);
        x /= 2;
    }
    printf("0");
    puts("");
}

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        int val = 0;

        scanf("%s", S);
        n = strlen(S);
        for (int i=n-1; i>=0; i--) {
            if (S[i] == '-') val = (val << 1) | 1;
            else val <<= 1;
        }

        fill(mind, mind+10000, INF);

        mind[val] = 0;
        q.push(val);
        while (!q.empty()) {
            int k = q.front(); q.pop();
            int mask = 1;
            for (int i=0; i<n; i++) {
                int newk = (k & ~mask) | flip(k & mask, i+1);
                if (mind[newk] > mind[k]+1) {
                    mind[newk] = mind[k]+1;
                    q.push(newk);
                }
                mask = (mask << 1) | 1;
            }
        }

        printf("Case #%d: %d\n", Case, mind[0]);
    }
}
