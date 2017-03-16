#include <stdio.h>
#include <string.h>

#define SIZE 200

int T;
int n;
char s[SIZE];
int len;
int i, j, l;
int sol;

bool isCons(char c)
{
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return false;  
  return true;
}

bool seq(int b)
{
  int i;
  for (i = 0; i < n; i++)
    if (!isCons(s[b+i])) return false;
    
  return true;  
}

bool check(int b, int e)
{
   int i; 
   for (i = b; i <= e-n+1; i++) 
     if (seq(i)) return true;
     
   return false;  
}


int main() {

  scanf("%d", &T);
  int c = 0;
  while (T--) {
    c++;
    scanf("%s %d", s, &n);
    len = strlen(s);
    
    sol = 0;
    for (l = n; l <= len; l++)
      for (i = 0; i <= len-l; i++) {
	j = i + l - 1;
	if (check(i, j)) sol++;
      }
    
    printf("Case #%d: %d\n", c, sol);
  }
  return 0;
}