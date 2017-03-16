/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2016-04-09 10:11
# Filename: 		b.cpp
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
const int MAXN = 110;
char ch[MAXN];
 
int main(){
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++){
        scanf(" %s", ch);
        int len = strlen(ch);
        int start = len - 1;
        while(start >= 0 && ch[start] == '+') start--;
        int num = 0;
        for(int i = start; i >= 0; i--){
            if(ch[i] != ch[i + 1]) num++;
        }
        printf("Case #%d: %d\n", Case, num);
    }
    return 0;
}

