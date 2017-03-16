#include <stdio.h>

#define min(x,y) (x)<(y)?(x):(y)
#define MAX 1000001

int dp[MAX];

long long int rev(long long int n);
int dig(long long int n);

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w+", stdout);
    for(int i=1;i<MAX;i++) dp[i]=i;
    for(int i=1;i<MAX;i++) {
        if(dig(rev(i)) == dig(i) && rev(i)<MAX) dp[i] = min(dp[i], min(dp[i-1]+1, dp[rev(i)]+1));
        else  dp[i] = min(dp[i], dp[i-1]+1);
    }

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        int num;
        scanf("%d", &num);
        printf("Case #%d: %d\n", t, dp[num]);
    }

    return 0;
}


long long int rev(long long int n) {
    int dig = 0;
    int t = n;
    while(t) {
        dig = dig*10 + t%10;
        t/=10;
    }

    return dig;
}

int dig(long long int n) {
    int d = 0;
    int t = n;
    while(t) {
        t/=10;
        d++;
    }
    return d;
}
