//
//  main.cpp
//  GCJ Qualification Round 2016 Problem B. Revenge of the Pancakes
//
//  Created by luras on 16/4/9.
//  Copyright (c) 2016年 luras. All rights reserved.
//

#define ms(x, y) memset(x, y, sizeof(x))
#define mc(x, y) memcpy(x, y, sizeof(x))
#define lson o << 1, l, mid
#define rson o << 1 | 1, mid + 1, r
#define ls o << 1
#define rs o << 1 | 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<list>
#include<set>
#include<string>
#include<algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")
template <class T> inline void gmax(T &a, T b){if(b > a) a = b;}
template <class T> inline void gmin(T &a, T b){if(b < a) a = b;}
using namespace std;
const int N = 1e5 + 10, M = 2e6 + 10, Z = 1e9 + 7, maxint = 2147483647, ms1 = 16843009, ms31 = 522133279, ms63 = 1061109567, ms127 = 2139062143;
const double PI = acos(-1.0), eps = 1e-8;
typedef long long LL;
void fre()
{
    freopen("/Users/luras/Desktop/in.txt", "r", stdin);
    freopen("/Users/luras/Desktop/out.txt", "w", stdout);
}
const int INF = 1e9;
int casenum, casei;

int len, num;
char s[110];


int main()
{
    //fre();
    scanf("%d", &casenum);
    for(casei = 1; casei <= casenum; casei ++){
        scanf("%s", s);
        len = strlen(s);
        num = 0;
        for(int i = 0; i < len; i ++){
            for(int j = 1; j < len; j ++){
                if(s[j] != s[j - 1]){
                    for(int k = 0; k < j; k ++){
                        if(s[k] == '+') s[k] = '-';
                        else s[k] = '+';
                    }
                    num ++;
                }
            }
        }
        if(s[0] == '-') num ++;
        printf("Case #%d: %d\n", casei, num);
    }
    return 0;
}

/*
 
 
 题意:
 
 类型:
 
 分析:
    - + - - +
 优化:
 
 trick:
 
 数据:
 
 Sample Input
 
 Sample Output
 
 
 */

