//
//  main.cpp
//  2015R1C_C
//
//  Created by apple on 15/5/10.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int main(int argc, const char * argv[]) {
    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1C_C/2015R1C_C/output2.txt", "w", stdout);
    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1C_C/2015R1C_C/C-large.in.txt", "r", stdin);
    ll T; cin >> T;
    for (int t = 1; t <= T; ++t){
        // each test case starts here
        ll C, D, V; cin >> C >> D >> V;
        vector<ll> Ds;
        for (ll i = 0; i < D; ++i){
            int temp; cin >> temp;
            Ds.push_back(temp);
        }
        int count = 0;
        if (Ds[0] != 1){
            count++;
            Ds.insert(Ds.begin(), 1);
        }
        ll range = 0;
        for (ll i = 0; i < Ds.size(); ++i){
            range += C * Ds[i];
            if (range >= V)break;
            if (i == Ds.size() - 1 || Ds[i + 1] > range + 1){
                Ds.insert(Ds.begin() + i + 1, range + 1);
                if (Ds.size() > 1000){
                    ll a = 0;
                }
                count++;
            }
        }
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
