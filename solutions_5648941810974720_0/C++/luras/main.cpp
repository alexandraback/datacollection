//
//  main.cpp
//  GCJ Round 1B 2016 A
//
//  Created by luras on 16/4/30.
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

char s[2010];
int len, num[200], ans[200];


int main()
{
    fre();
    scanf("%d", &casenum);
    for(casei = 1; casei <= casenum; casei ++){
        scanf("%s", s);
        len = strlen(s);
        ms(num, 0);
        for(int i = 0; i < len; i ++){
            num[s[i]] ++;
        }
        ms(ans, 0);
        if(num['Z']){
            ans[0] = num['Z'];
            num['E'] -= num['Z'];
            num['R'] -= num['Z'];
            num['O'] -= num['Z'];
            num['Z'] = 0;
        }
        if(num['W']){
            ans[2] = num['W'];
            num['T'] -= num['W'];
            num['O'] -= num['W'];
            num['W'] = 0;
        }
        if(num['G']){
            ans[8] = num['G'];
            num['E'] -= num['G'];
            num['I'] -= num['G'];
            num['H'] -= num['G'];
            num['T'] -= num['G'];
            num['G'] = 0;
        }
        if(num['H']){
            ans[3] = num['H'];
            num['T'] -= num['H'];
            num['R'] -= num['H'];
            num['E'] -= num['H'];
            num['E'] -= num['H'];
            num['H'] = 0;
        }
        if(num['X']){
            ans[6] = num['X'];
            num['S'] -= num['X'];
            num['I'] -= num['X'];
            num['X'] = 0;
        }
        if(num['R']){
            ans[4] = num['R'];
            num['F'] -= num['R'];
            num['O'] -= num['R'];
            num['U'] -= num['R'];
            num['R'] = 0;
        }
        if(num['S']){
            ans[7] = num['S'];
            num['E'] -= num['S'];
            num['V'] -= num['S'];
            num['E'] -= num['S'];
            num['N'] -= num['S'];
            num['S'] = 0;
        }
        if(num['V']){
            ans[5] = num['V'];
            num['F'] -= num['V'];
            num['I'] -= num['V'];
            num['E'] -= num['V'];
            num['V'] -= num['V'];
        }
        if(num['I']){
            ans[9] = num['I'];
            num['N'] -= num['I'];
            num['N'] -= num['I'];
            num['E'] -= num['I'];
            num['I'] -= num['I'];
        }
        if(num['O']){
            ans[1] = num['O'];
            num['N'] -= num['O'];
            num['E'] -= num['O'];
            num['O'] -= num['O'];
        }
        printf("Case #%d: ", casei);
        for(int i = 0; i <= 9; i ++){
            for(int j = 1; j <= ans[i]; j ++){
                printf("%d", i);
            }
        }
        puts("");
        
    }
    return 0;
}

/*
 
 
 题意:
 
 类型:
 
 分析:
 
 优化:
 
 trick:
 
 数据:
 
 Sample Input
 
 Sample Output
 
 
 */

