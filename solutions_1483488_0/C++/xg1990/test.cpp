/* *************************
 * Author: xg1990
 * Created Time:  
 * LastModified:  Sat 14 Apr 2012 12:22:33 PM CST
 * C File Name: 
 * ************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl

int A,B;
int masks[7] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000
};

void shift(int& a, int mask){
    a = (a % 10) * mask + a / 10;
}
int digitcount(int n){
    return int(log(n) / log(10) + 1e-9)  + 1;
}

long long count(int n){
    int a = n;
    set<int> ans;
    int m = digitcount(n);
    int i = m;
    while(i --){
        shift(a, masks[m - 1]);
        //printf("test (%d %d)\n", n, a);
        if(digitcount(n) == m && a <= B && a > n){
            ans.insert(a);
        }
    }
    //for(set<int>::iterator it = ans.begin() ; it != ans.end() ; ++it){
        //printf("(%d %d)\n", n, *it);
    //}
    return ans.size();
}

int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        scanf("%d %d", &A, &B);
        //printf("%d %d \n=============\n", A,B);
        long long ans = 0;
        for(int i = A; i <= B; ++i){
            ans += count(i);
        }
        printf("Case #%d: %lld\n", t+1, ans);
    }
    return 0;
}


