#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

int T;
long long N;

long long getAns(long long num){
    bitset<10> set;
    for (int i = 0; i < 10; i++) set[i] = 1;
    int cnt = 0;
    while(set.count()){
        if (cnt >= 1000) break;
        cnt++;
        long long n = num*cnt;
        while(n){
            set[n%10] = 0;
            n /= 10;
        }
    }
    return num*cnt;
}

int main(){
    freopen("ldata.in","r",stdin);
    freopen("ldata.out","w",stdout);
    scanf("%d",&T);
    for (int z = 1; z <= T; z++){
        scanf("%lld",&N);
        if (N == 0) printf("Case #%d: INSOMNIA\n",z);
        else printf("Case #%d: %lld\n",z,getAns(N));
    }
    return 0;
}
