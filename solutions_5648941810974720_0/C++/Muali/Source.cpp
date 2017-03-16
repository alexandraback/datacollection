#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cstring>

using namespace std;

ifstream in;
ofstream out;

void solve()
{
    string s;
    in >> s;

    vector<int> cnt(40, 0);
    for (int i = 0; i < s.size(); ++i)
    {
        cnt[s[i] - 'A']++;        
    }

    vector<int> cnt2(15, 0);
    
    auto de = [&](string const &s2)
    {
        for (auto c: s2)
            cnt[c - 'A'] --;    
    };

    while (cnt['Z' - 'A'] != 0)
    {
        de("ZERO");
        cnt2[0]++;
    }

    while (cnt['W' - 'A'] != 0)
    {
        de("TWO");
        cnt2[2]++;
    }

    while (cnt['G' - 'A'] != 0)
    {
        de("EIGHT");
        cnt2[8]++;
    }

    while (cnt['T' - 'A'] != 0)
    {
        de("THREE");
        cnt2[3]++;
    }

    while (cnt['R' - 'A'] != 0)
    {
        de("FOUR");
        cnt2[4]++;
    }

    while (cnt['F' - 'A'] != 0)
    {
        de("FIVE");
        cnt2[5]++;
    }

    while (cnt['V' - 'A'] != 0)
    {
        de("SEVEN");
        cnt2[7]++;
    }

    while (cnt['X' - 'A'] != 0)
    {
        de("SIX");
        cnt2[6]++;
    }

    while (cnt['O' - 'A'] != 0)
    {
        de("ONE");
        cnt2[1]++;
    }

    while (cnt['N' - 'A'] != 0)
    {
        de("NINE");
        cnt2[9]++;
    }

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < cnt2[i]; ++j)
            out << i;
    }
}

int main(int argc, char const *argv[])
{
    in = ifstream(argv[1]);
    out = ofstream(argv[2]);
    //in = ifstream("in.txt");
    //out = ofstream("out.txt");
    int n;
    in >> n;
    for (int i = 0; i < n; ++i)
    {
        out << "Case #" << i + 1 << ": ";
        solve();
        out << endl;
    }
}