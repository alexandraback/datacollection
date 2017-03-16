#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

inline bool is_consonent(char c)
{
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

inline bool is_vowel(char c)
{
    return !is_consonent(c);
}

bool ok(const std::string &L, int begin, int end, int n)
{
    int consec = 0;
    int max_ = 0;
    for(int i = begin; i != end; ++i)
    {
        if(!is_vowel(L.at(i))) consec++;
        else {
            max_ = max(consec, max_);
            consec = 0;
        }
    }
    return max(consec, max_) >= n;
}

void testcase(int tst)
{
    std::string L;
    cin >> L;
    int n;
    cin >> n;
    int total = 0;
    for(int i = 0; i < L.size(); ++i)
    {
        for(int j = i + 1; j <= L.size(); ++j)
        {
            total += ok(L, i, j, n) ? 1 : 0;
        }
    }
    cout << "Case #" << tst << ": " << total << endl;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        testcase(t);
    }
    return 0;
}
