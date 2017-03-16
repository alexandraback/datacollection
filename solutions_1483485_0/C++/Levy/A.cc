#include <cstdio>

const char orig[26] = { 
  'o', 'u', 'r', 'l', 'a', 'n', 'g', 'e', 'i', 's', 'm', 'p', 'b', 't', 'd', 'c',
  'f', 'h', 'j', 'k', 'q', 'v', 'w', 'x', 'y', 'z' };
const char rese[26] = {
  'e', 'j', 'p', 'm', 'y', 's', 'l', 'c', 'k', 'd', 'x', 'v', 'n', 'r', 'i', 'f',
  'w', 'b', 'u', 'o', 'z', 'g', 't', 'h', 'a', 'q' };

char s[200];

int main() {
  int n;
  scanf("%d", &n);
  gets(s);
  for (int c = 0; c < n; ++c) {
    gets(s);
    printf("Case #%d: ", c+1);
    for (int i = 0; s[i]; ++i) {
      char c = ' ';
      for (int j = 0; j < 26; ++j) 
	if (rese[j] == s[i]) {
	  c = orig[j];
	  break;
	}
      printf("%c", c);
    }
    printf("\n");
  }
}
