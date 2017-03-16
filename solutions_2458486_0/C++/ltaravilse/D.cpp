#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()

using namespace std;

int keys[256];
int keys2[256];
int open[256];
vector<int> chests[256];
bool abierto[256];
int n;

void abrir(int t)
{
    keys[open[t]]--;
    forn(i,chests[t].size())
        keys[chests[t][i]]++;
    abierto[t] = true;
    return;
}

void cerrar(int t)
{
    keys[open[t]]++;
    forn(i,chests[t].size())
        keys[chests[t][i]]--;
    abierto[t] = false;
    return;
}

bool hayCerrados()
{
    forn(i,n)
    if(abierto[i]==false)
        return true;
    return false;
}

vector<int> aux1[256], aux2[256];
bool noAbiertos[256];

bool hayCerrados2()
{
    forn(i,200)
    if(!aux1[i].empty()||!aux2[i].empty())
        return true;
    return false;
}

vector<int> dfs(int t)
{
    vector<bool> toc(n,false);
    vector<int> vec(1,t);
    toc[t] = true;
    forn(i,n)
    if(noAbiertos[i] == false)
        toc[i] = true;
    while(!vec.empty())
    {
        int t2 = vec[vec.size()-1];
        if(count(all(chests[t2]),open[t])>0)
            return vec;
        bool b = false;
        forn(i,n)
        if(toc[i]==false&&count(all(chests[t2]),open[i])>0)
        {
            b = true;
            vec.push_back(i);
            toc[i] = true;
            break;
        }
        if(b==false)
            vec.pop_back();
    }
    return vec;
}

vector<int> ciclo()
{
    forn(i,200)
        noAbiertos[i] = false;
    forn(i,200)
    {
        forn(j,aux1[i].size())
            noAbiertos[aux1[i][j]] = true;
        forn(j,aux2[i].size())
            noAbiertos[aux2[i][j]] = true;
    }
    forn(i,200)
    if(noAbiertos[i]==true&&keys[open[i]]>0)
    {
        vector<int> vec = dfs(i);
        if(!vec.empty())
            return vec;
    }
    vector<int> vec(0);
    return vec;
}

void borrar(vector<int> &vec, int r)
{
    forn(i,vec.size())
    {
        if(vec[i]==r)
        {
            swap(vec[i],vec[vec.size()-1]);
            vec.pop_back();
            return;
        }
    }
    return;
}

bool possible()
{
    forn(i,200)
    {
        aux1[i].clear();
        aux2[i].clear();
    }
    forn(i,200)
        keys2[i] = keys[i];
    forn(i,n)
    if(abierto[i]==false)
    {
        if(count(all(chests[i]),open[i])==0)
            aux1[open[i]].push_back(i);
        else
            aux2[open[i]].push_back(i);
    }
    bool c = true;
    while(c==true)
    {
        c = false;
        forn(i,200)
        if(keys[i]>0 && !aux2[i].empty())
        {
            forn(j,aux2[i].size())
            {
                keys[i]--;
                forn(t,chests[aux2[i][j]].size())
                    keys[chests[aux2[i][j]][t]]++;
            }
            aux2[i].clear();
            i = 0;
        }
        forn(i,200)
        if(keys[i]>=aux1[i].size() && !aux1[i].empty())
        {
            c = true;
            forn(j,aux1[i].size())
            {
                keys[i]--;
                forn(t,chests[aux1[i][j]].size())
                    keys[chests[aux1[i][j]][t]]++;
            }
            aux1[i].clear();
            i = 0;
        }
    }
    while(hayCerrados2())
    {
        vector<int> vec = ciclo();
        if(vec.empty())
        {
            forn(i,200)
                keys[i] = keys2[i];
            return false;
        }
        forn(i,vec.size())
        {
            int r = vec[i];
            int k = open[r];
            borrar(aux1[k],r);
            borrar(aux2[k],r);
            keys[k]--;
            forn(j,chests[r].size())
                keys[chests[r][j]]++;
        }
        forn(i,200)
        if(keys[i]>0)
        {
            forn(j,aux2[i].size())
            {
                keys[i]--;
                forn(t,chests[aux2[i][j]].size())
                    keys[chests[aux2[i][j]][t]]++;
            }
            aux2[i].clear();
        }
        forn(i,200)
        if(keys[i]>=aux1[i].size())
        {
            forn(j,aux1[i].size())
            {
                keys[i]--;
                forn(t,chests[aux1[i][j]].size())
                    keys[chests[aux1[i][j]][t]]++;
            }
            aux1[i].clear();
        }
    }
    forn(i,200)
        keys[i] = keys2[i];
    return true;
}

int main()
{
	#ifdef ACMTUYO
	freopen("D-small.in","r",stdin);
	freopen("D.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
	    int k;
	    cin >> k >> n;
	    forn(i,200)
            keys[i] = 0;
        forn(i,k)
        {
            int a;
            cin >> a;
            keys[a]++;
        }
        forn(i,n)
            chests[i].clear();
        forn(i,n)
        {
            cin >> open[i];
            int a;
            cin >> a;
            chests[i].resize(a);
            forn(j,a)
                cin >> chests[i][j];
        }
        forn(i,n)
            abierto[i] = false;

        string res = "";
        if(!possible())
            res = "IMPOSSIBLE";
        else
        {
            forn(i,n)
                abierto[i] = false;
            while(hayCerrados())
            {
                forn(i,n)
                if(abierto[i]==false&&keys[open[i]]>0)
                {
                    abrir(i);
                    abierto[i] = true;
                    if(possible())
                    {
                        ostringstream oss;
                        oss.str("");
                        oss.clear();
                        oss << i+1;
                        res += oss.str();
                        if(hayCerrados())
                            res += " ";
                        break;
                    }
                    abierto[i] = false;
                    cerrar(i);
                }
            }
        }
        cout <<"Case #"<< casito << ": "<<res<<endl;
	}
}
