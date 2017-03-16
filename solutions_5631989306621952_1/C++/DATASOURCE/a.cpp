/*=============================================================================
# Author:			He Shuwei
# Last modified:	2016-04-16 09:07
# Filename:			a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int Case = 1; Case <= t; Case++){
        string ch;
        cin >> ch;
        string res = "";
        res += ch[0];
        int dx = 1;
        for(int i = 1; i < ch.size(); i++){
            string t1 = ch[i] + res;
            string t2 = res + ch[i];
            if(t1 >= t2) res = t1;
            else res = t2;
            dx++;
        }
        cout <<"Case #"<< Case <<": "<< res << endl;
    }
    return 0;
}

