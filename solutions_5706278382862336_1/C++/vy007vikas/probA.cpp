#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b){
    if(a>b)     gcd(b,a);
    if(a==0)    return b;
    return gcd(b%a,a);
}

int main(){
    int t;
    scanf("%d", &t);
    int xt = t;
    while(t>0){
        long long p,q,x;
        char c;
        scanf("%lld%c%lld", &p, &c, &q);
        int count = 0;
        int first = 0;
        while(count<40){
            count++;
            p = 2*p;
            x = gcd(p,q);
            p = p/x;
            q = q/x;
            if(p>q){
                p = p - q;
                if(first==0)    first = count;
            } else if (p==q){
                if(first==0)    first=count;
                break;
            }
        }
        if(count == 40 && (p!=q || p!=0)){
            printf("Case #%d: impossible\n", (xt-t+1));  
        } else {
            printf("Case #%d: %d\n" , (xt-t+1), first);
        }
        t--;
    }
    return 0;
}
