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

vector<long long> num;

int T;

bool isPal(long long x){
     vector<int> s;
     while (x>0){
           s.push_back(x%10);
           x=x/10;
           }
     for (int i=0;i<s.size();i++){
         if (s[i]!=s[s.size()-i-1]) return false;
         }
     return true;
     
     }

  
     
int main(){
    for (long long i=1;i<=10000000;i++){
        if (isPal(i)&&isPal(i*i)) num.push_back(i*i);
        }       
    scanf("%d",&T); 
    for (int i=0;i<T;i++){
        long long a,b;
        int res=0;
        scanf("%I64d %I64d",&a,&b);
        for (int j=0;j<num.size();j++){
            if (num[j]>=a&&num[j]<=b) res++;
            }
        printf("Case #%d: %d\n",i+1,res);
        }      
    return 0;
    }     
