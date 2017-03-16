#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " filename" << endl;
        return -1;
    }

    ifstream infile(argv[1]);

    int total, n, s, p, minSurp, minUnsurp, numSurp, numUnsurp, t;
    infile >> total;

    for (int i = 0; i < total; ++i)
    {
        infile >> n >> s >> p;
        minSurp = max(3 * p - 4, 1);
        minUnsurp = 3 * p - 2;
        numSurp = 0;
        numUnsurp = 0;
        cout << "Case #" << i + 1 << ": ";
        for (int j = 0; j < n; ++j)
        {
            infile >> t;
            if (t >= minUnsurp)
                ++numUnsurp;
            else if (t >= minSurp)
                ++numSurp;
        }
        cout << numUnsurp + min(s, numSurp) << endl;
    }
    infile.close();
}