#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
const int NUM = 1e3;
char s[NUM],ans[NUM*2];

int main(){
    int T;
    scanf("%d",&T);
    for(int _i = 1 ; _i <= T; _i++){
        scanf("%s",s);
        int len = strlen(s);
        int l = len-2 , r = len - 1;
        ans[r++] = s[0];  
        bool fg;
        for(int i = 1 ; i < len ; i++){
            if(s[i] >= ans[l + 1]) fg = true;
            else
                fg = false;
            if(fg) ans[l--] = s[i];
            else
                ans[r++] = s[i];
        }
        ans[r] = '\0';
        printf("Case #%d: %s\n",_i,ans+l+1);
    }
    return 0;
}