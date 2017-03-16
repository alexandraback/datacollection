#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
int main(){
    long long T, Case = 1;
    long long p, q;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%lld", &T);
    while(T--){
    scanf("%lld/%lld", &p, &q);//printf("%lld %lld\n", p, q);
        long long cnt = 0;
        while(q%2 == 0){
            if(p < q)
            cnt++;
            q/=2;
        }
        if(p >= q && p%q == 0) printf("Case #%lld: %lld\n",Case++, cnt);
        else printf("Case #%lld: impossible\n", Case++);
    }
    return 0;
}

