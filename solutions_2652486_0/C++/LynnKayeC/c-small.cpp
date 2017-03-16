#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int R;
int N = 3;
int M = 5;
int K = 7;
int v[20];
int a[4] = {2, 3, 4, 5};
vector<int> prodvec[4][4][4];

void preprocess()
{
    /* pick 3 numbers */
    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 4; ++j) {
            for (int k = j; k < 4; ++k) {
                prodvec[i][j][k].clear();
                /* compute products */
                for (int t = 0; t < 8; ++t) {
                    int prod = 1;
                    if ((t & 1) == 1)
                        prod *= a[i];
                    if ((t & 2) == 2)
                        prod *= a[j];
                    if ((t & 4) == 4)
                        prod *= a[k];
                    prodvec[i][j][k].push_back(prod);
                }
                /* sorted */
                sort(prodvec[i][j][k].begin(), prodvec[i][j][k].end());
            }
        }
    }
}

int test(int x1, int x2, int x3)
{
    for (int i = 0; i < K; ++i) {
        if (!binary_search(prodvec[x1][x2][x3].begin(), prodvec[x1][x2][x3].end(), v[i]))
            return false;
    }
    return true;
}

void getAns()
{
    for (int i = 0; i < 4; ++i)
        for (int j = i; j < 4; ++j)
            for (int k = j; k < 4; ++k) {
                if (test(i, j, k)) {
                    fprintf(stdout, "%d%d%d\n", a[i], a[j], a[k]);
                    return;
                }
            }
    fprintf(stdout, "NOT FOUND\n");
}

int main()
{
    preprocess();

    FILE * fd = fopen("input", "r");
    int testnum;
    fscanf(fd, "%d ", &testnum);
    for (int test = 1; test <= testnum; ++test)
    {
        fscanf(fd, "%d %d %d %d ", &R, &N, &M, &K);
        fprintf(stdout, "Case #1:\n");
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < K; ++j) {
                fscanf(fd, "%d ", &v[j]);
            }
            getAns();
        }
    }

    return 0;
}

