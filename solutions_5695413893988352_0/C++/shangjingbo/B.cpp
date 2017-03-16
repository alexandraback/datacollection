#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

long long ansA, ansB;

void update(long long A, long long B)
{
//fprintf(stderr, "%I64d, %I64d\n", A, B);
    if (ansA == -1 || abs(ansA - ansB) > abs(A - B) || abs(ansA - ansB) == abs(A - B) && make_pair(A, B) < make_pair(ansA, ansB)) {
        ansA = A;
        ansB = B;
    }
}

void show(long long x, int n)
{
    if (n == 0) {
        return;
    }
    int y = x % 10;
    show(x / 10, n - 1);
    printf("%d", y);
}

int main()
{
    int tests, test = 1;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        char C[100], J[100];
        ansA = -1;
        scanf("%s%s", C, J);
        int n = strlen(C);
        for (int same = 0; same <= n; ++ same) {
            bool valid = true;
            long long A = 0, B = 0;
            for (int i = 0; i < same && valid; ++ i) {
                int a = C[i] - '0', b = J[i] - '0';
                if (C[i] != '?' && J[i] != '?') {
                    valid &= a == b;
                } else if (C[i] == '?' && J[i] == '?') {
                    a = b = 0;
                } else  if (C[i] == '?') {
                    a = b;
                } else {
                    b = a;
                }
                A = A * 10 + a;
                B = B * 10 + b;
            }
            if (!valid) {
                continue;
            }
//fprintf(stderr, "same = %d\n%s\n", same, C);
            if (same < n) {
                for (int a = 0; a < 10; ++ a) {
                    if (C[same] == '?' || C[same] - '0' == a) {
//fprintf(stderr, "a = %d\n", a);
                        for (int b = 0; b < 10; ++ b) {
                            if (J[same] == '?' || J[same] - '0' == b) {
//fprintf(stderr, "a b = %d %d\n", a, b);
                                long long AA = A * 10 + a, BB = B * 10 + b;
                                if (a > b) {
                                    for (int i = same + 1; i < n; ++ i) {
                                        AA = AA * 10 + (C[i] == '?' ? 0 : C[i] - '0');
                                        BB = BB * 10 + (J[i] == '?' ? 9 : J[i] - '0');
                                    }
                                    update(AA, BB);
                                } else if (a < b) {
                                    for (int i = same + 1; i < n; ++ i) {
                                        AA = AA * 10 + (C[i] == '?' ? 9 : C[i] - '0');
                                        BB = BB * 10 + (J[i] == '?' ? 0 : J[i] - '0');
                                    }
                                    update(AA, BB);
                                }
                            }
                        }
                    }
                }
            } else {
                update(A, B);
            }
        }
        printf("Case #%d: ", test);
        show(ansA, n);
        printf(" ");
        show(ansB, n);
        printf("\n");
    }
    return 0;
}
