//
//  main.cpp
//  GCJ Round 1B 2016 C
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

int n, m, ans, flag;
char s1[20][30], s2[20][30];
int b[30];
set<string> sot1, sot2;

int main()
{
    fre();
    for(int i = 0; i <= 20; i ++) b[i] = 1 << i;
    scanf("%d", &casenum);
    for(casei = 1; casei <= casenum; casei ++){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            scanf("%s%s", s1[i], s2[i]);
        }
        m = b[n]; ans = 0;
        for(int i = 0; i < m; i ++){
            sot1.clear(); sot2.clear(); flag = 1;
            for(int j = 0; j < n; j ++){
                if(b[j] & i){       // real
                    if(sot1.find(s1[j]) != sot1.end() && sot2.find(s2[j]) != sot2.end()){
                        flag = 0;
                        
                    }
                    else{
                        sot1.insert(s1[j]);
                        sot2.insert(s2[j]);
                    }
                }
            }
            if(flag == 1){
                for(int j = 0; j < n; j ++){
                    if((b[j] & i) == 0){
                        if(sot1.find(s1[j]) == sot1.end() || sot2.find(s2[j]) == sot2.end()){
                            flag = 0;
                        }
                    }
                }
                if(flag == 1){
                    int tmp = 0;
                    for(int j = 0; j < n; j ++){
                        if(b[j] & i) tmp ++;
                    }
                    gmax(ans, n - tmp);
                }
            }
        }
        printf("Case #%d: %d\n", casei, ans);
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

