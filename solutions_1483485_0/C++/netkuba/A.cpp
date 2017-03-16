#include <cstdio>

char t[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int caseCount = 0;
void make() {
  char * buffer = new char[256];
  scanf(" %[^\n]", buffer);

  printf("Case #%d: ", ++caseCount);
  for(int i=0; (buffer[i] != NULL) && (buffer[i] != '\n'); ++i) {
    if (buffer[i] == ' ') printf("%c", ' ');
    else printf("%c", t[buffer[i] - 'a']);
  }
  printf("\n");

  return;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    make();
  }
  return 0;
}
