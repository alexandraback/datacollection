#include<cstdio>
#include<algorithm>
using namespace std;
int z, nr, a, b, n, m, k, w, kam, wynik;
int main()
{
  scanf("%d", &z);
  
  for(nr = 1; nr <= z; nr++)
  {
    scanf("%d%d%d", &n, &m, &k);
    wynik = k;
    for(a = 3; a <= n; a++)
    {
      kam = k;
      w = 0;
      if (b >= 2 && kam >= (a - 2) * 2)
      {
	w += (a - 2) * 2;
	kam -= 3;
	b = 2;
	while(b + 1 <= m && kam >= a)
	{
	  kam -= a;
	  w += 2;
	  b++;
	}
	if (kam > 0){w += 2;}
	wynik = min(wynik, w);
      }
    }
    printf("Case #%d: %d\n", nr, wynik);
  }
  
return 0;
}