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

vector<int> vec;

map<int,int> mapa;

void imprime(int casito, int n1, int n2)
{
    vector<int> v1,v2;
    forn(i,vec.size())
    if(((1<<i)&n1)!=0)//&&((i<<i)&n2)==0)
        v1.push_back(i);
    else if(((1<<i)&n2)!=0)//&&((i<<i)&n1)==0)
        v2.push_back(i);
    cout << "Case #"<< casito<<":"<< endl;
    forn(i,v1.size())
    {
        if(i==0)
            cout << vec[v1[i]];
        else
            cout << " "<< vec[v1[i]];
    }
    cout << endl;
    forn(i,v2.size())
    {
        if(i==0)
            cout << vec[v2[i]];
        else
            cout << " "<< vec[v2[i]];
    }
    cout << endl;
    int t1 = 0;
}

int main()
{
	#ifdef ACMTUYO
	freopen("C-small.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito=1;casito<=casos;casito++)
	{
	    int n;
	    cin >> n;
	    vec.resize(n);
	    forn(i,n)
            cin >> vec[i];
        int suma;
        mapa.clear();
        bool sepuede = false;
        forn(i,(1<<n))
        {
            suma = 0;
            forn(j,n)
            if((i&(1<<j))!=0)
                suma+=vec[j];
            if(mapa.find(suma)!=mapa.end())
            {
                imprime(casito,mapa[suma],i);
                sepuede = true;
                break;
            }
            mapa[suma] = i;
        }
        if(sepuede==false)
            cout << "Case #" << casito << ":" << endl << "Impossible"<< endl;
	}
}
