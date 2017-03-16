#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T;
int N;
int i;

char v[100][10000];
char s[10000];
int pos[100];

bool check()
{  
  int i, j;
  
  int used[26];
  for (i = 0; i < 26; i++) used[i] = 0;
  
  char c = v[pos[0]][0];
  used[(int)(c-'a')] = 1;
  i = 0; j = 1;
  while (i < N) {
    //printf("%s\n", st.c_str());
    while (v[pos[i]][j] != 0) {
      if (v[pos[i]][j] != c) {
        c = v[pos[i]][j];
        if (used[(int)(c-'a')] != 0) return false;
        used[(int)(c-'a')] = 1;
      }
      j++;
    }
    i++; j = 0;
  }  
  //printf("%s\n", st.c_str());  
  return true;
}

int main() {

  scanf("%d", &T);
  int c = 0;
  while (T--) {
    c++;
      
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
      scanf("%s", v[i]);      
      pos[i] = i;
    }
    
    int sol = 0;
    if (check()) sol++;
    while (next_permutation(pos, pos+N)) {
      if (check()) sol++;
    }   
    
    
    printf("Case #%d: %d\n", c, sol);
  }
  
  
  return 0;
}