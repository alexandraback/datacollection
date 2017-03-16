#include<cstdio>
unsigned long long int z, nr, p, q, x, y, pom; 
int main()
{
  scanf("%llu", &z);
  
  for(nr = 1; nr <= z; nr++)
  {
    scanf("%llu/%llu", &p, &q);
    x = 0;
    while(q > 1)
    {
      if (q % 2 != 0){break;}
      q /= 2;
      x++;
    }
    printf("Case #%llu: ", nr);
    if (p % q != 0){printf("impossible\n");}
    else
    {
      p /= q;
      pom = 1;
      for(y = 0; 2 * pom <= p; y++)
      {
	pom *= 2;
      }
      printf("%llu\n", x - y);
    }
  }
  
return 0;
}