#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> 
using namespace std;
  
typedef long long ll;
 
int main() {
 
   // freopen("input1.txt","r",stdin);
    freopen("D-small-attempt3.in","r",stdin);
   //freopen("D-large.in","r",stdin);
    freopen("output1.txt","w",stdout);
 
    int t, x, r, c, z = 0, flag, area;
 
    scanf("%d", &t);
    for(int ti=1;ti<=t;ti++) {
        scanf("%d %d %d", &x, &r, &c);
        area = r*c;
        if(x == 1) flag = 0;
        else if(x == 2){
            if(area % 2 )
                flag = 1;
            else flag = 0;
        }
        else if(x == 3) {
            if(area == 6 || area == 9 || area == 12) {
                flag = 0;
            }
            else flag = 1;
        }
        else {
            if(area == 12 || area == 16) {
                flag = 0;
            }
            else flag = 1;
        }
        if(flag)
            printf("Case #%d: RICHARD\n", ti);
        else printf("Case #%d: GABRIEL\n", ti);
    }
    return 0;
}