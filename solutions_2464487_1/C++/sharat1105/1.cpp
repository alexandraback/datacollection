#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<cassert>
#include<iomanip>
using namespace std;

#define LL long long
#define PI pair<int,int>
#define F first
#define S second
#define MP make_pair
#define VI vector<int>
#define VPI vector<PI>
#define PB push_back

LL squareRoot(LL num)
{
    LL left = (LL)sqrt((double)num);
    LL right = (LL)sqrt((double)(2LL*num));
    if(right*right <= num) return right;
    while(right > left + 1LL){
        LL mid = (left + right)/2LL;
        if(mid * mid > num) right = mid;
        else left = mid;
    }
    return left;
}

LL ans(LL R,LL T)
{
    LL lim1 = T/(2LL*R) + 1LL;
    LL lim2 = squareRoot(T/2LL) + 10LL;
    LL left = 0;
    LL right = min(lim1,lim2);
    while(right > left + 1LL){
        LL mid = (left + right)/2LL;
        if(2*mid*R + 2LL*mid*mid - mid > T) right = mid;
        else left = mid;
    }
    return left;
}

int main()
{
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int cases;
    scanf("%d", &cases);
    for(int tt=1;tt<=cases;tt++){
        LL R,T;
        scanf("%lld%lld", &R, &T);
        printf("Case #%d: %lld\n", tt, ans(R,T));
    }
    return 0;
}
