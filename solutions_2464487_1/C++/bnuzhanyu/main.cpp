#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include <math.h>
using namespace std;
typedef unsigned long long ull;
const double eps = 1e-6;
const double PI = acos(-1.0);
unsigned long long gotK(ull r, ull t)
{
    ull a = sqrt(t);
    ull left = 1, right = min(t/(2*r), a) + 1;
    while(left < right){
        ull mid = (left+right)/2;
        ull K = mid;
        if( 2*K*K-K <= t-2*r*K) left = mid + 1;
        else right = mid;
    }
    return (unsigned long long)(left - 1);
}

int main()
{
    int T;
    ull r, t;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    cin>>T;
    for(int ca=1; ca<=T; ++ca){
        //scanf("%ulld%ulld", &r, &t);
        cin>>r>>t;
        unsigned long long ans = gotK(r, t);
        cout << "Case #" << ca << ": "<< ans << endl;
        //printf("Case #%d: %ulld\n", ca, ans);
    }
    return 0;
}
