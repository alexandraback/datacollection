#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 1001
#define INF 0x3f3f3f3f
#define PII pair<int, int>
typedef long long int ll;

int graph[MAX];
vector<bool> visited, vtemp;
int maxi, cont, n, chamou;

int check(int start, int end)
{
  int atual=start, c=0;
  while(true)
  {
    if(atual==end) return c;
    if(vtemp[atual]) break;
    vtemp[atual]=true;
    atual = graph[atual];
    c++;
  }
  return 0;
}

int checkAugmenting(int u, int v)
{
  int mm=0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      vtemp=visited;
      if(i==j)
      {
        int soma = check(i, u);
        vtemp=visited;
        mm = max(mm, max(soma, check(i, v)));
      }
      else mm = max(mm, check(i, u)+check(j, v));
    }
  }
  return mm;
}

void dfs(int i, int p)
{
  if(visited[i]) return;
  visited[i]=true;
  int temp = ++cont;
  if(graph[i] == p)
  {
    temp += checkAugmenting(chamou, i);
    maxi = max(maxi, temp);
  }
  else if(graph[i] == chamou) maxi = max(maxi, temp);
  
  dfs(graph[i], i);
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int t, node, teste=1;
  cin >> t;
  
  while(t--)
  {
    cin >> n;
    maxi=1, cont=0;
    for(int i = 0; i < n; i++)
    {
      cin >> node;
      graph[i]=node-1;
    }
    
    for(int i = 0; i < n; i++)
    {
      visited.assign(n, false);
      chamou=i; cont=0;
      dfs(i, -1);
    }
    cout << "Case #" << teste++ << ": " << maxi << endl;
  }
  
  return 0;
}




