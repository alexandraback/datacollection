#include<cstdio>
#include <vector>

using namespace std;

struct nodo {
  vector <int> vicini;
  bool vivo;
};

vector <nodo> grafo;

bool dfs(int nodo)
{
  //printf("visito %d\n",nodo);
  if (!grafo[nodo].vivo)
  {
    //printf("gia fatto ritorno true\n");
    return true;
  }
  else
  {
    grafo[nodo].vivo = false;
    for (int i=0; i<(int)grafo[nodo].vicini.size(); i++)
    {
      //printf("con %d visito vicino %d\n",nodo,grafo[nodo].vicini[i]);
      if (dfs(grafo[nodo].vicini[i]))
	return true;
    }
    return false;
  }
}

int main()
{
  bool dia;
  int t,n,m,b;
  FILE *inp, *out;
  inp = fopen("input.txt","r");
  out = fopen("output.txt","w");
  fscanf(inp,"%d",&t);
  for (int k=0; k<t; k++)
  {
    fscanf(inp,"%d",&n);
    grafo = *(new vector<nodo>());
    grafo.resize(n+1);
    for (int i=1; i<=n; i++)
    {
      fscanf(inp,"%d",&m);
      for (int j=0; j<m; j++)
      {
	fscanf(inp,"%d",&b);
	grafo[i].vicini.push_back(b);
      }
    }
    printf("grafo %d\n",k+1);
    /*for (int i=1; i<=n; i++)
    {
      printf("il nodo %d confina con:\n",i);
      for (int j=0; j<(int)grafo[i].vicini.size(); j++)
      {
	printf("%d ",grafo[i].vicini[j]);
      }
      printf("\n");
    }
    printf("\n");*/
    dia = false;
    for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=n; j++)
	grafo[j].vivo = true;
      if (dfs(i))
      {
	dia = true;
	break;
      }
    }
    if (dia)
      fprintf(out,"Case #%d: Yes\n",k+1);
    else
      fprintf(out,"Case #%d: No\n",k+1);
  }
  fclose(inp);
  fclose(out);
  return 0;
}
