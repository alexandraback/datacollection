#include <fstream>
using namespace std;

ifstream fin("1.in");
ofstream fout("1.out");

#define cin fin
#define cout fout

bool mark[1010];
int a[1010][1010];
int size[1010];
int indeg[1010];
bool flag;

void init()
{
  int i,j;
  flag=false;
  for(i=1;i<=1001;i++)
  {
    indeg[i]=0;
    mark[i]=0;
    size[i]=0;
  }
  for(i=0;i<=1001;i++)
    for(int j=0;j<=1010;j++)
      a[i][j]=0;
}
void tinit(){for(int i=1;i<=1010;i++)mark[i]=0;}

void dfs(int v)
{
  if(flag==true)
    return;
  mark[v]=1;
  int i;
  for(i=1;i<=size[v];i++)
  {
    if(mark[a[v][i]])
    {
      flag=true;
      break;
    }
    else
      dfs(a[v][i]);
  }
}

int main()
{
  int i,d,j,k,t,n,num;
  cin >> t;
  for(k=1;k<=t;k++)
  {
    init();
    cin >> n;
    for(i=1;i<=n;i++)
    {
      cin >> num;size[i]=num;
      for(j=1;j<=num;j++)
      {
	cin >> a[i][j];
	indeg[a[i][j]]++;
      }
    }
    for(i=1;i<=n;i++)
    {
      if(indeg[i]==0)
      {
	tinit();
	dfs(i);
      }
    }
    cout << "Case #" << k << ": ";
    if(flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
    