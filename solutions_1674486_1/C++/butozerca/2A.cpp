#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define FOR(x,y,z) for(int x=y;x<z;x++)
#define MP make_pair
#define F first
#define S second
#define PB push_back 
using namespace std;

vector<int> V[1010];
bool jest=false;
int odw[1010];

void DFS(int v)
{
   FOR(i,0,V[v].size())
   {
      if(odw[V[v][i]]==1){;jest=true;break;}
      else if(odw[V[v][i]]==-1)continue;
      else {odw[V[v][i]]=1;DFS(V[v][i]);}
   }
}

int main()
{
   int Z;
   scanf("%d",&Z);
   for(int zz=1;zz<=Z;zz++)
   {
      int n,k;
      jest=false;
      scanf("%d",&n);
      FOR(i,1,n+1)
      {
         scanf("%d",&k);
         FOR(j,1,k+1)
         {
            int t;
            scanf("%d",&t);
            V[i].PB(t);
         }
      }
      FOR(i,1,n+1)
      {
         FOR(j,1,n+1)odw[j]=false;
         odw[i]=-1;
         DFS(i);
         if(jest)break;
      }
      FOR(i,1,n+1)V[i].clear();
      printf("Case #%d: %s\n",zz,((jest)?"Yes":"No"));
   }
 //  system("pause");
   return 0;
}
