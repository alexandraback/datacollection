
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std ; 

typedef long long ll ; 

int N, J ; 

const int primes[] = {2, 3, 5, 7, 11, 13} ; 
const int pCnt = 6 ; 
ll myPow(int n, int k, int m){
    ll rtn = 1 ; 
    for(int i = 0 ; i != k ; i++)
        rtn = (rtn*n) % m ; 
    // printf("myPow(%d, %d, %d) = %d\n", n, k, m, rtn) ; 
    return rtn ; 
}

int isNotPrime(ll num, int rep){ // may return 0 even the input actually is not prime
    for(int i = 0 ; i < pCnt ; i++){
        int now = primes[i] ; 
        int sum = 0, k = 0 ; 
        ll n = num ; 
        while(n){
            if(n&1){
                sum += myPow(rep, k, now) ; 
                sum %= now ;  
            }
            n >>= 1 ; 
            k++ ; 
        }
        if(sum == 0)
            return now ; 
    }
    // puts("isPrime") ; 
    return 0 ; 
}

void printBinary(ll num){
    if(num){
        printBinary(num>>1) ; 
        putchar('0' + (num&1)) ; 
    }
}

bool ok(ll num){
    int prove[11] ; 
    for(int rep = 2 ; rep <= 10 ; rep++){
        int tmp ; 
        if(tmp = isNotPrime(num, rep))
            prove[rep] = tmp ; 
        else
            return false ;
    }
    printBinary(num) ; 
    for(int rep = 2 ; rep <= 10 ; rep++){
        printf(" %d", prove[rep]) ; 
    }
    puts("") ; 
    return true ;
}

void sol(){
    scanf("%d%d", &N, &J) ; 
    int j = 0 ;
    for(ll i = 0 ; j < J ; i++){
        if(ok((1LL<<(N-1))+(i<<1LL)+1))
            j++ ; 
    }
}

int main()
{
    int T ; 
    scanf("%d", &T) ; 
    for(int time = 1 ; time <= T ; time++){
        fprintf(stderr, "solving case (%d / %d)...\n", time, T) ; 
        printf("Case #%d: ", time) ; 
        puts("") ; 
        sol() ; 
    }
    return 0 ; 
}


