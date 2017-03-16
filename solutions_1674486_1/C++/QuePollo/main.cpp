#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;
typedef pair<int, int> pi;

typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for(int i = 0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()
#define dforn(i, n) for(int i= (int)n-1; i=>0; i--)

#define sz(a) int((a).size())
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())




using namespace std;


typedef pair< tint, pair<int,int> > eje;
vector<vector<int> > ejes; //grafo n=cant nodos
#define MAXN 10000

int minHijo=1000000;

int dfs(int n, int m)
{
    bool vistos[n];
    //int m = minHijo;
    deque<int> pila;
    memset(vistos,0,n*sizeof(bool));

    pila.push_back(m);
    vistos[m]=1;
    while(!pila.empty())
    {
        int k = pila.front();
        pila.pop_front();


        forn(i,ejes[k].size())
        {
            int q= ejes[k][i];
            if(vistos[q])
                return 1;
            vistos[q]=1;
            pila.push_back(q);
        }


    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output2.out","w",stdout);
    #endif
    unsigned int t=1;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        ejes.clear();

        for(int j =0; j<n; j++)
        {
            int padre;
            cin >> padre;
            vector<int> misPadres;
            for(int q=0;q<padre;q++)
            {
                int u;
                cin >> u >>ws;
                misPadres.push_back(u-1);
                minHijo=min(minHijo,min(u-1,j));
            }
            ejes.push_back(misPadres);
        }
        //  orn(i,ejes.size()) cout << ejes[i].second.first << "-" << ejes[i].second.second << endl;

        int k=0;
        forn(q,n)
            k= max(dfs(n,q),k);
        cout << "Case #" << i+1 << ": ";



            //printf("%.6f", sols[j]*100.0);
        if(k==1)
            cout << "Yes" ;
        else
            cout << "No";


        if(i!=t-1) cout << endl;

    }

    return 0;
}

