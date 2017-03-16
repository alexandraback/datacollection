/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2016-04-09 10:40
# Filename: 		c.cpp
# Description: 
=============================================================================*/

#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
char ch[35];

int isPrime(long long x){
    long long end = sqrt(x) + 1;
    if(x < 2) return 1;
    if(x == 2) return -1;
    for(long long i = 2; i <= end; i++)
        if(x % i == 0) return i;
    return -1;
}

char* base10ToBase2(long long val){
    int dx = 0;
    stack <int> sta;
    while(val){
        sta.push(val % 2);
        val /= 2;
    }
    while(!sta.empty()){
        ch[dx++] = sta.top() + '0';
        sta.pop();
    }
    ch[dx] = '\0';
    return ch;
}

long long base10ToBasex(long long val, int x){
    base10ToBase2(val);
    long long res = 0;
    int len = strlen(ch);
    for(int i = 0; i < len; i++){
        res += (long long)(ch[i] - '0') * pow(x, len - i - 1);
    }
    return res;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        int n, l;
        scanf("%d%d", &n, &l);
        printf("Case #%d:\n", Case);
        long long end = (1 << n);
        long long start = (1 << (n - 1)) + 1;
        int cnt = 0;
        int res[10], dx = 0;
        for(long long i = start; i < end; i += 2){
            dx = 0;
            for(int b = 2; b <= 10; b++){
                long long val = base10ToBasex(i, b);
                int yinzi = isPrime(val);
                //cerr <<"i = "<< i <<", b = "<< b <<", yinzi = "<< yinzi <<", dx = "<< dx << endl;
                if(yinzi != -1) res[dx++] = yinzi;
                else{
                    dx = 0;
                    break;
                }
            }
            if(dx == 9){
                printf("%s ", base10ToBase2(i));
                for(int i = 0; i < dx; i++)
                    printf("%d%c", res[i], i == dx-1 ? '\n' : ' ');
                cnt++;
                if(cnt == l) break;
            }
        }
    }
    return 0;
}

