#include <string>

using namespace std;

int T;
int Smax;
char A[1002];

int c2i(char c) {
    return c - '0';
}

int solve() {
    int ans = 0;
    int c = 0;

    for (int i = 0; i <= Smax; i++) {
        int n = c2i(A[i]);
        if (i > c) {
            int f = i - c;
            c += f;
            ans += f;
        }
        c += n;
    }

    return ans;
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        for (int j = 0; j < 1002; j++) { A[j] = 0; }
        scanf("%d %s", &Smax, A);
        printf("Case #%d: %d\n", i, solve());
    }
}

