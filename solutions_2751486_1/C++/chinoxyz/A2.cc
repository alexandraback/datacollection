#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iostream>
#include <set>

#define inf 0x3f3f3f3f

using namespace std;
char s[1000009];
int d, n;

bool  vowel(char a){
  if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
  return false;
}
class par{
public:
  int x; int y;
  bool operator< (const par &s) const{
    return x < s.x && y < s.y;
  }
  bool operator== (const par &s) const{
    return x == s.x && y == s.y;
  }
};


long long sol;


long long int func(){
  char c;
  int sum;
  int k;
  int num = 0;
  sum = 0;
  int first = 0;
  for(k = 0; k< d; k++){
    if(!vowel(s[k])) sum++;
    else sum = 0;
    if(sum >= d){
      //cout << k << " " << (k+2-d)*(n-k) << endl;
      sol += (k+2-d)*(n-k);
      first = 1;
    }
  }
  for(int i = d; i < n; i++){
    if(!vowel(s[i])) sum++;
    else sum = 0;
    
    if(sum >= d){
      //cout << first <<" "<< i << " " << (i+2-d)*(n-i)- (first)*(n-i) << endl; //(i+2-d)*(n-i)
      sol += (i+2-d)*(n-i)- (first)*(n-i);
      //if(first == 0){
      first = i-k+2;
      //}
      num++;
    }
    
  }
  
  /*
  
      }*/
  return sol;
}

int main(){
  int T;
  scanf("%d\n", &T);
  for(int t = 0; t < T; t++){
    scanf("%s %d\n", s, &d);
    n = strlen(s);
    sol = 0;
    printf("Case #%d: %lld\n", t+1, func());
  }
}
