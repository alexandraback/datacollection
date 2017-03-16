#include <iostream>
#include <vector>
using namespace std;

int main()
{
    FILE *fout = fopen("E:/a.txt", "w");
    int T;
    cin >> T;

    for (int cases = 1; cases <= T; ++cases)
    {
        int A, B;
        cin >> A >> B;
        double product = 1.0;
        double min = B + 2;
        int t = 2 * B + A + 2;

        for (int i = 0; i < A; ++i)
        {
            double p;
            cin >> p;
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
