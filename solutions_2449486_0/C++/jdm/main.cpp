#include <cassert>

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

#include <cstdlib>
using std::abs;

#include <cmath>
using std::sqrt;

#include <algorithm>
using std::transform;
using std::max;
using std::min;

#include <vector>
using std::vector;
#include <set>
using std::set;
using std::multiset;

#include <utility>
using std::pair;
using std::make_pair;

#include <memory>
using std::auto_ptr;

#include <map>
using std::map;

#include <list>
using std::list;
#include <bitset>
using std::bitset;
#include <cstring>
using std::memset;

typedef int Int;

Int T;
Int N, M;
Int a[100][100];


string answer()
{
    Int rowMax[N];
    Int colMax[M];

    for (Int i=0; i< N; ++i) {
        rowMax[i] = 0;
        for (Int j=0; j<M; ++j)
            if (a[i][j] > rowMax[i]) rowMax[i] = a[i][j];
    }
    for (Int j=0; j<M; ++j) {
        colMax[j] = 0;
        for (Int i=0; i< N; ++i) 
            if (a[i][j] > colMax[j]) colMax[j] = a[i][j];
    }
    for (Int i=0; i< N; ++i)
        for (Int j=0; j<M; ++j)
            if (a[i][j] != colMax[j] && a[i][j] != rowMax[i]) {
                return "NO";
            }
    return "YES";
}

int main(int argc, char** argv)
{
    cin >> T;

    string junk;
    for (Int testcase = 1; testcase <= T; ++testcase) {
        cin >> N >> M;

        for (Int i=0; i< N; ++i)
            for (Int j=0; j<M; ++j) {
                cin >> a[i][j];
            }

        cout << "Case #" << testcase << ": "
            << answer() << endl;

    }
}
