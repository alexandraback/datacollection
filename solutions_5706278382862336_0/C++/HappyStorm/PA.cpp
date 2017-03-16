#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
long long P, Q, table[45], ans;

int main()
{
    int T, times=1;
    scanf("%d", &T);
    long long t=1;
    for(int i=0 ; i<40 ; i++)
        t*=2, table[i] = t;
    while(T--){
        scanf("%lld%*c%lld", &P, &Q);
        long long gcd = __gcd(P, Q);
        while(gcd!=1)
            P/=gcd, Q/=gcd, gcd = __gcd(P, Q);
        int check=0;
        for(int i=0 ; i<40 ; i++){
            if(Q==table[i]){
                check=1;
                break;
            }
        }
        if(!check)
            printf("Case #%d: impossible\n", times++);
        else{
            ans = 0;
            while(P<Q)
                ++ans, P*=2;
            printf("Case #%d: %lld\n", times++, ans);
        }
    }
    return 0;
}
