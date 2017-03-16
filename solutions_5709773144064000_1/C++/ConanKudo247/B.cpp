#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i = (a); i <= (b);i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
long double C,F,X;

long double get_time_needed(int nFarm) {
    long double time_needed=0;
    long double rate = 2;
    FR(i,nFarm) {
        time_needed += C / rate;
        rate += F;
    }
    time_needed += X / rate;
    return time_needed;
}
int main() 
{
    freopen("B3.in","r",stdin);
    freopen("B.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> C >> F >> X;
        long double res = 1e15;
        int first = 0, last = 10000000, mid1, mid2;
        do {
            mid1 = (first * 2 + last) / 3;
            mid2 = (first + last * 2) / 3;
            if (get_time_needed(mid1) < get_time_needed(mid2)) last = mid2;
            else first = mid1;
        } while (last - first > 3);
        FOR(nFarm,first,last) res = min(res,get_time_needed(nFarm));
        printf("%.8lf\n",(double)res);
    }
    return 0;
}
