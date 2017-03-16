#include <cstdio>
#include <cstring>

char buf[1000002];

bool is_consonant(char c) {
  switch(c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return false;
  default:
    return true;
  }
}

int main() {
  int T,n,L;
  scanf("%d",&T);
  for (int tc=1; tc<=T; tc++) {
    scanf("%s %d\n",buf, &n);
    L = strlen(buf);

    int res = 0;
    int beg = 0;

    int len = 0;

    for (int i=0; i<L; i++) {
      if (is_consonant(buf[i]))
	len++;
      else
	len = 0;

      if (len >= n) {
	int poczatki = i-beg-n+2;
	int konce = L-i;
	
	res += poczatki*konce;
	beg = i-n+2;
      }
    }
    
    printf("Case #%d: %d\n",tc,res);
  }
}
