#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        int X, Y;
        cin >> X >> Y;

        string ret;

        while(X != 0 || Y != 0){
            if (X > 0){
                ret += "W";
                ret += "E";
                --X;
            }
            else if (X < 0){
                ret += "E";
                ret += "W";
                ++X;
            }

            if (Y > 0){
                ret += "S";
                ret += "N";
                --Y;
            }
            else if (Y < 0){
                ret += "N";
                ret += "S";
                ++Y;
            }
        }
        
        

        cout << "Case #" << (test+1) << ": " << ret << endl;
    }

    return 0;
}
