#include <iostream>
#include <stdio.h>
using namespace std;

char m[4][10];

bool isfull() {
  for (int i=0; i<4; i++)  
    for (int j=0; j<4; j++)
      if (m[i][j] == '.') return false;
  return true;
}

bool check(char x) {
  for (int i=0; i<4; i++) {
    bool t = true;
    for (int j=0; j<4; j++)
      if (m[i][j] != x && m[i][j] != 'T') {
        t = false; break;
      }
    if (t) return true;
  }

 for (int i=0; i<4; i++) {
    bool t = true;
    for (int j=0; j<4; j++)
      if (m[j][i] != x && m[j][i] != 'T') {
        t = false; break;
      }
    if (t) return true;
  }

  bool t = true;
 for (int j=0; j<4; j++)
   if (m[j][j] != x && m[j][j] != 'T')
     t =  false;
  if (t) return true;
  
  for (int j=0; j<4; j++)
   if (m[j][3-j] != x && m[j][3-j] != 'T')
     return  false;
 return true;
}
int main() {
  int T, TC= 1;
  scanf("%d", &T);
  while (T--) {
    for (int i=0; i<4; i++)
      scanf("%s", m[i]);
    //puts("here");
    if (check('X')) printf("Case #%d: X won\n", TC++);
    else if (check('O')) printf("Case #%d: O won\n", TC++);
    else if (isfull()) printf("Case #%d: Draw\n", TC++);
    else printf("Case #%d: Game has not completed\n", TC++);
  }
} 
