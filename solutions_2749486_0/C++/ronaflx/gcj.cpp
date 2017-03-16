/*
 * =====================================================================================
 *
 *       Filename:  gcj.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2013 05:06:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ronaflx
 *        Company:  hit-ACM-Group
 *
 * =====================================================================================
 */

#include <string>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 130000;

string walk(int x, int start) {
    char S = (x < 0) ? '1' : '0';
    if(x > 0) x = -x;
    int from = 0;
    string res = "";
    while(from != x) {
        from += start;
        start++;
        start = -start;
        res.append(1, S);
        S ^= 1;
    }
    return res;
}
int main() {
    int t, x, y;
    scanf("%d", &t);
    for(int cas = 1;cas <= t;cas++) {
        scanf("%d %d", &x, &y);
        string res0 = walk(x, 0);
        for(auto & i : res0) {
            if(i == '0') i = 'W';
            if(i == '1') i = 'E';
        }
        string res1 = walk(y, 0);
        for(auto & i : res1) {
            if(i == '0') i = 'S';
            if(i == '1') i = 'N';
        }
        string res = res0 + res1;
        printf("Case #%d: %s\n", cas, res.c_str());
    }
    return 0;
}
