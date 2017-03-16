#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
int T;
long long a,b;
char c;

long long gcd(long long a, long long b) {
    if(a==0) return b;
    if(b==0) return a;
    if(a<b) {
        return gcd(a,b%a);
    } else {
        return gcd(b,a%b);
    }
}

int pw(long long b) {
    int ret = 0;
    long long x = b;
    while(x%2==0) {
        x/=2;
        ++ret;
    }
    if(x!=1) {
        return -1;
    }
    return ret;
}

int lpw(long long a) {
    long long x = 1;
    int ret = 0;

    while(x<=a) {
        ++ret;
        x*=2;
    }

    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%lld%c%lld",&a,&c,&b);
        if(a>b) {
            printf("Impossible\n");
            continue;
        }
        long long d = gcd(a,b);
        a/=d;
        b/=d;

        int x = pw(b);
        if(x==-1) {
            printf("Impossible\n");
            continue;
        }
        printf("%d\n",x+1-lpw(a));
    }
    return 0;
}
