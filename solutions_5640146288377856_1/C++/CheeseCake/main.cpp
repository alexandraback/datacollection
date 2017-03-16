#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> etats; //0 pas demandé, 1 demandé mais vide, 2 touché
vector<int> possibles;

int test(int r, int c, int w)
{
  int resultat = (r-1) * (c/w); 
  if( (c % w) == 0)
    resultat += (c/w) + w - 1;
  else resultat += (c/w) + w;
  return resultat;
}

int main()
{
  int nbcases;
  scanf("%d",&nbcases);
  for(int cas = 0; cas < nbcases; cas++)
  {
    int r,c,w;
    scanf("%d%d%d",&r,&c,&w);
    printf("Case #%d: %d\n", cas+1, test(r,c,w));
  }
  return 0;
}
