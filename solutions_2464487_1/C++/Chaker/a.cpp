#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define pb push_back
#define sz(v) (int(v.size()))
#define mp make_pair


const long double eps = 1e-5;

long long calc2(long long r0, long long t) 
{
    long long a = -1, b = 1000000000LL+ 1;
    while (a < b) {
        long long x = (a + b + 1) / 2;
        //cout << "(" << a << " " << b << ")" << (r0 + r0 + x + x + 1) * x << "----" << t << endl;
        if ((r0 + r0 + x + x + 1) * (x + 1) <= t
        && ((r0 + r0 + x + x + 1) * (long double)(x + 1) < t + eps)) {
            a = x;
        } else {
            b = x - 1;
        }
    }
    return a == -1 ? 0 : a + 1;
}

long long calc(long long r0, long long t)
{
    int ans = 0;
    long double sum = 0;
    for (long double r = r0; (sum + 2*r + 1) <= t; r += 2) {
        ++ans;
        sum += 2 * r + 1;
        //cout << sum * M_PI << " ---- " << t << endl;
    }
    return ans;
}

int main()
{
    int TEST = 0;
    cin >> TEST;
    
    for (int test = 1; test <= TEST; ++test) {
        //---code here---
        long long t,r;
        cin >> r >> t;
        //cout << r << " " << t << endl;
        cout << "Case #" << test <<": " << calc2(r,t) << endl;
    }
    return 0;
}