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

#define forall(i,c) for(auto i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(auto i = (c).rbegin(); i != (c).rend(); i++)
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

const int MAXN = 2024;

int f[MAXN];

bool biciclo[MAXN];
int maxbi[MAXN];

int visto[MAXN];

int main()
{	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
        int N; cin >> N;
        forn(i,N)
        {
            cin >> f[i];
            f[i]--;
        }
        
        forn(i,N) biciclo[i] = f[f[i]] == i;
        forn(i,N) maxbi[i] = 0;
        int res = 0;
        forn(i,N)
        {
            forn(j,N) visto[j] = -1;
            int x = i;
            int index = 0;
            int CL;
            while (visto[x] < 0)
            {
                if (biciclo[x])
                {
                    maxbi[x] = max(maxbi[x], index);
                    goto proximo;
                }
                visto[x] = index++;
                x = f[x];
            }
            CL = index - visto[x];
            res = max(res, CL);
proximo:;
        }
        int sumbi = 0;
        forn(i,N) if (biciclo[i]) sumbi += maxbi[i] + 1;
        res = max(res, sumbi);
		cout << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}
