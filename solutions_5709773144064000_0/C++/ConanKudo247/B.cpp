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
int main() 
{
    freopen("B.in2","r",stdin);
    freopen("B.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> C >> F >> X;
        long double res = 1e9;
        FR(nFarm,8000) {
            long double time_needed=0;
            long double rate = 2;
            FR(i,nFarm) {
                time_needed += C / rate;
                rate += F;
            }
            time_needed += X / rate;
            res = min(res,time_needed);
        }
        printf("%.8lf\n",(double)res);
    }
    return 0;
}
