#include<cstdio>
int z, nr, p, q, x, y, pom; 
int main()
{
  scanf("%d", &z);
  
  for(nr = 1; nr <= z; nr++)
  {
    scanf("%d/%d", &p, &q);
    x = 0;
    while(q > 1)
    {
      if (q % 2 != 0){break;}
      q /= 2;
      x++;
    }
    printf("Case #%d: ", nr);
    if (p % q != 0){printf("impossible\n");}
    else
    {
      p /= q;
      pom = 1;
      for(y = 0; 2 * pom <= p; y++)
      {
	pom *= 2;
      }
      printf("%d\n", x - y);
    }
  }
  
return 0;
}