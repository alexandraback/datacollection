// =====================================================================================
// 
//       Filename:  C.cpp
// 
//    Description:  
// 
//        Version:  0.01
//        Created:  04/08/2016 21:17:21
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

int n, m, k, t, c, s;

long long talk (int st, int k, int c) {
    long long ret = st;
    int str = st+1;
    
    for (int i = st; i < st+c-1 && str <= k; ++i, ++str) {
//        cout << endl << endl << i << " " << st << " " << c << endl << endl;
        ret = (ret-1) * k + i+1;
    }
    return ret;
}
void gorun(int k, int c, int s) {
   if (c * s < k) {
       cout << "IMPOSSIBLE" << endl;
       return ;
   }
   c = min(c, k);
   bool first = true;
   int st = 1;
   while (st <= k) {
       long long guess = talk (st, k, c);
       st += c;
       
       if(!first) {
           cout << " ";
       }
       first = false;
       cout << guess;
   }
   cout << endl;
}
int main() {
    scanf("%d", &t);
    
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        scanf("%d %d %d", &k, &c, &s);
        
        gorun(k, c, s);
    }
    return 0;
}

