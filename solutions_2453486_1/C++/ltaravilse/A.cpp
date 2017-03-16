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

string st[4];

int main()
{
	#ifdef ACMTUYO
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
	    forn(i,4)
            cin >> st[i];
        bool siguen = false;
        forn(i,4)
        forn(j,4)
        if(st[i][j] == '.')
        {
            siguen = true;
        }
        bool x = false, o = false;
        forn(i,4)
        {
            bool aux = true;
            forn(j,4)
            {
                if(st[i][j] != 'T'&&st[i][j]!='X')
                    aux = false;
            }
            if(aux == true)
                x = true;
            aux = true;
            forn(j,4)
            {
                if(st[j][i] != 'T'&&st[j][i]!='X')
                    aux = false;
            }
            if(aux == true)
                x = true;
            aux = true;
            forn(j,4)
            {
                if(st[i][j] != 'T'&&st[i][j]!='O')
                    aux = false;
            }
            if(aux == true)
                o = true;
            aux = true;
            forn(j,4)
            {
                if(st[j][i] != 'T'&&st[j][i]!='O')
                    aux = false;
            }
            if(aux == true)
                o = true;
        }
        bool aux = true;
        forn(i,4)
        {
            if(st[i][i] !='X' && st[i][i]!= 'T')
                aux = false;
        }
        if(aux == true)
            x = true;
        aux = true;
        forn(i,4)
        {
            if(st[i][3-i] !='X' && st[i][3-i]!= 'T')
                aux = false;
        }
        if(aux == true)
            x = true;
        aux = true;
        forn(i,4)
        {
            if(st[i][i] !='O' && st[i][i]!= 'T')
                aux = false;
        }
        if(aux == true)
            o = true;
        aux = true;
        forn(i,4)
        {
            if(st[i][3-i] !='O' && st[i][3-i]!= 'T')
                aux = false;
        }
        if(aux == true)
            o = true;
        string st = "Draw";
        if(siguen == true)
            st = "Game has not completed";
        if(x == true)
            st = "X won";
        if(o == true)
            st = "O won";
        cout <<"Case #"<< casito << ": " << st <<endl;
	}
}
