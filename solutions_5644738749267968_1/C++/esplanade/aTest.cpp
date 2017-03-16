//#define __test__aTest__
#ifndef __test__aTest__

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
#include <stdexcept>

using namespace std;

#define ll long long
#define ull size_t

void process(int index) {
    int N;
    cin >> N;
    vector<int> Naomi, Ken;
    for (int i = 0; i < N; i++) {
        double d;
        cin >> d;
        Naomi.push_back((int)(d * 1000000));
    }
    for (int i = 0; i < N; i++) {
        double d;
        cin >> d;
        Ken.push_back((int)(d * 1000000));
    }
    sort(Naomi.begin(), Naomi.end());
    sort(Ken.begin(), Ken.end());
    deque<int> nq, kq;
    for (int i = 0; i < N; i++) {
        nq.push_back(Naomi[i]);
        kq.push_back(Ken[i]);
    }
    int y = 0;
    for (int i = 0; i < N; i++) {
        if (nq.back() > kq.back()) {
            y++;
            nq.pop_back();
            kq.pop_back();
        } else {
            nq.pop_front();
            kq.pop_back();
        }
    }
    int z = 0;
    for (int i = 0; i < N; i++) {
        int naomi = Naomi.back();
        int j = 0;
        for (; j < (int)Ken.size() - 1; j++) {
            if (Ken[j] > naomi)  break;
        }
        if (Ken[j] < naomi) {
            z++;
            Ken.erase(Ken.begin());
        } else {
            Ken.erase(Ken.begin() + j);
        }
        Naomi.pop_back();
    }
    cout<<"Case #"<<index<<": "<<y<<" "<<z<<endl;
}

int main() {
    
    freopen("/Users/zishirs/Documents/workspace/test/test/test.txt", "r", stdin);
    freopen("/Users/zishirs/Documents/workspace/test/test/output.txt", "w", stdout);
    
    
    int T;
    cin >> T;
    for (int index = 1; index <= T; ++index) {
        process(index);
        //cout<<"Case #"<<index<<": "<<endl;
    }
    
    /*
    int F;
    cin >> F;
    int n;
    vector<int> v;
    while (cin >> n) {
        v.push_back(n);
    }
    vector<int> v1(v.begin(), v.begin() + v.size()/2), v2(v.begin() + v.size()/2, v.end());
     */
    
    return 0;
}

#endif