#include <bits/stdc++.h>
using namespace std;

int t;

int n;

int n1, n2;
string a, b;
map <string,int> aa, bb;

vector <int> graf[1007];

int l;
int sko[1007];
int ma[1007];

int bylo[1007];

void czys()
{
    for (int i=1; i<=n1; i++)
    bylo[i]=0;
}

int dfs(int v)
{
    bylo[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (!sko[graf[v][i]] || (!bylo[sko[graf[v][i]]] && dfs(sko[graf[v][i]])))
        {
            ma[v]=graf[v][i];
            sko[graf[v][i]]=v;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        printf("Case #%d: ", tt);
        n1=n2=0;
        aa.clear();
        bb.clear();
        cin >> n;
        for (int i=1; i<=n; i++)
        {
            graf[i].clear();
        }
        for (int i=1; i<=n; i++)
        {
            cin >> a >> b;
            if (!aa[a])
            {
                n1++;
                aa[a]=n1;
                ma[n1]=0;
            }
            if (!bb[b])
            {
                n2++;
                bb[b]=n2;
                sko[n2]=0;
            }
            graf[aa[a]].push_back(bb[b]);
        }
        l=0;
        while(1)
        {
            czys();
            int czy=0;
            for (int i=1; i<=n1; i++)
            {
                if (!ma[i] && !bylo[i] && dfs(i))
                {
                    czy=1;
                    break;
                }
            }
            if (!czy)
            break;
            l++;
        }
        printf("%d\n", n-n1-n2+l);
    }
    return 0;
}
