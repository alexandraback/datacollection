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



#define forn(i, n) for(tint i = 0; i<(tint)n; i++)
#define all(v) (v).begin(), (v).end()
#define dforn(i, n) for(int i= (int)n-1; i=>0; i--)

#define sz(a) int((a).size())
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define MAX 10000
using namespace std;
struct _star{int min1; int min2; int ganadas;};
typedef struct _star  star;

bool comp(const star& l1, const star& l2)
{
    if(l1.min1<l2.min1)
        return false;
    if(l1.min1>l2.min1)
        return true;//false;
    if(l1.min2<l2.min2)
        return false;//true;
    if(l1.min2>l2.min2)
        return true;//false;
    return false;
}
tint estrellasConseguidas;
tint solucion(star levels[MAX], tint cant)
{
    tint maxcant = 2*cant;
    tint mejor = cant;
    tint estrellas = 0;
    tint vecesGanadas=0;
    estrellasConseguidas=0;
    sort(levels, levels+cant, comp);
    bool hayaCambios =false;
    do
    {
        ciclo:hayaCambios=false;

        forn(i, cant)
        {
            if(levels[i].ganadas<2)
            {
                if (estrellas >= levels[i].min2)
                {
                    //cerr << '*' << levels[i].min1 << '-' << levels[i].min2 << endl;
                    estrellas+=2-levels[i].ganadas;
                    levels[i].ganadas=2;
                    hayaCambios=true;
                    vecesGanadas++;
                    goto ciclo;
                }
            }
        }
        forn(i, cant)
        {
           if(levels[i].ganadas<1)
            {
                 if(estrellas >= levels[i].min1)
                {
                    //cerr << levels[i].min1 << '-' << levels[i].min2 << endl;
                    estrellas+=1;
                    levels[i].ganadas=1;
                    hayaCambios=true;
                    vecesGanadas++;
                    goto ciclo;
                }
            }
        }
    }while(hayaCambios);
    estrellasConseguidas=estrellas;
    return vecesGanadas;
}
star levels[MAX];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.out","w",stdout);
    #endif
    unsigned int n=1;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        forn(j,MAX)
        {
            levels[j].min1 =levels[j].min2=levels[j].ganadas=0;
        }
        //memset(levels, 0, MAX*sizeof(star));
        tint cnt;
        cin >> cnt;
        forn(j, cnt)
        {
            int m, n;
            cin >> m >> n;
            levels[j].min1 = m; levels[j].min2=n;
        }

        tint sol = solucion(levels,cnt);
        if(estrellasConseguidas==2*cnt)
            cout << "Case #"<< i+1 << ": " << sol;
        else
            cout << "Case #"<< i+1 << ": Too Bad";
        if(i!=n-1) cout << endl;
    }

    return 0;
}

