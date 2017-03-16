#include<cstdio>
#include<algorithm>

const int MAXN = 107;
int tab[MAXN];

int solve()
{
  long long a;
  int n;
  scanf("%lld%d", &a, &n);
  for(int i=0; i<n; i++)
    scanf("%d", &tab[i]);
  std::sort(tab, tab + n);
  int li;
  for(li=0; li<n; li++)
    if(a>tab[li])
      a += tab[li];
    else
      break;
  int pozo = n-li;
  //printf("\nli: %d\n pozo: %d\n", li, pozo);
  int wyn = pozo, tmp = 0;
  for( ; li<n; li++)
  {
    wyn = std::min(tmp+n-li, wyn);
    while(a<=tab[li])
    {
      a += a-1;
      tmp++;
      if(tmp>wyn)
	break;
    }
    if(tmp>wyn)
      break;
    a += tab[li];
  }
  return wyn = std::min(tmp+n-li, wyn);;
}

int main()
{
  int t;
  scanf("%d", &t);
  for(int ti=1; ti<=t; ti++)
    printf("Case #%d: %d\n", ti, solve());
  return 0;
}