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

double v[MAXN], p[MAXN];

int main()
{
    freopen("a.in","r",stdin);
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
        int A,B; cin >> A >> B;
        forn(i,A) cin >> v[i];
        p[0] = 1.0;
        forn(i,A)
            p[i+1] = p[i] * v[i];
        double res = B+2;
        forn(k,A+1)
        {
            double e = p[A - k] * (2.0*k + B - A + 1.0) + 
                 (1.0-p[A - k]) * (2.0*k + B - A + 1.0 + B + 1.0);
            res = min(res,e);
        }
		//cout << "Case #" << caso + 1 << ": " << res << endl;
        printf("Case #%d: %.20lf\n",caso + 1 ,(double)res);
	}
	return 0;
}
