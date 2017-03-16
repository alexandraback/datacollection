#include <cstdio>
#include <cstdlib>

char trans[26] = {'y', // a
  'h',
  'e',
  's',
  'o', // e
  'c',
  'v',
  'x',
  'd', // i
  'u',
  'i',
  'g',
  'l', // m
  'b',
  'k',
  'r',
  'z', // q
  't',
  'n',
  'w',
  'j', // u
  'p',
  'f',
  'm',
  'a',
  'q'}; //z

int N;
int main()
{
  scanf("%d\n", &N);
  for(int i = 1; i <= N; i++)
  {
    unsigned char str[200];
    scanf("%[^\n]\n", str);
    printf("Case #%d: ", i);
    unsigned char *p = str;
    while(*p) {
      if(*p == ' ') printf(" ");
      else printf("%c", trans[*p-'a']);
      *p++;
    }
    printf("\n");
  }
}

