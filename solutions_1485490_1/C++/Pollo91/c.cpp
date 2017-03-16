#include<cstdio>
#include<utility>
#include<map>

#define MAX_N 100

using namespace std;

pair<long long int,int> scatole[MAX_N];
pair<long long int,int> giochi[MAX_N];
map<pair<long long int, long long int>,long long int> mem[MAX_N][MAX_N];
int n,m;

long long int trova(int s, int g, long long int ns, long long int ng)
{
  pair<long long int, long long int> temp;
  map<pair<long long int, long long int>,long long int>::iterator it;
  temp.first = ns;
  temp.second = ng;
  //printf("chiamata %d %d %lld %lld\n",s,g,ns,ng);
  if (s==n || g == m)
  {
    //printf("raggiunta la fine, ritorno 0\n");
    return 0;
  }
  else
  {
    it = mem[s][g].find(temp); 
    if (it != mem[s][g].end())
    {
      //printf("già in memoria, ritorno %lld\n",(*it).second);
      return (*it).second;
    }
    else
    {
      if (scatole[s].second == giochi[g].second)
      {
	if (ns == ng)
	{
	  //printf("stesso tipo: prendo tutt0\n");
	  mem[s][g][temp] = trova(s+1,g+1,scatole[s+1].first,giochi[g+1].first) + ns;	  
	}
	else if (ns > ng)
	{
	  //printf("stesso tipo: prendo tutti i giochi\n");
	  mem[s][g][temp] = trova(s,g+1,ns-ng,giochi[g+1].first) + ng;
	}
	else
	{
	  //printf("stesso tipo: prendo tutte le scatole\n");
	  mem[s][g][temp] = trova(s+1,g,scatole[s+1].first,ng-ns) +ns;
	}
      }
      else
      {
	mem[s][g][temp] = max(trova(s+1,g,scatole[s+1].first,ng),trova(s,g+1,ns,giochi[g+1].first));
      }
    }
    //printf("chiamata %d %d %lld %lld, ritorno %lld\n",s,g,ns,ng,mem[s][g][temp]);
    return mem[s][g][temp];
  }
}

int main()
{
  int t,b;
  long long int a, max;
  FILE *inp, *out;
  inp = fopen("input.txt","r");
  out = fopen("output.txt","w");
  fscanf(inp,"%d",&t);
  for (int k=0; k<t; k++)
  {
    fscanf(inp,"%d %d",&n,&m);
    for (int i=0; i<n; i++)
    {
      fscanf(inp,"%lld %d",&a,&b);
      scatole[i].first = a;
      scatole[i].second = b;      
    }
    for (int i=0; i<m; i++)
    {
      fscanf(inp,"%lld %d",&a,&b);
      giochi[i].first = a;
      giochi[i].second = b;      
    }
    printf("caso %d\n",k+1);
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
	mem[i][j].clear();
    /*for (int i =0; i<n; i++)
      printf("%lld %d  ",scatole[i].first,scatole[i].second);
    printf("\n");
    for (int i =0; i<m; i++)
      printf("%lld %d  ",giochi[i].first,giochi[i].second);
      printf("\n");*/
    max = trova(0,0,scatole[0].first,giochi[0].first);
    fprintf(out,"Case #%d: %lld\n",k+1,max);
  }
  fclose(inp);
  fclose(out);
  return 0;
}
