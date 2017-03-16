#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin("A-large.in");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    for (int i = 0; i != n; ++i) {
        long a, b;
        fin >> a >> b;
        double p[a];
        double result = b + 2;

        for (int j = 0; j != a; ++j) {
            fin >> p[j];
        }

        double temp = 1;
        for (int j = 0; j != a; ++j) {
            temp *= p[j];
        }
        double keeptyping = (1 - temp) * (2 * b - a + 2) + temp * (b - a + 1);
        if (keeptyping < result) result = keeptyping;

        temp = 1;
        double bs = 0;
        for (int j = 0; j != a; ++j) {
            bs = temp * (a - j + b - j + 1) + (1 - temp) * (a - j + b - j + 1 + b + 1);
            if (bs < result) result = bs;
            temp *= p[j];
        }

        fout.setf(ios::fixed, ios::floatfield);
        fout.precision(6);

        fout << "Case #" << (i + 1) << ": " << result << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
