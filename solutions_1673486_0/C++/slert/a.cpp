#include <cstdio>
#include <cstdlib>
#include <cstring>

double p[100010];

int main()
{
  freopen("A-small-attempt0.in","r", stdin);
  freopen("A-small-attempt0.out","w", stdout);
  int tc;
  scanf("%d", &tc);
  for(int ti = 1; ti <= tc; ti++)
    {
      int a,b;
      scanf("%d%d", &a, &b);
      for(int i = 0; i < a; i++)
	scanf("%lf", &p[i]);
      double beste = b+2;
      double pnow = 1;
      for(int i = a; i >= 0; i--)
	{
	  if(i<a)pnow*=p[a-i-1];
	  double t = b-a+1+2*i+(1-pnow)*(b+1);
	  if(t < beste)beste=t;
	}
      printf("Case #%d: %.6lf\n", ti, beste);
    }
}
