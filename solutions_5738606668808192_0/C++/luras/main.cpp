//
//  main.cpp
//  GCJ Qualification Round 2016 Problem C. Coin Jam
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

LL b[20][20];
int n, m, a[20];
int num;
LL ans[20];

void init()
{
    for(int i = 2; i <= 10; i ++){
        b[i][0] = 1;
        for(int j = 1; j <= 16; j ++){
            b[i][j] = b[i][j - 1] * i;
        }
    }
}

void dfs(int step)
{
    if(num == m) return;
    if(step == n - 1){
        int i;
        for(i = 2; i <= 10; i ++){
            LL tmp = 0;
            for(int j = 0; j < 16; j ++){
                tmp += b[i][j] * a[j];
            }
            int flag = 0;
            for(LL j = 2; j * j <= tmp; j ++){
                if(tmp % j == 0){
                    ans[i] = j;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) break;
        }
        if(i == 11){
            num ++;
            for(int i = 15; i >= 0; i --) printf("%d", a[i]);
            for(int i = 2; i <= 10; i ++) printf(" %lld", ans[i]);
            puts("");
        }
        return;
    }
    a[step] = 0;
    dfs(step + 1);
    a[step] = 1;
    dfs(step + 1);
}

int main()
{
    fre();
    init();
    scanf("%d", &casenum);
    for(casei = 1; casei <= casenum; casei ++){
        printf("Case #%d:\n", casei);
        scanf("%d%d", &n, &m);
        num = 0;
        a[0] = 1; a[n - 1] = 1;
        dfs(1);
        //printf("%d\n", num);
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

