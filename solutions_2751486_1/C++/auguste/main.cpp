#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int nbTests;
char str[1000001];

bool f(char c)
{
   return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main()
{
   scanf("%d", &nbTests);
   for(int test=0; test<nbTests; test++)
   {
      int n;
      scanf("%s%d", str, &n);
      int a = -1, b = 0, l = strlen(str);
      long long t = 0;
      for(int i=0; i<l; i++)
      {
         if(f(str[i])) b++;
         else b = 0;
         if(b >= n)
            a = i - n + 1;
         if(a >= 0)
            t += a + 1;
      }
      printf("Case #%d: %lld\n", test+1, t);
   }
}
