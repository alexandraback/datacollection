#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C.txt", "w", stdout);

    int T;
    int n1, n2, n3;
    int R, N, M, K;

    printf("Case #1:\n");

    scanf("%d", &T);

    scanf("%d%d%d%d", &R, &N, &M, &K);

    vector<int> prod;



    int kp[100];

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < K; ++j) {
            scanf("%d", &kp[j]);
        }
        int a1, a2, a3;
        int rg = -1;
        for (n1 = 2; n1 <= M; ++n1) {
          for (n2 = 2; n2 <= M; ++n2) {
            for (n3 = 2; n3 <= M; ++n3) {
                prod.clear();
                prod.push_back(1);
                prod.push_back(n1); prod.push_back(n2); prod.push_back(n3);
                prod.push_back(n1 * n2);
                prod.push_back(n3 * n2);
                prod.push_back(n1 * n3);
                prod.push_back(n1 * n2 * n3);
                int trg = -1;
                for (int k = 0; k < K; ++k) {
                    int p;
                    for (p =0; p < prod.size(); ++p) {
                        if (kp[k] == prod[p]) {
                            break;
                        }
                    }
                    if (p <prod.size()) {
                        trg++;
                    }
                }
                if (trg > rg) {
                    rg = trg;
                    a1 = n1;
                    a2 = n2;
                    a3 = n3;
                }
            }
          }
        }
        printf("%d%d%d", a1,a2,a3);
        printf("\n");
    }

    return 0;
}
