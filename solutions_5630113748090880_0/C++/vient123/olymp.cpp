#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <bitset>
#include <sstream>
#include <iterator>

using namespace std;

int main() 
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int TESTS;
    in >> TESTS;
    for (auto TEST = 1; TEST <= TESTS; ++TEST)
    {
        out << "Case #" << TEST << ": ";
        size_t n, num;
        in >> n;
        vector<int> kek(10000, 0);
        for (size_t i = 0; i < n * (2 * n - 1); ++i)
        {
            in >> num;
            kek[num]++;
        }
        for (size_t i = 0; i < kek.size(); ++i)
            if (kek[i] & 1)
                out << i << ' ';
        out << endl;
    }
}
