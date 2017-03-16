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

double calc(int mask, int n, int x, int y)
{
    set<pair<int,int> > diamantes;
    diamantes.insert(make_pair(0,0));
    forn(i,n-1)
    {
        pair<int,int> par = make_pair(0,0);
        while(diamantes.find(par)!=diamantes.end())
            par.second+=2;
        int lado;
        if((mask&(1<<i))!=0)
        {
            lado = -1;
            par.first--;
            par.second--;
            if(diamantes.find(par)!=diamantes.end())
            {
                par.first+=2;
                lado = 1;
            }
            if(diamantes.find(par)!=diamantes.end())
            {
                par.first--;
                par.second++;
                diamantes.insert(par);
                continue;
            }
        }
        else
        {
            lado = 1;
            par.first++;
            par.second--;
            if(diamantes.find(par)!=diamantes.end())
            {
                par.first-=2;
                lado = -1;
            }
            if(diamantes.find(par)!=diamantes.end())
            {
                par.first++;
                par.second++;
                diamantes.insert(par);
                continue;
            }
        }
        if(lado == -1)
        {
            while(diamantes.find(make_pair(par.first-1,par.second-1))==diamantes.end())
            {
                par.first--;
                par.second--;
                if(par.second == 0)
                    break;
            }
        }
        else
        {
            while(diamantes.find(make_pair(par.first+1,par.second-1))==diamantes.end())
            {
                par.first++;
                par.second--;
                if(par.second == 0)
                    break;
            }
        }
        diamantes.insert(par);
    }
    if(diamantes.find(make_pair(x,y))==diamantes.end())
        return 0.;
    return 1.;
}

int main()
{
	#ifdef ACMTUYO
	freopen("B-small.in","r",stdin);
	freopen("B.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
        int n,x,y;
        cin >> n >> x >> y;
        double pot12n = 1.;
        forn(i,n-1)
            pot12n = pot12n * 0.5;
        double res = 0;
        forn(i,(1<<(n-1)))
            res += pot12n*calc(i,n,x,y);
        cout <<"Case #"<< casito << ": "<<res<<endl;
	}
}
