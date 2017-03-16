#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

FILE *in = stdin;
FILE *out = stdout;

void initialize();

void compute(int *input, int N, int S, int p, int num)
{
    int qualify = 0;
    int marginal = 0;
    int i;
    int score_required = max(3*p - 2, 0);
    int score_marginal = max(3*p - 4, 0);
    for (i = 0; i < N; i++)
    {
        if (input[i] >= p)
            if (input[i] >= score_required)
                qualify++;
            else if (input[i] >= score_marginal)
                marginal++;
    }
    fprintf(out, "Case #%d: %d\n", num, min(marginal, S)+qualify);
    // cout << "Case #" << num <<": " << min(marginal, S)+qualify << "\n";
}

int main(int argc, char **argv)
{
    int N, T, S, p, i, j;
    int *input;
    in = fopen("B-small-attempt0.in", "r");
    in = fopen("B-large.in", "r");
    // in = fopen("input", "r");
    out = fopen("Result", "w+");
    fscanf(in, "%d", &T);
    for (i = 1; i <= T; i++)
    {
        fscanf(in, "%d", &N);
        fscanf(in, "%d", &S);
        fscanf(in, "%d", &p);
        input = (int *)malloc(N*sizeof(int));
        for (j = 0; j < N; j++)
        {
            fscanf(in, "%d", &input[j]);
        }
        compute(input, N, S, p, i);
        free(input);
    }
}
