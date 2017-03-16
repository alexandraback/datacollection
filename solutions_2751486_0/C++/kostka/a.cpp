#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 1000007;
char buf[MAXN];

long long solve()
{
  long long wyn = 0;
  int n, ile = 0, ost = -1;
  scanf("%s", buf);
  int dl = strlen(buf);
  scanf("%d", &n);
  //printf("DL %d\n", dl);
  for(int i=0; i<dl; i++)
  {
    if(!(buf[i]=='a' || buf[i]=='i' || buf[i]=='e' || buf[i]=='o' || buf[i]=='u'))
      ile++;
    int wcz = i-n;
    if(wcz>=0 && (!(buf[wcz]=='a' || buf[wcz]=='i' || buf[wcz]=='e' || buf[wcz]=='o' || buf[wcz]=='u')))
      ile--;
    if(ile == n)
    {
      //printf("X %d %d\n", i-n-ost+1, dl-i);
      wyn += (i-n-ost+1) * (dl-i);
      ost = i-n+1; 
    }
  }
  return wyn;
}

int main()
{
  int t;
  scanf("%d", &t);
  for(int ti=1; ti<=t; ti++)
    printf("Case #%d: %lld\n", ti, solve());
  return 0;
}