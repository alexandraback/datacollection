//
//  main.cpp
//  A. Counter Culture(L)
//
//  Created by KJBS2 on 2015. 5. 3..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//


#include <stdio.h>


long long reverseL(long long n) {
    long long result = 0;
    while(n != 0) {
        result *= 10;
        result += n%10;
        n/=10;
    }
    return result;
}
int reverse(int n) {
    int result = 0;
    while(n != 0) {
        result *= 10;
        result += n%10;
        n/=10;
    }
    return result;
}

long long N;

long long Find(long long n) {
    if(n<10) return n;
    long long nn = n;
    
    int size = 0;
    long long power_min = 1;
    
    nn = n;
    while(nn) {
        nn /= 10;
        size++;
        power_min *= 10;
    }
    power_min /= 10;
    
    nn = n;
    
    long long power_s = 1;
    for(int i=1; i<=size/2; i++) {
        nn /= 10;
        power_s *= 10;
    }
    int first = (int)nn;
    int second = (int)(n - nn*power_s);
    
    long long themin = 1;
    for(int i=1; i<size-size/2; i++) themin *= 10;
    
    if(first == themin || (first == (themin+1) && second == 0) ) {
        return Find(power_min - 1) + (n - power_min + 1);
    }else{
        long long next = 0;
        if(second == 0) first --;
        next = first * power_s + 1;
        
        int minus = 0;
        if(reverseL(next) == next ) minus = 1;

        return Find(power_min - 1)  + (n - next + 1)
                                    + 1
                                    + (reverse(first))
                                    - minus;
    }
}

int main() {
    freopen("/Users/kjb/Desktop/Ainput2.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/Aouptut2.txt", "w", stdout);

    int T; scanf("%d", &T);
    for(int i=1; i<=T; i++) {
        scanf("%lld", &N);
        printf("Case #%d: %lld\n", i, Find(N) );
    }
    return 0;
}