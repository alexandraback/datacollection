#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
int a[510];
int set2[510];

int main(){
    freopen("2.out", "w", stdout);
    int t;
    cin >> t;
    for(int testCases = 1; testCases <= t; testCases++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        printf("Case #%d:\n", testCases); 
       
        int end = pow(2, n);
        int cnt = 0; 
        bool flag = false;
        for(int i = 0; i < end && !flag; i++){
            int mask = i;
            int sum1 = 0, sum2 = 0;
            for(int k = 0; k < n; k++){
               if(mask & 1 == true){
                    sum1 += a[k];
               }
               else
                   sum2 += a[k];
               mask >>= 1;
               if(sum1 == sum2){
                   mask = i;
                   for(int j = 0; j <= k; j++){
                       if(mask & 1 == true)
                           printf("%d ", a[j]);
                        else
                            set2[cnt++] = a[j];
                        mask >>= 1;
                   }
                   putchar('\n');
                   for(int j = 0; j < cnt; j++)
                       printf("%d ", set2[j]);
                   putchar('\n');
                   flag = true;
                   break;
               }
            }
        }
        if(!flag)
            cout << "Impossible" << endl;
    }

    return 0;
}
