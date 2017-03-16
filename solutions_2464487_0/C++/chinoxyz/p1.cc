#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;
int T;
int r, c;
long long sum;
int i;
int res;
int main(){
  scanf("%d", &T);
  printf("%d\n", T);
  for(int t = 0; t < T; t++){
    
    scanf("%d %d", &r, &c);
    sum = 0;
    res = 0;
      
    for(i = r+1; sum <= c; i+=2){
      sum += (i*i - (i-1)*(i-1));
      res++;
      //printf("%d ", sum);
    }
    if(sum != c ) res--;
    printf("Case #%d: %d\n", t+1, res);
    
    
  }
  
  
  
  
}
