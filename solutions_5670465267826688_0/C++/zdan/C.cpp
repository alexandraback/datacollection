#include <algorithm>
#include <numeric>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;


//enum : unsigned char { ONE = 0, ONE_, I, I_, J, J_, K, K_ };
static char mult_table[255][255] = {0};

inline char neg(char x)
{
    switch (x)
    {
    case '1':
        return '-';

    case '-':
        return '1';

    case 'i':
        return 'I';

    case 'I':
        return 'i';

    case 'j':
        return 'J';

    case 'J':
        return 'j';

    case 'k':
        return 'K';

    case 'K':
        return 'k';

    default:
        assert(false);
        return 0;
    }
}


void init_mult_table()
{
    mult_table['1']['1'] = '1';
    mult_table['1']['i'] = 'i';
    mult_table['1']['j'] = 'j';
    mult_table['1']['k'] = 'k';

    mult_table['i']['1'] = 'i';
    mult_table['i']['i'] = '-';
    mult_table['i']['j'] = 'k';
    mult_table['i']['k'] = 'J';

    mult_table['j']['1'] = 'j';
    mult_table['j']['i'] = 'K';
    mult_table['j']['j'] = '-';
    mult_table['j']['k'] = 'i';

    mult_table['k']['1'] = 'k';
    mult_table['k']['i'] = 'j';
    mult_table['k']['j'] = 'I';
    mult_table['k']['k'] = '-';

    const char list[] = {'1', 'i', 'j', 'k'};
    for (char row : list)
        for (char col : list)
        {
            mult_table[neg(row)][col]       = neg(mult_table[row][col]);
            mult_table[row][neg(col)]       = neg(mult_table[row][col]);
            mult_table[neg(row)][neg(col)]  = mult_table[row][col];
        }
}


inline char mult(char x, char y)
{
    char result = mult_table[x][y];
    assert(result != 0);
    return result;
}


char mult_all(const string& str)
{
    char result = '1';
    for (char x : str)
        result = mult(result, x);
    return result;
}


bool test_ijk(const string& str, unsigned int periods)
{
    const char targetlist[] = { 'i', 'j', 'k' };
    assert(std::accumulate(begin(targetlist), end(targetlist), '1', mult) == '-');

    auto len = str.length(), maxidx = len*periods, idx = 0U;
    for (char target : targetlist)
    {
        bool found_target = false;
        char result = '1';

        for (; idx < maxidx; ++idx)
        {
            result = mult(result, str[idx % len]);
            if (result == target)
            {
                found_target = true;
                ++idx;  // next target iteration should start from next char
                break;
            }
        }

        if (!found_target)
            return false;
    }

    char result = '1';
    for (; idx < maxidx; ++idx)
        result = mult(result, str[idx % len]);

    return (result == '1');
}


bool solve(unsigned long long int L, unsigned long long int X, const string& str)
{
    assert(str.length() == L);
    //cout << str << " * " << X << endl;

    if (L <= 1)
        return false;

    const char term = mult_all(str);
    //cout << "term = " << term << endl;

    switch (term)
    {
    case '1':
        return false;

    case '-':
        if (X % 2 != 1) // even
            return false;
        break;

    default:
        if (X % 4 != 2)
            return false;
    }

    unsigned int periods = ((term == '-') ? 3 : 6);
    if (X < periods)
        periods = X;

    return test_ijk(str, periods);
}


int main()
{
    init_mult_table();

    int T; cin >> T;
    for (int test = 1; test <= T; ++test)
    {
        unsigned long long int L, X; // L fits in int, but X <= 10e12
        string str;
        cin >> L >> X >> str;

        cout << "Case #" << test << ": "
             << (solve(L, X, str) ? "YES" : "NO") << endl;
    }

    return 0;
}

