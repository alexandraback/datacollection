#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"

int i,cs,c;
string x="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvzq";
string y="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upqz";
char A[257];
char str[101];

int main()
{
  for(i=x.size()-1;i>=0;i--)
    A[x[i]]=y[i];
  A[' ']=' ';
  scanf("%d ",&cs);
  for(c=1;c<=cs;c++)
  {
    gets(str);
    printf("Case #%d: ",c);
    for(i=0;i<strlen(str);i++)
      printf("%c",A[str[i]]);
    printf("\n");
  }
  return 0;
}
