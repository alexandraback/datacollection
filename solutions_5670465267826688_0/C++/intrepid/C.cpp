//
//  B.cpp
//  codejam2015
//  zintrepid
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

#if defined(CJ_INDIRECT_COMPILE)
#  define ENTRY_POINT C
#else
#  define ENTRY_POINT main
#endif

#define CASE_LABEL(i) "Case #" << to_string(i) << ": "

#define I 2
#define J 3
#define K 4
int mabs(int value)
{
    if ( value < 0 )
        return -value;
    else
        return value;
}
int ijk_mul_impl(int value, int multiplier)
{
    assert( value >= 1 && value <= 4 );
    assert( multiplier >= 1 && multiplier <= 4 );
    static int mul_table[4][4] = {
        { 1,  I,  J,  K },
        { I, -1,  K, -J },
        { J, -K, -1,  I },
        { K,  J, -I, -1 }};
    return mul_table[value-1][multiplier-1];
}

int ijk_mul(int value, int multiplier)
{
    int value_abs = mabs(value);
    int multiplier_abs = mabs(multiplier);
    return ( value_abs == value ? 1 : -1 ) * ( multiplier_abs == multiplier ? 1 : -1 )
        * ijk_mul_impl(value_abs, multiplier_abs);
}
int c_to_ijk(char c)
{
    switch (c)
    {
        case 'i': return I;
        case 'j': return J;
        case 'k': return K;
        default: assert( !"Bad ijk char" );
    }
}

bool find_ijk(int value, const vector<int>& spelling, int max_reps, int& index, int& rep)
{
    int acc = 1;
    int start_rep = rep;
    
    if ( index >= spelling.size() )
    {
        index = 0;
        ++rep;
    }

    while ( rep < max_reps && rep < (start_rep + 10) )
    {
        while ( index < spelling.size() )
        {
            acc = ijk_mul(acc, spelling[index]);
            ++index;
            if ( acc == value )
                return true;
        }
        index = 0;
        ++rep;
    }
    return false;
}

int calc_value(const vector<int>& spelling)
{
    int acc = 1;
    for (int value : spelling)
        acc = ijk_mul(acc, value);
    return acc;
}

int ijk_pow(int value, int power)
{
    int mod = 4;
    if ( value == 1 || value == -1 )
        mod = 2;
    switch ( power % mod )
    {
        case 0:
            return 1;
        case 1:
            return value;
        case 2:
            return -1;
        case 3:
            return -value;
        
        default:
            assert( !"Error" );
            return 0;
    }
}

bool is_one_left(const vector<int>& spelling, int max_reps, int index, int rep)
{
    int acc = 1;
    while (index < spelling.size())
    {
        acc = ijk_mul(acc, spelling[index]);
        ++index;
    }
    acc = ijk_mul(acc, ijk_pow(calc_value(spelling), max_reps - rep - 1));
    return acc == 1;
}

void ijk_mul_test()
{
    vector<int> spelling;
    char ijk[] = "ijkijk";
    transform(ijk, ijk + strlen(ijk), back_inserter(spelling), &c_to_ijk);
    
    assert( is_one_left(spelling, 1, 0, 0) );
    assert( is_one_left(spelling, 2, 0, 1) );
    assert( is_one_left(spelling, 2, 0, 0) );
    assert( is_one_left(spelling, 3, 0, 0) );
    assert( is_one_left(spelling, 5, 0, 0) );
}

int ENTRY_POINT(int argc, const char* argv[])
{
    ijk_mul_test();
    int T;
    cin >> T;
    for (int test_num = 1; test_num <= T; ++test_num)
    {
        int len, reps;
        cin >> len >> reps >> ws;
        vector<int> spelling;
        for (int i=0; i<len; ++i)
        {
            char c;
            cin >> c;
            //cerr << "c=\'" << c << "\'\n";
            spelling.push_back(c_to_ijk(c));
        }
        int cur_index = 0;
        int cur_rep = 0;
        bool res = find_ijk(I, spelling, reps, cur_index, cur_rep);
        if (!res)
            cerr << "Could not find I\n";
        if ( res )
            res = find_ijk(J, spelling, reps, cur_index, cur_rep);
        if (!res)
            cerr << "Could not find J\n";
        if ( res )
            res = find_ijk(K, spelling, reps, cur_index, cur_rep);
        if (!res)
            cerr << "Could not find K\n";
        if ( res )
            res = is_one_left(spelling, reps, cur_index, cur_rep);
        cout << CASE_LABEL(test_num) << ( res ? "YES" : "NO" ) << "\n";
    }
    return 0;
}
