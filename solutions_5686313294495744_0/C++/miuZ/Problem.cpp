
// compile this with a compiler supporting C++11

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
        int N;
        IN >> N;
        vector<string> firstW(N);
        vector<string> secondW(N);
        //vector<pair<string, string> > theW(N);
        map<string, int> set1;
        map<string, int> set2;
        map<string, int> counted1;
        map<string, int> counted2;
        vector<int> indices[4];
        int res = 0;
        for (int i = 0; i < N; ++i) {
            IN >> firstW[i] >> secondW[i];
            //theW[i].first = firstW[i];
            //theW[i].second = secondW[i];

            bool new1;
            auto I = set1.find(firstW[i]);
            if (I == set1.end()) {
                set1.insert(pair<string, int>(firstW[i], 1));
                counted1.insert(pair<string, int>(firstW[i], 0));
                new1 = true;
            } else {
                ++(I->second);
                new1 = false;
            }
            
            bool new2;
            auto I2 = set2.find(secondW[i]);
            if (I2 == set2.end()) {
                set2.insert(pair<string, int>(secondW[i], 1));
                counted2.insert(pair<string, int>(secondW[i], 0));
                new2 = true;
            } else {
                ++(I2->second);
                new2 = false;
            }

            indices[(!new1) + (!new2) * 2].push_back(i);
        }

        //if (tc > 10-1) continue;

#if 0
        /*sort(theW.begin(), theW.end());, [](const pair<string,string> &op1, const pair<string,string> &op2)->int {

        });*/

        /*for (int i = 0; i < N; ++i) {
            cerr << theW[i].first << " " << theW[i].second << "\n";
        }*/
#endif

        //for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < (int) indices[j].size(); ++k) {
                int i = indices[j][k];

                cerr << i << " " << firstW[i] << " " << secondW[i] << "\n";

#if 1
                auto I = set1.find(firstW[i]);
                auto IC = counted1.find(firstW[i]);
                auto I2 = set2.find(secondW[i]);
                auto IC2 = counted2.find(secondW[i]);
                if (IC->second > 0 && IC2->second > 0) {
                    ++res;
                    cerr << "-> yes\n";
                }
                ++(IC->second);
                ++(IC2->second);
#endif
                /*if (j == 3) {
                    ++res;
                }*/
            }
        }

#if 0
        cerr << "set 1\n";
        for ( auto I : set1 ) {
            cerr << I.first << " - " << I.second << "\n";
        }
        cerr << "set 2\n";
        for ( auto I : set2 ) {
            cerr << I.first << " - " << I.second << "\n";
        }
#endif

        cout << "Case #" << (tc + 1) << ": ";
        cout << res << std::endl;
    }
    return 0;
}

