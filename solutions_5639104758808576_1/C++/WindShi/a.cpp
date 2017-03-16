#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n;
char str[1001];

int main(){
     freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
     scanf("%d", &test);
     for (int uu = 1; uu <= test; uu++)
     {
          printf("Case #%d: ", uu);
          scanf("%d%s", &n, str);
          for (int i = 0; i <= 10000; i++)
          {
               bool ok = true; int cnt = i;
               for (int j = 0; j <= n && ok; j++)
                    if (j > cnt) ok = false;
                    else cnt += str[j] - '0';
               if (ok)
               {
                    printf("%d\n", i);
                    break;
               } 
          }
     }
}
          
     
