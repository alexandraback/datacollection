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
#define INF 200000000

using namespace std;

pair<int,int> grilla[128][128];

int h,n,mm;

struct mov{
    int tin,tix,tf,adonde;
};

vector<vector<mov> > lista;

int dijkstra(int ini, int fin)
{
    vector<int> dist(n*mm,INF);
    vector<bool> toc(n*mm,false);
    toc[ini] = true;
    dist[ini] = 0;
    int t=ini;
    forn(i,n*mm)
    {
        //cout << t << " "<< dist[t] << endl;
        toc[t] = true;
        forn(i,lista[t].size())
        {
            if(t==7&&lista[t][i].adonde==8)
            {
                //cout << dist[t] <<" "<< lista[t][i].tix <<" "<< lista[t][i].tf << endl;
            }
            if(lista[t][i].tix>=dist[t])
                dist[lista[t][i].adonde] = min(dist[lista[t][i].adonde],lista[t][i].tf+max(dist[t],lista[t][i].tin));
        }
        forn(i,n*mm)
        if(toc[t]==true||(toc[i]==false&&dist[i]<dist[t]))
            t = i;
    }
    return dist[fin];
}

void aristas(int x1, int y1, int x2, int y2)
{
    if(x2<0||y2<0||x2==n||y2==mm)
        return;
    if(grilla[x2][y2].second-grilla[x2][y2].first<50)
        return;
    if(grilla[x2][y2].second-grilla[x1][y1].first<50)
        return;
    if(grilla[x1][y1].second-grilla[x2][y2].first<50)
        return;
    mov m;
    m.tin = max(h-(grilla[x2][y2].second - 50),0);
    m.adonde = x2*mm+y2;
    if(m.tin==0)
    {
        m.tf = 0;
        m.tix = 0;
        lista[x1*mm+y1].push_back(m);
    }
    if(h-m.tin-20>=grilla[x1][y1].first)
    {
        m.tf = 10;
        m.tix=h-(grilla[x1][y1].first+20);
        lista[x1*mm+y1].push_back(m);
        m.tin=m.tix;
        m.tix=INF;
        m.tf = 100;
        lista[x1*mm+y1].push_back(m);
    }
    else
    {
        m.tix=INF;
        m.tf = 100;
        lista[x1*mm+y1].push_back(m);
    }
    return;
}

int main()
{
	#ifdef ACMTUYO
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito=1;casito<=casos;casito++)
	{
	    lista.clear();
	    cin >> h >> n >> mm;
	    forn(i,n)
	    forn(j,mm)
	        cin >> grilla[i][j].second;
        forn(i,n)
	    forn(j,mm)
	        cin >> grilla[i][j].first;
        forn(i,n)
        forn(j,mm)
            grilla[i][j].second = max(grilla[i][j].second,grilla[i][j].first+10);
        lista.resize(n*mm);
        forn(i,n*mm)
        {
            int x = i/mm, y = i%mm;
            aristas(x,y,x-1,y);
            aristas(x,y,x+1,y);
            aristas(x,y,x,y-1);
            aristas(x,y,x,y+1);
        }
        int res = dijkstra(0,n*mm-1);
	    cout << "Case #" << casito << ": " << res/10 <<"."<<res%10<<endl;
	}
}
