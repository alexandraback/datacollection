#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url    
 * @status  
 */


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T, t, r, w, c;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &r, &c, &w);
        printf("Case #%d: %d\n", t, ((int) ceil((r * c) / (w * 1.))) + w - 1);
    }
    return 0;
}
