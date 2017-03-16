#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define LL long long
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;
const int N = 55;
const int M = 10000;
int nr[N], gdzie[N];
int per[N];
bool odw[N];
vector<int>V[N];
int n, m, a, b;
pair<int, int>tab[N];
bool cmp(int a, int b)
{
  return tab[a] < tab[b];
}
int DFS(int w, int szuk)
{
  odw[w] = 1;
  if(nr[w] == per[szuk])
    szuk++;
 for(int j=0; j <V[w].size(); j++){
  for(int i=0; i<V[w].size(); i++)
  {
    int u = V[w][i];
    if(odw[u] == 0 && nr[u] == per[szuk])
    {
      szuk = DFS(u, szuk);
    }
  }
 }
  return szuk;
}
   
int main()
{
  int t;
  scanf("%d", &t);
  for(int z=1; z<=t; z++)
  {
    printf("Case #%d: ", z);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
    {
      V[i].clear();
      odw[i] = 0;
      scanf("%d", &tab[i].ff);
      tab[i].ss = i;
    }
    for(int i=1; i<=m; i++)
    {
      scanf("%d %d", &a ,&b);
      V[a].PB(b);
      V[b].PB(a);
    }
    



    sort(tab+1, tab+1+n);
    for(int i=1; i<=n; i++)
    {
      nr[tab[i].ss] = i;
      gdzie[i] = tab[i].ss;
    }
    for(int i=1; i<=n; i++)
    {
      per[i] = i;
    }
    do
    {
      for(int i=1; i<=n; i++)odw[i] = 0;
      if(DFS(gdzie[per[1]], 2) == n+1)
      {
	for(int i=1; i<=n; i++)
	{
	  printf("%d", tab[per[i]].ff);
	}
	printf("\n");
	break;
      }
      
    }while(next_permutation(per+1, per+1+n));
  }
  return 0;
}