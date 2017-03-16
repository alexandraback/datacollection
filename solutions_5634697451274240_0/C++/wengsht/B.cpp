// =====================================================================================
// 
//       Filename:  B.cpp
// 
//    Description:  
// 
//        Version:  0.01
//        Created:  04/08/2016 20:45:03
//       Revision:  none
//       Compiler:  clang 3.5
// 
//         Author:  wengsht (SYSU-CMU), wengsht.sysu@gmail.com
//        Company:  
// =====================================================================================



/*
ID: wengsht1
LANG: C++
TASK: test
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <sstream>
#include <set>
using namespace std;

#define MX 100005
#define REP(i,n) for(int i=0;i<(n);i++)
#define OREP(i,n) for(int i=1;i<=(n);i++)

typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       UINT;

int n, m, k, t;
#define HAPPY '+'
#define SAD   '-'

char current;

int main() {
    scanf("%d", &t);
    char input[10000];
    
    for (int c = 1; c <= t; ++c) {
        printf("Case #%d: ", c);
        
        scanf("%s", input);
        
        current = HAPPY;
        
        int len = strlen(input);
        
        int ret = 0;
        

        for (int i = len - 1;i >= 0; --i) {
            if (current != input[i]) {
                current = (current == HAPPY ? SAD : HAPPY);
                ret ++;
            }
        }
        
        printf("%d\n", ret);
    }
    return 0;
}

