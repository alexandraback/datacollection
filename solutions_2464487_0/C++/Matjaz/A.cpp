#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std; 

int T;

long long solve(long long r,long long t){
     long long l=1;
     long long d=min((long long)sqrt(t)+1,t/(2*r));
     while (l<d){
           long long mid=l+(d-l+1)/2;
           if (mid*(2*r+1)+2*(mid-1)*mid>t){
              d=mid-1;
              } else l=mid;
           }
     return l;
     }

int main(){
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        long long r,t;
        scanf("%I64d %I64d",&r,&t);
        printf("Case #%d: %I64d\n",i+1,solve(r,t));
        }
    return 0;
    }
