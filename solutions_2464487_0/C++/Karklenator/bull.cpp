#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;
typedef long long ll;
#define INF 1<<30



int main()
{
    int casenum = 1;
    int TC;
    ll r,t;
    scanf("%d\n",&TC);
    while(TC--){
        scanf("%lld %lld",&r,&t);
        ll total = 0;
        while(t >= 0){
            t -= ((r+1)*(r+1) - r*r);
            r+= 2;
            total++;
        }
        printf("Case #%d: %lld\n",casenum++,total-1);
        
    }
    return 0;
}
