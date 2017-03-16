#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("A-large.out");
ifstream fin("A-large.in");

int T,o;

int main()
{
  int n,m,x,p,head,tail,i,j;
  bool flag;
  bool a[1001][1001];
  bool v[1001];
  int b[10001];
  fin>>T;
  for (o=1;o<=T;o++)
  {
    memset(a,false,sizeof(a));
    p=0;
    fin>>n;
    for (p=1;p<=n;p++)
    {
      fin>>m;
      for (i=1;i<=m;i++)
      {
        fin>>x;
        a[x][p]=true;
      }
    }
    fout<<"Case #"<<o<<": ";
    flag=false;
    for (i=1;i<=n;i++)
    {
      memset(v,false,sizeof(v));
      memset(b,0,sizeof(b));
      head=-1;
      tail=0;
      b[0]=i;
      do
      {
        head++;
        x=b[head];
        for (j=1;j<=n;j++)
        {
          if ((x!=j)&&(a[x][j]))
          {
            if (v[j]) 
            {
              flag=true;
              break;
            }
            else 
            {
              v[j]=true;
              tail++;
              b[tail]=j;
            }
          }
        }
      } while (head<tail);
      if (flag) break;
    }
    if (flag) fout<<"Yes"<<endl;
      else fout<<"No"<<endl;
  }
  return 0;
}
