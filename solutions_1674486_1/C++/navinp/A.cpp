#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 1001;
int E[MAX][MAX];
vector < int >v;
int visit[MAX][MAX];
int node[MAX];
int N;
int dia;

void
dfs (int x)
{
//printf("x:%d\n",x);
  node[x] = true;
int i;
  for (i = 1; i <= N; i++)
    {
	if(i==x) continue;
      if ((visit[x][i] == 0) && E[x][i])
	{
	  if (node[i] == true)
	    {
	      dia = true;
	      return;
	    }

	  visit[x][i] = 1;
	  dfs (i);
	}
    }
}

int
main ()
{
int tc,num;
scanf(" %d",&num);
for(tc=1;tc<=num;tc++){
printf("Case #%d: ",tc);
memset(E,0,sizeof(E));
  v.clear();
  dia=false;
  int n,no,i,j;
  scanf (" %d", &n);
  N=n;
  for (i = 0; i < n; i++)
    {
      scanf (" %d", &no);
      for (j = 0; j < no; j++)
	{
		int x;
	  scanf (" %d", &x);
	  E[x][i + 1] = 1;
	}
	  if (no == 0)
	    v.push_back (i + 1);

    }
  for (j = 0; j < v.size (); j++) {
  memset (visit, 0, sizeof (visit));
  memset(node,0,sizeof(node));
//printf("calling:%d\n",v[j]);
    dfs (v[j]);
	if(dia) break;
}
  if (dia)
    printf ("Yes");
  else
    printf ("No");
  printf ("\n");
}
}
