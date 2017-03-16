#include <cassert>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int LettersToFull(string const & e, string const & s)
{
    int res = 0;
    for (int k = 1; k < static_cast<int>(s.size()) && k <= static_cast<int>(e.size()); ++k)
    {
        bool overlaps = true;
        for (int i = 0; i < k; ++i)
            if (s[i] != e[e.size() - k + i])
                overlaps = false;
        if (overlaps)
            res = k;
    }
    return res;
}

int MaxFullStrings(int n, string const & s)
{
    return n < static_cast<int>(s.size()) ? 0 : 1 + (n - s.size()) / (s.size() - LettersToFull(s, s));
}

bool IsPossible(string const & kbd, string const & s)
{
    set<char> kbdset(kbd.begin(), kbd.end());
    for (char c : s)
        if (kbdset.count(c) == 0)
            return false;
    return true;
}

double AvgFullStrings(string const & kbd, int n, string const & s)
{
    /*
    vector<double> kbdP(127);
    for (int i = 0; i < kbd.size(); ++i)
        kbdP[kbd[i]] += 1;
    for (size_t i = 0; i < kbdP.size(); ++i)
        kbdP[i] /= static_cast<double>(kbd.size());
    */

    double res = 0;
    double P[102][102];
    for (int i = 0; i < 102; ++i) for (int j = 0; j < 102; ++j) P[i][j] = 0;
    P[0][0] = 1.0;

    for (int k = 0; k < n; ++k)
    {
        for (int o = 0; o <= k && o < static_cast<int>(s.size()); ++o)
        {
            if (P[k][o] > 0)
            {
                for (char c : kbd)
                {
                    double const p = P[k][o] / static_cast<double>(kbd.size());
                    if (o == static_cast<int>(s.size()) - 1 && c == s.back())
                        res += p;
                    int const m = LettersToFull(s.substr(0, o) + c, s);
                    P[k+1][m] += p;
                }
            }
        }
    }


    return res;
}

double solve(string const & kbd, int n, string const & target)
{
    if (n < static_cast<int>(target.size()) || !IsPossible(kbd, target))
        return 0;
    int const maxRes = MaxFullStrings(n, target);
    double const avgRes = AvgFullStrings(kbd, n, target);
    assert(static_cast<double>(maxRes) >= avgRes);
    return max(0.0, maxRes - avgRes);
}

int main()
{
    assert(LettersToFull("", "ABA") == 0);
    assert(LettersToFull("Z", "ABA") == 0);
    assert(LettersToFull("A", "ABA") == 1);
    assert(LettersToFull("AB", "ABA") == 2);
    assert(LettersToFull("ABA", "ABA") == 1);
    assert(LettersToFull("ABAB", "ABA") == 2);
    assert(LettersToFull("ABABZ", "ABA") == 0);
    assert(LettersToFull("ABABA", "ABA") == 1);
    assert(MaxFullStrings(1, "ABA") == 0);
    assert(MaxFullStrings(2, "ABA") == 0);
    assert(MaxFullStrings(3, "ABA") == 1);
    assert(MaxFullStrings(4, "ABA") == 1);
    assert(MaxFullStrings(5, "ABA") == 2);
    assert(MaxFullStrings(6, "ABA") == 2);
    assert(MaxFullStrings(7, "ABA") == 3);
    assert(IsPossible("AB", "ABA"));
    assert(IsPossible("BA", "ABA"));
    assert(IsPossible("ABBBA", "ABA"));
    assert(IsPossible("AZBX", "ABA"));
    assert(!IsPossible("AZX", "ABA"));
    // cout << "Hello World!" << endl;

    cout << setprecision(7);

    int testCount;
    cin >> testCount;
    for (int tst = 0; tst < testCount; ++tst)
    {
        int kbdSize, n, targetSize;
        cin >> kbdSize >> targetSize >> n;
        string kbd, target;
        cin >> kbd >> target;
        assert(kbdSize == static_cast<int>(kbd.size()));
        assert(targetSize == static_cast<int>(target.size()));
        double const res = solve(kbd, n, target);
        cout << "Case #" << tst + 1 << ": " << res /*<< "| " << n << " " << MaxFullStrings(n, target)*/ << endl;
    }

    return 0;
}

