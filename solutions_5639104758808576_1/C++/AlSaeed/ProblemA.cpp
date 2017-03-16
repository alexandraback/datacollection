#include <cstdio>

int main()
{
  int n;
  char g;
  scanf("%d%c",&n,&g);
  for(int c=1;c<=n;c++)
    {
      int s;
      scanf("%d%c",&s,&g);
      int counter = 0;
      int sum=0;
      for(int i=0;i<=s;i++)
	{
	  int a;
	  scanf("%c",&g);
	  a=g-'0';
	  if(sum+counter<i)
	    counter += i-sum-counter;
	  sum+=a;
	}
      printf("case #%d: %d\n",c,counter);
      scanf("%c",&g);
    }
  return 0;
}
