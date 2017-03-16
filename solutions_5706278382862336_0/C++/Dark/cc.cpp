#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
long long gcd(long long a, long long b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int solve(long long p, long long q){
    long long gg = gcd(p, q);
    p /= gg;
    q /= gg;
    if(p == q || p == 0) return 0;
    if(p * 2 >= q) return 1;
    return solve(p+1, q) + 1;
}
int check(long long p,long long q){
    long long gg = gcd(p, q);
    p /= gg;
    q /= gg;
    if(p==q || p == 0) return 0;
    while(q != 1){
        if(q % 2 == 1) return 1;
        q /= 2;    
    }
    return 0;
}
int main(){
	int T;
	cin >> T;
    int ca = 0;
	for(int ca = 0; ca < T; ca++){
        long long p, q;
        scanf("%lld/%lld", &p, &q);
        int ans = solve(p,q);
        if(check(p,q))
            printf("Case #%d: impossible\n", ca+1);
        else
            printf("Case #%d: %d\n", ca+1, ans);
    }
}
