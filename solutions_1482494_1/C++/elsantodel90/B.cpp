#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define all(c) (c).begin(),(c).end()

#define esta(x,c) ((c).find(x) != (c).end())
#define zMem(c) memset((c),0,sizeof(c))

typedef long long tint;
typedef long double tdbl;

typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;

const int MAXN = 1000000;

int a[MAXN],b[MAXN];
int x[MAXN];

int main()
{
    freopen("b.in","r",stdin);
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
        int N; cin >> N;
        forn(i,N) cin >> a[i] >> b[i];
        zMem(x);
        int res = 0, anda = 1;
        int T = 0; // stars
        while (T != 2*N)
        {
            bool hay = false;
            forn(i,N)
            if (x[i] < 2 && b[i] <= T)
            {
                hay = true;
                T += 2 - x[i];
                x[i] = 2;
                res++;
            }
            if (hay) continue;
            // El 0 posible con un b mas caro
            int candi = -1;
            forn(i,N)
            if (a[i] <= T && x[i] == 0 && (candi == -1 || b[i] > b[candi]))
                candi = i;
            if (candi != -1)
            {
                hay = true;
                x[candi]++;
                T++;
                res++;
            }
            if (!hay)
            {
                anda = 0;
                break;
            }
        }
        
		cout << "Case #" << caso + 1 << ": ";
        if (anda)
            cout << res;
        else
            cout << "Too Bad";
        cout << endl;
	}
	return 0;
}
