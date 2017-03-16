#include<cstdio>
int t, a, b, k, i, j, x, nr, wynik;
int main()
{
  scanf("%d", &t);
  
  for(nr = 1; nr <= t; nr++)
  {
    scanf("%d%d%d", &a, &b, &k);
    
    wynik = 0;
    
    for(i = 0; i < a; i++)
    {
      for(j = 0; j < b; j++)
      {
	x = i&j;
	if (x < k){wynik++;}
      }
    }
    printf("Case #%d: %d\n", nr, wynik);
  }
  
  
return 0;
}