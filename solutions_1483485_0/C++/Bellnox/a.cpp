#include <iostream>
#include <map>
#include <stdio.h>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;

map<char, char> m;
char buf[1024];

void init()
{
  vector<string> s1, s2;
  s1.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
  s1.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
  s1.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
  s1.push_back("y n f i c w l b k u o m x s e v z p d r j g a t h a q set k oset xa ynfd");
  s2.push_back("our language is impossible to understand");
  s2.push_back("there are twenty six factorial possibilities");
  s2.push_back("so it is okay if you want to just give up");
  s2.push_back("a b c d e f g h i j k l m n o p q r s t u v y w x y z now i know my abcs");
  for(int i = 0; i < s1.size(); i++)
  {
    for(int j = 0; j < s1[i].length(); j++)
    {
      m[s1[i][j]] = s2[i][j];
    }
  }
}

int main() 
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  init();
  int n;
  scanf("%d", &n);
  gets(buf);
  for(int t = 0; t < n; t++)
  {
    memset(buf, 0, sizeof(buf));
    gets(buf);
    printf("Case #%d: ", t + 1);
    for(int i = 0; i < strlen(buf); i++)
    {
      printf("%c", m[buf[i]]);
    }
    printf("\n");
  }
  return 0;
}