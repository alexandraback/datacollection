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

long long getGcd(long long a, long long b)
{
    while(1)
    {
        if (a == 0){
            return b;
        }
        b %= a;
        if (b == 0){
            return a;
        }
        a %= b;
    }
}

bool getlog(ll Q, ll& pow){
    pow = 0;
    while (1) {
        if (Q == 1) return true;
        if (Q % 2 == 0) {
            ++pow;
            Q /= 2;
        }
        else {
            return false;
        }
    }
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        ll P, Q;
        char d;
        cin >> P >> d >> Q;

        ll div = getGcd(P, Q);

        P /= div;
        Q /= div;

        // cout << P << "/" << Q << endl;

        ll pow;
        bool flag = getlog(Q, pow);

        cout << "Case #" << (test+1) << ": ";
        if (!flag) {
            cout << "impossible" << endl;
            continue;
        }

        int ret = 1;
        while(1) {
            if ( P*2 >= Q ) break;
            else {
                Q /= 2;
                ++ret;
            }
        }
        
        cout << ret;
        cout << endl;
    }

    return 0;
}
