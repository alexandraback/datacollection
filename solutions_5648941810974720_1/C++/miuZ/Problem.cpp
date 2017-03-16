
// compile this with a compiler supporting C++11
// link also the gmp library using the linker flags -lgmp -lgmpxx

//#define USE_DEBUG
//#define USE_BIGINT
//#include "../../../Template/Common.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <cstdint>
#ifdef USE_BIGINT
  #include <gmpxx.h>
#endif

using namespace std;

#ifdef USE_DEBUG
  #define DBG
#else
  #define DBG if (0)
#endif

#ifdef USE_BIGINT
//typedef long long int int64;
//typedef long int64;
typedef mpz_class BigInt;
//typedef uint64_t BigInt;
#endif

//! Output of a vector
template <typename T>
ostream& operator<<(ostream &stream, const vector<T> &v) {
    if (v.size() == 0)
        return stream;
    stream << v[0];
    for (size_t i = 1; i < v.size(); ++i)
        stream << " " << v[i];
    return stream;
}


int main(int argc, char **argv) {
    //cout.unsetf(ios::floatfield);
    cout.precision(10);

#if 1
    #define IN cin
#else
    ifstream IN("A-small-practice.in");
    if (!IN) {
        cerr << "Can't open input file\n";
        exit(1);
    }
#endif

    int T;
    IN >> T;
    for (int tc = 0; tc < T; ++tc) {
        string S;
        IN >> S;

        DBG cerr << "[Case #" << (tc + 1) << "] " << S << std::endl;

        vector<int> alpha(26);
        alpha.assign(26, 0);
        for (int i = 0; i < (int) S.size(); ++i) {
            ++alpha[S[i] - 'A'];
        }

        DBG cerr << alpha << "\n";

        vector<int> theNum;

        bool found = true;
        while (found == true) {
            found = false;
            if (alpha['z'-'a'] > 0) {
                --alpha['z'-'a'];
                --alpha['e'-'a'];
                --alpha['r'-'a'];
                --alpha['o'-'a'];
                theNum.push_back(0);
                found = true;
            }
            if (alpha['w'-'a'] > 0) {
                --alpha['t'-'a'];
                --alpha['w'-'a'];
                --alpha['o'-'a'];
                theNum.push_back(2);
                found = true;
            }
            if (alpha['u'-'a'] > 0) {
                --alpha['f'-'a'];
                --alpha['o'-'a'];
                --alpha['u'-'a'];
                --alpha['r'-'a'];
                theNum.push_back(4);
                found = true;
            }
            if (alpha['x'-'a'] > 0) {
                --alpha['s'-'a'];
                --alpha['i'-'a'];
                --alpha['x'-'a'];
                theNum.push_back(6);
                found = true;
            }
            if (alpha['g'-'a'] > 0) {
                --alpha['e'-'a'];
                --alpha['i'-'a'];
                --alpha['g'-'a'];
                --alpha['h'-'a'];
                --alpha['t'-'a'];
                theNum.push_back(8);
                found = true;
            }
            DBG cerr << alpha << " (" << theNum << ")\n";
        }

        found = true;
        while (found == true) {
            found = false;
            if (alpha['s'-'a'] > 0) {
                --alpha['s'-'a'];
                --alpha['e'-'a'];
                --alpha['v'-'a'];
                --alpha['e'-'a'];
                --alpha['n'-'a'];
                theNum.push_back(7);
                found = true;
            }
            if (alpha['h'-'a'] > 0) {
                --alpha['t'-'a'];
                --alpha['h'-'a'];
                --alpha['r'-'a'];
                --alpha['e'-'a'];
                --alpha['e'-'a'];
                theNum.push_back(3);
                found = true;
            }
        }

        found = true;
        while (found == true) {
            found = false;
            if (alpha['v'-'a'] > 0) {
                --alpha['f'-'a'];
                --alpha['i'-'a'];
                --alpha['v'-'a'];
                --alpha['e'-'a'];
                theNum.push_back(5);
                found = true;
            }
            if (alpha['o'-'a'] > 0) {
                --alpha['o'-'a'];
                --alpha['n'-'a'];
                --alpha['e'-'a'];
                theNum.push_back(1);
                found = true;
            }
        }

        found = true;
        while (found == true) {
            found = false;
            if (alpha['n'-'a'] > 0) {
                --alpha['n'-'a'];
                --alpha['i'-'a'];
                --alpha['n'-'a'];
                --alpha['e'-'a'];
                theNum.push_back(9);
                found = true;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (alpha[i] != 0) {
                cerr << "ERROR at alpha " << ('A' - i) << "!!!" << std::endl;
            }
        }

        sort(theNum.begin(), theNum.end());

        DBG cerr << theNum << "\n";

        cout << "Case #" << (tc + 1) << ": ";
        for (int i = 0; i < (int) theNum.size(); ++i) {
            printf("%c", '0' + theNum[i]);
        }
        cout << std::endl;
    }
    return 0;
}

