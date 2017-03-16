#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

std::vector<long long> table;

bool isPalin(long long num){

    char buf[123];
    sprintf(buf, "%lld" ,num);

    int len = strlen(buf);
    for(int i = 0; i < len; i++){
        if(buf[i] != buf[len - i - 1]) return false;
    }
    return true;

}

int bsearch(long long obj){

    int l = 0, r = table.size() - 1;
    while(l != r){
        int m = (l + r) / 2 + 1;
        if(table[m] <= obj) l = m;
        else r = m - 1;
    }
    return l;

}

int main(){

    table.push_back(0);
    const long long LIM = 10000000LL;
    for(long long i = 1; i <= LIM; i++){
        if(isPalin(i) && isPalin(i * i)) table.push_back(i * i);
    }

    int t;
    scanf("%d" ,&t);

    for(int T = 1; T <= t; T++){
        
        long long l, r;
        scanf("%lld %lld" ,&l ,&r);

        int lcnt = l == 1? 0: bsearch(l - 1);
        int rcnt = bsearch(r);
        printf("Case #%d: %d\n" ,T ,rcnt - lcnt);

    }

}
