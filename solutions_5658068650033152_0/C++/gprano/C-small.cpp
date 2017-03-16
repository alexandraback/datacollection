#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool stone[20][20];
bool fre[20][20];
int n,m,k;
int min_stone;

void freedom(int i, int j)
{
  if(i<0 || j<0 || i>=n || j>=m || fre[i][j] || stone[i][j])
    return;
  else
    {
      fre[i][j]=true;
      freedom(i+1,j);
      freedom(i-1,j);
      freedom(i,j-1);
      freedom(i,j+1);
    }
  return;
}
  
int nb_close()
{
  for(int i=0;i<n;i++)
    for(int j=0;j < m;j++)
      { fre[i][j]=false; }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(i==0 || j == 0 || i == n-1 || j==m-1)
	freedom(i,j);
  int k = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(!fre[i][j])
	k++;
    return k;
}

void parcours(int i, int j, int nb_stone)
{
  if(j==m)
    {
      int priso = nb_close();
      if(priso >= k)
	min_stone = min(min_stone,nb_stone);
    }
  else
    {
      int new_i=(i==n-1)?0:(i+1);
      int new_j=(i==n-1)?(j+1):j;
      stone[i][j]=true;
      parcours(new_i,new_j,nb_stone+1);
      stone[i][j]=false;
      parcours(new_i,new_j,nb_stone);
    }
  return;
}

int main()
{
  int nb_cas;
  scanf("%d",&nb_cas);
  for(int cas = 1; cas <= nb_cas; cas++)
    {
      printf("Case #%d: ",cas);
      scanf("%d%d%d",&n,&m,&k);
      for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	  stone[i][j]=false;
      min_stone = 1000000;
      parcours(0,0,0);
      printf("%d\n",min_stone);
    }
  return 0;
}
