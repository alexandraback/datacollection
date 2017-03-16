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

bool visit[100][100];
int sol;
set<par> conj;

int func(){
  char c;
  memset(visit, 0, sizeof(visit));
  for(int i = 0; i <= n; i++){
    int num = 0;
    int maxnum = 0;
    for(int j = i; j <= n; j++){
      maxnum = max(maxnum, num);
      if(vowel(s[j])) num = 0;
      else num++;
      if(maxnum >= d){
        for(int k = 0; k <= i; k++){
          
          
          if(!visit[k][j]){
            
            visit[k][j] = true;
            sol++;
          }
          
        }
      }
      
    }
    //cout << i << " " << maxnum << endl;
    
    
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
    printf("Case #%d: %d\n", t+1, func());
  }
}
