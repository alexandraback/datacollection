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
#define MUCHO 2001000

using namespace std;

vector<int> vec[MUCHO];
int pot10[8];

set<pair<int,int> > setint;

int main()
{
	#ifdef ACMTUYO
	freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif
	pot10[0] = 1;
	for(int i=1;i<8;i++)
        pot10[i] = pot10[i-1]*10;
	forn(i,MUCHO)
        vec[i].clear();
    int cifras,j,aux;
    for(int i=10;i<MUCHO;i++)
    {
        cifras = 0;
        j = i;
        while(j!=0)
        {
            cifras++;
            j/=10;
        }
        j = i;
        forn(t,cifras+1)
        {
            aux = j%10;
            j/=10;
            j+=aux*pot10[cifras-1];
            if(j>i)
                vec[i].push_back(j);
        }
    }
    int n;
    cin >> n;
    forn(ii,n)
    {
        setint.clear();
        int a,b;
        cin >> a >> b;
        int res = 0;
        for(int i=a;i<b;i++)
        {
            for(j=0;j<vec[i].size();j++)
            if(vec[i][j]>=a&&vec[i][j]<=b&&setint.find(make_pair(i,vec[i][j]))==setint.end())
            {
                setint.insert(make_pair(i,vec[i][j]));
                res++;
            }
        }
        cout << "Case #"<< ii+1 << ": "<< res << endl;
    }
}
