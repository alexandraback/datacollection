///////////////////////////////////////////////////////////////////////
/////    The code is written for Google Code Jam 2013 contest.    /////
/////    You may use any part of this code without exception.     /////
/////    The author is not responsible for any consequences       /////
/////    of using this code.                                      /////
/////                                                             /////
/////    Author: Andrey Rubtsov                                   /////
///////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <hash_map>
#include <hash_set>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <utility>
#include <valarray>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PROBLEM_NAME "C"
#define LARGE_INPUT 0

#if LARGE_INPUT
    #define INPUT_FILE PROBLEM_NAME "-large.in"
    #define OUTPUT_FILE PROBLEM_NAME "-large.out"
#else
    #define INPUT_FILE PROBLEM_NAME "-small-attempt0.in"
    #define OUTPUT_FILE PROBLEM_NAME "-small0.out"
#endif

unsigned __int64 table[] = 
{
    1,
    4,
    9,
    121,
    484,
    10201,
    12321,
    14641,
    40804,
    44944,
    1002001,
    1234321,
    4008004,
    100020001,
    102030201,
    104060401,
    121242121,
    123454321,
    125686521,
    400080004,
    404090404,
    10000200001,
    10221412201,
    12102420121,
    12345654321,
    40000800004,
    1000002000001,
    1002003002001,
    1004006004001,
    1020304030201,
    1022325232201,
    1024348434201,
    1210024200121,
    1212225222121,
    1214428244121,
    1232346432321,
    1234567654321,
    4000008000004,
    4004009004004,
    100000020000001,
    100220141022001,
    102012040210201,
    102234363432201,
    121000242000121,
    121242363242121,
    123212464212321,
    123456787654321,
    400000080000004,
    10000000200000001,
    10002000300020001,
    10004000600040001,
    10020210401202001,
    10022212521222001,
    10024214841242001,
    10201020402010201,
    10203040504030201,
    10205060806050201,
    10221432623412201,
    10223454745432201,
    12100002420000121,
    12102202520220121,
    12104402820440121,
    12122232623222121,
    12124434743442121,
    12321024642012321,
    12323244744232321,
    12343456865434321,
    12345678987654321,
    40000000800000004,
    40004000900040004,
    1000000002000000001,
    1000220014100220001,
    1002003004003002001,
    1002223236323222001,
    1020100204020010201,
    1020322416142230201,
    1022123226223212201,
    1022345658565432201,
    1210000024200000121,
    1210242036302420121,
    1212203226223022121,
    1212445458545442121,
    1232100246420012321,
    1232344458544432321,
    1234323468643234321,
    4000000008000000004
};

int main()
{
    freopen(INPUT_FILE,"r",stdin);
    freopen(OUTPUT_FILE,"w",stdout);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        unsigned __int64 A, B;
        cin >> A >> B;

        unsigned __int64* from = std::lower_bound(table, table + _countof(table), A);
        unsigned __int64* to = std::upper_bound(table, table + _countof(table), B);

        int count = to - from;
        cout << "Case #" << i + 1 << ": " << count << endl;
    }

    return 0;
}