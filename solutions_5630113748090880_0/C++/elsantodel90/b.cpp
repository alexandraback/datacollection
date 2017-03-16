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



int main()
{	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
        int N; cin >> N;
        map<int,int> m;
        forn(i,2*N-1)
        forn(j,N)
        {
            int x; cin >> x;
            m[x]++;
        }
        vector<int> ret;
        for (pair<int,int> p : m)
        if (p.second % 2 == 1)
        {
            ret.push_back(p.first);
        }
        sort(all(ret));
        
		cout << "Case #" << caso + 1 << ":";
        forn(i,ret.size())
            cout << " " << ret[i];
        cout << endl;
		//cerr << "Case #" << caso + 1 << ": " << res << endl;
	}
	return 0;
}
