#include <stdio.h>

int T;
int Smax;
char S[2000];

int freinds;

int main ()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int t,s;
  int sum;
  scanf("%d",&T);

  for(t = 1; t <= T; t++ )
  {
    sum = 0;
    freinds = 0;
    
    scanf("%d",&Smax);
	scanf("%s",S);

    for( s = 0; s <= Smax; s++ )
    {
      while (sum < s)
      {
         sum++;
         freinds++;
      }
      sum += S[s] - '0';
    }
    printf("Case #%d: %d\n",t,freinds);
  }

  return 0;
}