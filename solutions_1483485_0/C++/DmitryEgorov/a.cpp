#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int l, A[26]={24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 16, 19, 13, 22, 9, 15, 5, 12, 0, 16};
char s[120];

int main()
{
  int t, cnt, i;
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d ", &t);
  A[(int)('y'-'a')]=(int)('a'-'a');
  A[(int)('e'-'a')]=(int)('o'-'a');
  A[(int)('q'-'a')]=(int)('z'-'a');
 /* for (i=0; i<26; i++)
    for (j=0; j<26; j++)
      if (A[i]==A[j])
        cerr<<i<<" !!! "<<j<<endl;     */
  for (cnt=1; cnt<=t; cnt++)
  {
    gets(s), l=strlen(s);
    for (i=0; i<l; i++)
      if (s[i]!=' ')
      s[i]=(char)(A[(int)(s[i]-'a')]+'a');
    printf("Case #%d: ", cnt), s[l]=0, puts(s);
  }
  return 0;
}
