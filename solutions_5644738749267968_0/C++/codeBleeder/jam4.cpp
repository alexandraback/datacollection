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
#include <math.h>
using namespace std;

long int t, n;
double arr1[10001] , arr2[10001];

int main()
{
    freopen("jam4.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    long int i , j , k , a, b , c , ans1 , ans2 , count;
    scanf("%ld" , &t);
    k = 1;
    while(k <= t) {
            scanf("%ld" , &n);
            for(i = 1; i <= n; i++) {
                  scanf("%lf" , &arr1[i]);
            }
            for(i = 1; i <= n; i++) {
                  scanf("%lf" , &arr2[i]);
            }
            
            sort(&arr1[1] , &arr1[n + 1]);
            sort(&arr2[1] , &arr2[n + 1]);
            
            /*for(i = 1; i <= n; i++) {
                  printf("%lf" , &arr1[i]);
            }
            for(i = 1; i <= n; i++) {
                  printf("%lf" , &arr2[i]);
            }*/
            
            a = 1;
            b = n;
            
            while((arr1[n] < arr2[b]) && (b >= 1)) {
                          b--;
                          a++;
            }
            //cout << a << " " << b << "\n";
            ans1 = 0;
            i = 1;
            count = 0;
            while((i <= b) && (a <= n)) {
                    //cout << arr1[a] << " " << arr2[i] << "\n";
                    if(arr1[a] > arr2[i]) {
                               
                               a++;
                               i++;
                               count++;
                               ans1++;
                    } else {
                           a++;
                    }
            }
            //cout << count << "\n";
            a = 1;
            b = 1;
            ans2 = 0;
            while(b <= n) {
                    if(arr2[b] > arr1[a]) {
                               a++;
                               b++;
                               ans2++;
                    } else {
                           b++;
                    } 
            }
            ans2 = n - ans2;
            printf("Case #%ld: %ld %ld\n" , k , ans1 , ans2);
            //cout << ans1 << " " << ans2 << "\n";
            k++;
    }
    //system("pause");
    return 0;
}
