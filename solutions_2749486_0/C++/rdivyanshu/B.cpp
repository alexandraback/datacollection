#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;
typedef long long int64;

void solve_case(){
     int64 a, b;  scanf("%lld %lld", &a, &b);
     int64 sp = 0;
     for(int64 i =0;  ; ++i){
           int64 s = i*(i+1);  s /= 2;
           if(s%2 == (abs(a+b))%2 && abs(a) <= i && abs(b) <= i) {
                 sp = i; break;
           }
     }
     
     string res = "";

     while(sp) { 
          int64 na = a; int64 nb = b;  int64 sm = (1LL<<60); 
          char dir;
          for(int i=-sp; i<=sp; i += sp)
             for(int j=-sp; j<=sp; j += sp) if(abs(i) + abs(j) == sp) {
                     int64 pa = a + i; int64 pb = b + j;
                     if(abs(pa) + abs(pb) <= sm ) {
                               if(i == -sp ) dir = 'E'; 
                               if(i == sp)  dir = 'W';
                               if(j == -sp) dir = 'N';
                               if(j == sp) dir = 'S';
                               sm = abs(pa) + abs(pb); 
                               na = pa;  nb = pb; 
                     }
             } 
          res += dir;
          a = na; b = nb;
          sp -= 1;
    } 
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main(){
   int tcase; scanf("%d", &tcase);
   for(int tc = 1; tc <= tcase; ++tc){
       printf("Case #%d: ",tc);
       solve_case();
   }
   return 0;
}
