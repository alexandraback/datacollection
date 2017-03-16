#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ad[1001];

int n_archi_entr[1001];

bool visitato[1000];

bool visita(int x)
{
    visitato[x]=true;
    //cerco un nodo già visto
    for(int i=0;i<ad[x].size();i++)
    {
        if(visitato[ad[x][i]])
        {
            return true;
        }
    }
    //continuo la ricerca sui figli
    for(int i=0;i<ad[x].size();i++)
    {
        if(!visitato[ad[x][i]])
        {
            if(visita(ad[x][i]))
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t,n,v,n_a,j;
    in>>t;
    for(int i=0;i<t;i++)
    {
        out<<"Case #"<<i+1<<": ";
        in>>n;
        for(j=1;j<=n;j++)
        {
            in>>n_a;
            for(int t=0;t<n_a;t++)
            {
                in>>v;
                ad[j].push_back(v);
                n_archi_entr[v]++;
            }
        }
        for(j=1;j<=n;j++)
        {
            if(visita(j))
            {
                out<<"Yes";
                break;
            }
            for(int t=1;t<=n;t++)
            {
                visitato[t]=false;
            }
        }
        if(j==n+1)
        {
             out<<"No";
        }
        out<<endl;
        for(j=1;j<=n;j++)
        {
            ad[j].clear();

            n_archi_entr[j]=0;

            visitato[j]=false;
        }
    }
}
