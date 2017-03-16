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

int mapa[128][128];
int mapa2[128][128];

bool hayUno(int n, int m)
{
    forn(i,n)
    forn(j,m)
    if(mapa2[i][j]==1)
        return true;
    return false;
}

bool calc(int n, int m)
{
    while(hayUno(n,m)==true)
    {
        bool b = false;
        forn(i,n)
        {
            bool aux = true;
            forn(j,m)
            if(mapa2[i][j]==0)
                aux=false;
            if(aux==true)
            {
                bool c = false;
                forn(j,m)
                if(mapa2[i][j]==1)
                    b = true;
                forn(j,m)
                    mapa2[i][j] = 2;
            }
        }
        forn(i,m)
        {
            bool aux = true;
            forn(j,n)
            if(mapa2[j][i]==0)
                aux = false;
            if(aux==true)
            {
                bool c = false;
                forn(j,n)
                if(mapa2[j][i]==1)
                    b = true;
                forn(j,n)
                    mapa2[j][i] = 2;
            }
        }
        if(b == false && hayUno(n,m)==true)
            return false;
        else if(hayUno(n,m)==false)
            return true;
    }
    return true;
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
	    int n,m;
	    cin >> n >> m;
	    forn(i,n)
	    forn(j,m)
            cin >> mapa[i][j];
        string res = "YES";
        for(int h=99;h>=1;h--)
        {
            forn(i,n)
            forn(j,m)
            {
                if(mapa[i][j] <=h)
                    mapa2[i][j] = 1;
                else
                    mapa2[i][j] = 0;
            }
            if(calc(n,m)==false)
                res = "NO";
        }
        cout <<"Case #"<< casito << ": "<< res <<endl;
	}
}
