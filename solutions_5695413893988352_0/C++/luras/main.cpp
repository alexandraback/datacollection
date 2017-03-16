//
//  main.cpp
//  GCJ Round 1B 2016 B
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

int len, flag;
char s1[20], s2[20];
int ans1, ans2, ans;

void dfs(int step, int tmp1, int tmp2)
{
    if(step == len){
        if(fabs(tmp1 - tmp2) <= ans){
            if(fabs(tmp1 - tmp2) < ans){
                ans = fabs(tmp1 - tmp2);
                ans1 = tmp1;
                ans2 = tmp2;
            }
            else{
                if(tmp1 < ans1){
                    ans1 = tmp1;
                    ans2 = tmp2;
                }
                else if(tmp1 == ans1 && tmp2 < ans2){
                    ans2 = tmp2;
                    ans1 = tmp1;
                }
            }
        }
        return;
    }
    if(s1[step] == '?'){
        for(int i = 0; i <= 9; i ++){
            if(s2[step] == '?'){
                for(int j = 0; j <= 9; j ++){
                    dfs(step + 1, tmp1 * 10 + i, tmp2 * 10 + j);
                }
            }
            else{
                dfs(step + 1, tmp1 * 10 + i, tmp2 * 10 + s2[step] - '0');
            }
        }
    }
    else{
        if(s2[step] == '?'){
            for(int j = 0; j <= 9; j ++){
                dfs(step + 1, tmp1 * 10 + s1[step] - '0', tmp2 * 10 + j);
            }
        }
        else{
            dfs(step + 1, tmp1 * 10 + s1[step] - '0', tmp2 * 10 + s2[step] - '0');
        }
    }
}

int main()
{
    fre();
    scanf("%d", &casenum);
    for(casei = 1; casei <= casenum; casei ++){
        scanf("%s%s", s1, s2);
        len = strlen(s1);
        flag = 0;   // 大小相同
        ans = INF; ans1 = 0, ans2 = 0;
        dfs(0, 0, 0);
        /*
        for(int i = 0; i < len; i ++){
            if(flag == 0){
                if(s1[i] == s2[i]){
                    if(s1[i] == '?')
                        s1[i] = s2[i] = '0';
                }
                else if(s1[i] == '?' && s2[i] != '?'){
                    for(int j = i + 1; j < len; j ++){
                        if(s1[j] > s2[j] && s1[j] != '?' && s2[j] != '?'){
                            if(s2[j] + 10 - s1[j] > 5){ // 4?9 415
                                s1[i] = s2[i];
                                flag = 1;
                            }
                            else{
                                if(s2[i] != '0'){       // 4?9 414
                                    s1[i] = s2[i] - 1;
                                    flag = 2;
                                }
                                else s1[i] = s2[i], flag = 1;
                            }
                            break;
                        }
                        else if(s1[j] < s2[j] && s1[j] != '?' && s2[j] != '?'){
                            if(s1[j] + 10 - s2[j] >= 5){ // 4?5 409
                                s1[i] = s2[i];
                                flag = 2;
                            }
                            else{
                                if(s2[i] != '9'){       // 4?3 489
                                    s1[i] = s2[i] + 1;
                                    flag = 1;
                                }
                                else s1[i] = s2[i], flag = 2;
                            }
                            break;
                        }
                    }
                    
                }
                else if(s1[i] != '?' && s2[i] == '?'){
                    for(int j = i + 1; j < len; j ++){
                        if(s2[j] > s1[j] && s1[j] != '?' && s2[j] != '?'){
                            if(s1[j] + 10 - s2[j] > 5){ // 4?9 415
                                s2[i] = s1[i];
                                flag = 2;
                            }
                            else{
                                if(s1[i] != '0'){       // 4?9 414
                                    s2[i] = s1[i] - 1;
                                    flag = 1;
                                }
                                else s2[i] = s1[i], flag = 2;
                            }
                            break;
                        }
                        else if(s2[j] < s1[j] && s1[j] != '?' && s2[j] != '?'){
                            if(s2[j] + 10 - s1[j] >= 5){ // 4?5 409
                                s2[i] = s1[i];
                                flag = 1;
                            }
                            else{
                                if(s1[i] != '9'){       // 4?3 489
                                    s2[i] = s1[i] + 1, flag = 2;
                                }
                                else s2[i] = s1[i], flag = 1;
                            }
                            break;
                        }
                    }
                    
                }
                else if(s1[i] > s2[i]){
                    flag = 1;
                }
                else if(s1[i] < s2[i]){
                    flag = 2;
                }
            }
            else if(flag == 1){ // s1 > s2
                if(s1[i] == s2[i]){
                    if(s1[i] == '?'){
                        s1[i] = '0';
                        s2[i] = '9';
                    }
                }
                else if(s1[i] == '?' && s2[i] != '?'){
                    s1[i] = '0';
                }
                else if(s1[i] != '?' && s2[i] == '?'){
                    s2[i] = '9';
                }
            }
            else if(flag == 2){
                if(s1[i] == s2[i]){
                    if(s1[i] == '?'){
                        s1[i] = '9';
                        s2[i] = '0';
                    }
                }
                else if(s1[i] == '?' && s2[i] != '?'){
                    s1[i] = '9';
                }
                else if(s1[i] != '?' && s2[i] == '?'){
                    s2[i] = '0';
                }
            }
        }
         */
        int tmp1 = ans1, tmp2 = ans2, len1 = 0, len2 = 0;
        if(tmp1 == 0) len1 ++;
        while(tmp1){
            len1 ++;
            tmp1 /= 10;
        }
        if(tmp2 == 0) len2 ++;
        while(tmp2){
            len2 ++;
            tmp2 /= 10;
        }
        printf("Case #%d: ", casei);
        for(int i = 1; i <= len - len1; i ++){
            printf("0");
        }
        printf("%d ", ans1);
        for(int i = 1; i <= len - len2; i ++){
            printf("0");
        }
        printf("%d\n", ans2);
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

