#include <cstdio>
#include <cassert>
#include <set>
using namespace std;

int ndigs(int x){
    int cnt = 0;
    while(x){
        x /= 10;
        cnt += 1;
    }
    return cnt;    
}

int pow(int a, int b){
    int x = 1;
    for(int i = 0; i < b; i++){
        x *= a;
    }
    return x;
}

int rotate(int x, int n, int shift){
    int p_n_10 = pow(10, n);
    int base = pow(10, shift);
    int left = x % base;
    int right = x / base;
    return left*(p_n_10/base)+right;
}

int count(int x, int a, int b){
    if(x < 10) return 0;
    set<int> rec;
    int n = ndigs(x);
    for(int i = 0; i < n; i++){
        int y = rotate(x, n, i+1);
        if(y >= a && y <= b){
            if(ndigs(y) == n) rec.insert(y);
        }
    }
    return rec.size();
}

int count_pairs(int a, int b){
    int cnt = 0;
    for(int i = a; i <= b; i++){
        cnt += count(i, a, i-1);            
    }
    return cnt;
}

int main(){  
    int t, a, b;
    assert(scanf("%d", &t)==1);
    for(int i = 0; i < t; i++){
        assert(scanf("%d%d", &a, &b)==2);
        printf("Case #%d: %d\n", i+1, count_pairs(a,b));
    }
    return 0;    
}
