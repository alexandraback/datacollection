//
//  main.cpp
//  2015R1B_A
//
//  Created by apple on 15/5/2.
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

ll reverse(ll n){
    ll ret = 0;
    while (n != 0){
        ret *= 10;
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

ll getsize(ll n){
    if (n == 0)return 0;
    ll ret = 0;
    while (n != 0){
        n /= 10;
        ret++;
    }
    return ret;
}

ll getdigit(ll n, ll index){
    for (int i = 1; i < index; ++i){
        n /= 10;
    }
    return n % 10;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1B_A/2015R1B_A/", "r", stdin);
    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1B_A/2015R1B_A/output1.txt", "w", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t){
        // each test case starts here
        ll n; cin >> n;
        ll count = 0;
        if (n % 10 == 0){
            n -= 1;
            count += 1;
        }
        ll nn = n;
        while (n > 10){
            ll size = getsize(n);
            for (ll i = 1; i <= size / 2; ++i){
                count += pow(10, i - 1) * getdigit(n, i);
                count += pow(10, i - 1) * getdigit(n, size + 1 - i);
            }
            if (size % 2 == 1){
                count += pow(10, size / 2) * getdigit(n, (size + 1) / 2);
            }
            int temp = 0;
            for (ll i = 1; i <= size / 2; ++i){
                temp += getdigit(n, size + 1 -i);
            }
            if (temp > 1)count += 1;
            
            n = 0;
            for (int i = 1; i < size - 1; ++i){
                n += 9;
                n *= 10;
            }
            n += 9;
        }
        count += n;
        if (nn < 19) count = nn;
        cout << "Case #" << t << ": " << count << endl;
    }
    
    return 0;
}
