#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstring>


using namespace std;

long int t;
double c , f , x;

int main()
{
    
    freopen("jam2large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    long int i , j , k;
    double b , d , ans , a;
    scanf("%ld" , &t);
    k = 1;
    while(k <= t) {
            
            
            
            scanf("%lf %lf %lf" , &c , &f , &x);
            
            ans = 0;
            a = 2;
            //coins_left = 0;
            while(1) {
                     b = x/a;
                     d = c/a + x/(a + f);
                     
                     if(d < b) {
                          ans = ans + c/a;
                          a = a + f;
                     } else {
                          ans = ans + x/a;
                          break;
                     }
            }
            printf("Case #%ld: %lf\n" , k , ans);
            k++;
    }
    //system("pause");
    return 0;
}
