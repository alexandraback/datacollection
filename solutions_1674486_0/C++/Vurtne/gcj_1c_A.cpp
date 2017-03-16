#include <iostream>
#include <fstream>
using namespace std;

int a[1001][1001];
int b[1001][1001];
int ro[1001];
bool v[1001];
int n;
bool flag;
ifstream fin("1ca.in");
ofstream fout("1ca.out");

int find(int x)
{
     v[x] = true;
     if (b[x][0] == 0) {ro[0]++;ro[ro[0]] = x;return 0;}
     for (int i=1;i<=b[x][0];i++)
     if (!v[b[x][i]])
     {
        find(v[b[x][i]]);
     }
}

bool dfs(int x)
{
     if (v[x]) return true;
     v[x] = true;
     for (int i=1;i<=a[x][0];i++)
     {
        if (dfs(a[x][i])) return true;
     }
     return false;
}

int main()
{
    int o,t,p,q;
    fin >> t;
    for (o=1;o<=t;o++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ro,0,sizeof(ro));
        memset(v,false,sizeof(v));
        fin >> n;
        for (int i=1;i<=n;i++)
        {
            fin >> p;
            for (int j=1;j<=p;j++)
            {
                fin >> q;
                a[i][0]++;
                a[i][a[i][0]] = q;
                b[q][0]++;
                b[q][b[q][0]] = i;
            }
        }
        for (int i=1;i<=n;i++)
        if (!v[i]) find(i);
        flag = false;
        for (int i=1;i<=ro[0];i++)
        {
            memset(v,false,sizeof(v));
            if (dfs(ro[i])) { fout << "Case #" << o << ": Yes" << endl;flag = true;break;}
        }
        if (flag) continue;
        fout << "Case #" << o << ": No" << endl;
    }
    return 0;
}
