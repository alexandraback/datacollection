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

struct node {
       long int quo;
       long int rem;
};

long int t , r , c , m;

int main()
{
    freopen("att5large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    long int i , j , k , a , b , d , l , n;
    struct node p; 
    long int arr[1000][1000];
    scanf("%ld" , &t);
    k = 1;
    while(k <= t) {
            scanf("%ld %ld %ld" , &r , &c , &m);
            printf("Case #%ld:\n" , k);
            a = 0;
            for(i = 1; i <= r; i++) {
                  for(j = 1; j <= c; j++) {
                        arr[i][j] = 0;
                  }
            }
            b = m;
            if(r == 1 || c == 1) {
                 a = r * c - m;
                 if(a >= 1) {
                      a = a - 1;
                      for(i = 1; i <= r; i++) {
                            for(j = 1; j <= c; j++) {
                                  if(i == 1 && j == 1) {
                                       printf("c");
                                  } else if(a > 0) {
                                       printf(".");
                                       a--;
                                  } else {
                                       printf("*");
                                  }
                            }
                            printf("\n");
                      }
                 } else {
                        printf("Impossible\n");
                 }
            } else {
                   a = r*c - m;
                   //cout << a << "\n";
                   if(a == 1) {
                        for(i = 1; i <= r; i++) {
                              for(j = 1; j <= c; j++) {
                                    if((i == 1) && (j == 1)) {
                                          printf("c");
                                    } else {
                                          printf("*");
                                    }
                              }
                              printf("\n");
                        }
                   } else {
                         for(i = 2; i <= c; i++) {
                               p.quo = a/i;
                               p.rem = a%i;
                               d = 0;
                               if(p.quo < 2) {
                                  d = 1;
                                  continue;
                               }
                               if(p.rem != 0) {
                                  if((p.quo + 1) > r) {
                                            d = 1;
                                            continue;
                                  }
                               } else if(p.quo > r){
                                 d = 1;
                                  continue;
                               }
                               if(p.rem == 1) {
                                    d = 1;
                                    if(p.quo > 2) {
                                           p.rem = p.rem + i;
                                           if((p.rem/2) >= 2) {
                                                        d = 2;
                                                        p.quo--;
                                                        break;
                                           }
                                           
                                    }
                                    continue;
                               } else {
                                 break;
                               }
                         }
                         //cout << p.quo << " " << p.rem << "\n";
                         if((i != (c + 1)) && (d != 1)) {
                        
                        
                               for(j = 1; j <= p.quo; j++) {
                                     for(l = 1; l <= i; l++) {
                                           arr[j][l] = 1;
                                     }
                               }
                               if(d == 0) {
                                    for(l = 1; l <= p.rem; l++) {
                                           arr[j][l] = 1;
                                    }
                               } else {
                                      if(p.rem%2 == 0) {
                                                 for(l = 1; l <= p.rem/2; l++) {
                                                       arr[j][l] = 1;
                                                 }
                                                 j++;
                                                 for(l = 1; l <= p.rem/2; l++) {
                                                       arr[j][l] = 1;
                                                 }      
                                      } else {
                                             for(l = 1; l <= (p.rem/2 + 1); l++) {
                                                   arr[j][l] = 1;
                                             }
                                             j++;
                                             for(l = 1; l <= p.rem/2; l++) {
                                                   arr[j][l] = 1;
                                             }   
                                      } 
                               }
                               for(j = 1; j <= r; j++) {
                                     for(l = 1; l <= c; l++) {
                                           if(l == 1 && j == 1) {
                                                printf("c");
                                           } else if(arr[j][l] == 1) {
                                                  printf(".");
                                           } else {
                                                  printf("*");
                                           }
                                     }
                                     printf("\n");
                               }
                        } else {
                               printf("Impossible\n");
                        }
                   }
                  
            }
            k++;
    }
    //system("pause");
    return 0;
}
