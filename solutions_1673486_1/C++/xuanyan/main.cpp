#include <iostream>
#include <vector>
using namespace std;

int main()
{
    FILE *fin = fopen("E:/input.txt", "r");
    FILE *fout = fopen("E:/a.txt", "w");
    int T;
    fscanf(fin, "%d", &T);

    for (int cases = 1; cases <= T; ++cases)
    {
        int A, B;
        fscanf(fin, "%d%d", &A, &B);
        double product = 1.0;
        double min = B + 2;
        int t = 2 * B + A + 2;

        for (int i = 0; i < A; ++i)
        {
            double p;
            fscanf(fin, "%lf", &p);
            product *= p;
            t -= 2;
            double e = t - (B + 1) * product;

            if (e < min)
                min = e;
        }

        fprintf(fout, "Case #%d: %.6lf\n", cases, min);
    }

    fclose(fout);

    return 0;
}
