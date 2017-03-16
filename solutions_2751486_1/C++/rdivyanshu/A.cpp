#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int64;

int n;
char input[1000007];


bool is_vowel(char c){
    return c == 'a' || c == 'e' ||  c =='i' || c == 'o' || c == 'u';
}

int64 solve_case(){

     scanf("%s %d", input, &n);
     int ct = 0; int idx = -1;
     int len = strlen(input);
     int64 res = 0;
   
     for(int i=0; i<len; ++i){
         if(is_vowel(input[i])) ct = 0;
         else {
              ct += 1;
         }
         if(ct>=n) {
            idx = i-n+1;
         }
         if(idx != -1) {
              res += (idx+1);
         }
     }
     return res;
}

int main(){
    int tcase; scanf("%d", &tcase);
    for(int i=1; i<=tcase; ++i){ 
         printf("Case #%d: %lld\n", i, solve_case());
    }
    return 0;
}
