#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<cstring>

#define FOR(i,n) for(int i=0;i<n;++i)
#define FORS(i,s,n) for(int i=s;i<n;++i)
#define MAX 1000

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;
FILE* ifp = fopen("small.in","r");
//FILE * ifp = stdin;

FILE* ofp = fopen("small.out","w");


void print(vector<int> adj[MAX], int n)
{
 FOR(i,n)
 {
  int size = adj[i].size();
  
  FOR(j,size)
  {
   cout<<adj[i][j]<<" ";             
  }
  cout<<endl;
 }
}

template<class T>
void print(T hash[MAX], int n)
{
 FOR(i,n)
 {
  cout<<hash[i]<<endl;        
 }     
}

bool bfs(vector<int> adj[MAX], int u, int n)
{
 int color[n];
 memset(color, WHITE, sizeof(color));
 queue<int> Q;
 color[u] = GRAY;
 Q.push(u);

 while(!Q.empty())
 {
  int v = Q.front();
  color[v] = BLACK;
  Q.pop();
  
  int size = adj[v].size();
  
  FOR(i,size)
  {
   int x = adj[v][i];
   if(color[x]!= WHITE)
   {
    return true;                      
   }           
   else
   {
    color[x] = GRAY;
    Q.push(x);    
   }
  }                
 }
 
 return false;
}

int main()
{
int t, n, x;
short int hash[MAX];
int bottom[MAX];

fscanf(ifp,"%d",&t);

FOR(T,t)
{
 fscanf(ifp,"%d",&n);        
 vector<int> adj[MAX];
 int nbottom = 0;
 
 memset(hash, 0, sizeof(hash));
 
 FOR(i,n)
 {
  fscanf(ifp,"%d",&x);
  
  FOR(j,x)
  {
   int v;
   fscanf(ifp,"%d",&v);
   adj[i].push_back(v-1);
   hash[v-1] = 1;        
  }      
 }
 
 FOR(i,n)
 {
  if(hash[i] == 0)
  {
   bottom[nbottom++] = i;           
  }        
 }
 //print(adj, n);
 //print<short int>(hash,n);
 //print<int>(bottom, nbottom);
 bool found = false;
 
 FOR(i,nbottom)
 {
  if((found = bfs(adj, bottom[i], n)) == true)
  {
   break;          
  }               
 }
 
 if(found)
 {
  fprintf(ofp, "Case #%d: Yes\n", T+1);         
 }
 else
 {
  fprintf(ofp, "Case #%d: No\n", T+1);         
 }
}

system("pause");
return 0;
}
