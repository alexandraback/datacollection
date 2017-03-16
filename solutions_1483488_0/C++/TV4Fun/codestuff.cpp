#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

using namespace std;

int permute(int input, int multiplier)
{
    return input / 10 + (input % 10) * multiplier;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " filename" << endl;
        return -1;
    }

    ifstream infile(argv[1]);

    int total, a, b, digits, multiplier, recycles, temp;
    set<int> tried;
    pair<set<int>::iterator, bool> result;
    infile >> total;

    for (int i = 0; i < total; ++i)
    {
        recycles = 0;
        infile >> a >> b;
        digits = floor(log10(double(a)));
        multiplier = pow(10.0, digits);
        for (int j = a; j < b; ++j)
        {
            temp = j;
            tried.clear();
            for (int k = 0; k < digits; ++k)
            {
                temp = permute(temp, multiplier);
                if (a <= temp && temp <= b && j < temp)
                {
                    result = tried.insert(temp);
                    if (result.second) ++recycles;
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << recycles << endl;
    }
    infile.close();
}