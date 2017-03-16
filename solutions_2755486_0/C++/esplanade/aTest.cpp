//#define __test__aTest__
#ifndef __test__aTest__

#include <vector>
#include <list>
#include <map.h>
#include <set.h>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <assert.h>

using namespace std;

#define ll long long

struct tribe {
    ll di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
    int count;
};

int main() {
    
    freopen("/Users/zishirs/Documents/workspace/test/test/test.txt", "r", stdin);
    freopen("/Users/zishirs/Documents/workspace/test/test/output.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int index = 1; index <= T; ++index) {
        int N;
        cin >> N;
        tribe all[N];
        for (int i = 0; i < N; ++i) {
            cin >> all[i].di >> all[i].ni >> all[i].wi >> all[i].ei >> all[i].si >> all[i].delta_di >> all[i].delta_pi >> all[i].delta_si;
            all[i].wi *= 2;
            all[i].ei *= 2;
            all[i].delta_pi *= 2;
            all[i].wi += 2000;
            all[i].ei += 2000;
            all[i].count = 0;
        }
        vector<ll> walls(10000, 0);
        ll ret = 0;
        while (true) {
            bool done = true;
            for (int i = 0; i < N; ++i) {
                if (all[i].count < all[i].ni) {
                    done = false;
                    break;
                }
            }
            if (done)
                break;
            ll day = 1e9;
            for (int i = 0; i < N; ++i) {
                if (all[i].count < all[i].ni)
                    day = min(all[i].di, day);
            }
            vector<ll> oldWalls(walls);
            for (int i = 0; i < N; ++i) {
                if (all[i].count < all[i].ni && day == all[i].di) {
                    for (ll j = all[i].wi; j <= all[i].ei; ++j) {
                        if (oldWalls[j] < all[i].si) {
                            ++ret;
                            break;
                        }
                    }
                    for (ll j = all[i].wi; j <= all[i].ei; ++j) {
                        walls[j] = max(walls[j], all[i].si);
                    }
                    all[i].di += all[i].delta_di;
                    all[i].count += 1;
                    all[i].wi += all[i].delta_pi;
                    all[i].ei += all[i].delta_pi;
                    all[i].si += all[i].delta_si;
                    if (all[i].si <= 0) {
                        all[i].count = all[i].ni;
                    }
                }
            }
        }
        cout<<"Case #"<<index<<": "<<ret<<endl;
    }
    
    return 0;
}

#endif