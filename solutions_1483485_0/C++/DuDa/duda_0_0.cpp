#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
  char t1[26];
  t1[0]  = 'y'; //a
  t1[1]  = 'h'; //b
  t1[2]  = 'e'; //c
  t1[3]  = 's'; //d
  t1[4]  = 'o'; //e
  t1[5]  = 'c'; //f
  t1[6]  = 'v'; //g
  t1[7]  = 'x'; //h
  t1[8]  = 'd'; //i
  t1[9]  = 'u'; //j
  t1[10] = 'i'; //k
  t1[11] = 'g'; //l
  t1[12] = 'l'; //m
  t1[13] = 'b'; //n
  t1[14] = 'k'; //o
  t1[15] = 'r'; //p
  t1[16] = 'z'; //q
  t1[17] = 't'; //r
  t1[18] = 'n'; //s
  t1[19] = 'w'; //t
  t1[20] = 'j'; //u
  t1[21] = 'p'; //v
  t1[22] = 'f'; //w
  t1[23] = 'm'; //x
  t1[24] = 'a'; //y
  t1[25] = 'q'; //z

  char s1[1000];
  char s2[1000];
  int T;
  int tc = 1;
  int i = 0;

  scanf("%d\n", &T);
  while(tc <= T)
  {
    char c;
    char c2;
    scanf("%c", &c);
    s1[i] = c;
    int d = static_cast<int>(c);
    if(d >= 97) {
      d -= 97;
    } else {
      d -= 65;
    }
    if((d >= 0) && (d < 26))
    {
      c2 = t1[d];
      if(' ' == c2) {
        c2 = c;
      }
    } else {
      c2 = c;
    }

    s2[i] = c2;
    ++i;

    if('\n' == c) {
      s1[i] = '\0';
      s2[i] = '\0';
      //printf("Case #%d: %s", tc, s1);
      printf("Case #%d: %s", tc, s2);
      ++tc;
      i = 0;
    } 
  }
}
