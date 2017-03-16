/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2016-04-09 09:46
# Filename: 		a.cpp
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
bool vis[10];

bool isCan(){
    for(int i = 0; i < 10; i++)
        if(!vis[i]) return false;
    return true;
}
 
int main(){
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        long long n;
        bool flag = true;
        scanf("%lld", &n);
        long long ans = -1;
        memset(vis, 0, sizeof(vis));
        if(n == 0) printf("Case #%d: INSOMNIA\n", Case);
        else{
            int dx = 1;
            do{
                long long cur = n * dx;
                long long tmp = cur;
                while(tmp){
                    vis[tmp % 10] = true;
                    tmp /= 10;
                }
                if(isCan()){
                    ans = cur;
                    flag = false;
                }
                dx++;
            }while(flag);
            printf("Case #%d: %lld\n", Case, ans);
        }
    }
    return 0;
}

