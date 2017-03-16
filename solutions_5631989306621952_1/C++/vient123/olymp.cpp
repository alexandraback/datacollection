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
        string S, ans;
        in >> S;
        size_t it = S.size();
        vector<bool> ok(S.size(), true);
        for (auto c = 'Z'; c >= 'A'; --c)
        {
            for (int j = it; j >= 0; --j)
                if (S[j] == c)
                    ans += c, ok[j] = false;
            it = distance(ok.begin(), find(ok.begin(), ok.end(), false));
        }
        out << ans;
        for (size_t i = 0; i < S.size(); ++i)
            if (ok[i])
                out << S[i];
        out << endl;
    }
}
