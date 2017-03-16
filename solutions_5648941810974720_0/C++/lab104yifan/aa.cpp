#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 105;
const double eps = 1e-8;

double A[N][N], V[N];

inline int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

int Gauss(int n, int m) {
    int i = 0, x = 0;
    while (i < n && x < m) {
        int r = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(A[j][x]) > fabs(A[r][x]))
                r = j;
        }
        if (dcmp(A[r][x]) == 0) {
            x++;
            continue;
        }
        if (r != i) {
            for (int j = x; j < m; j++)
                swap(A[r][j], A[i][j]);
            swap(V[r], V[i]);
        }
        for (int j = m; j > x; j--) A[i][j] /= A[i][x];
        V[i] /= A[i][x];
        A[i][x] = 1.0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (dcmp(A[j][x])) {
                for (int k = m; k > x; k--)
                    A[j][k] -= A[j][x] * A[i][k];
                V[j] -= A[j][x] * V[i];
                A[j][x] = 0.0;
            }
        }
        i++; x++;
    }
    for (int k = i; k < n; k++) if (dcmp(V[k])) return -1; //无解
    if (i < m) return 1; //多解,自由变元个数为m - i;
    return 0;//唯一解
}

int T;
char str[2005];

const char sb[20][20] =  {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int h[1005], hn;
int t;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
     freopen("A-small-attempt0.out", "w", stdout);
    int cas = 0;
    scanf("%d", &t);
    while (t--) {
        hn = 0;
        memset(A, 0, sizeof(A));
        memset(V, 0, sizeof(V));
        memset(h, -1, sizeof(h));
        for (int i = 0; i < 10; i++) {
            int len = strlen(sb[i]);
            for (int j = 0; j < len; j++) {
                if (h[sb[i][j]] == -1) {
                    h[sb[i][j]] = hn++;
                }
                A[h[sb[i][j]]][i] += 1.0;
            }
        }
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            V[h[str[i]]] += 1.0;
        }
        Gauss(15, 10);
        printf("Case #%d: ", ++cas);
        for (int i = 0; i < 10; i++) {
            if (dcmp(A[i][i]) == 0) continue;
            int tmp = (int)(V[i] / A[i][i] + eps);
           // printf("%d %f %f\n", tmp, A[i][i], V[i]);
            for (int j = 0; j < tmp; j++)
              printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}
