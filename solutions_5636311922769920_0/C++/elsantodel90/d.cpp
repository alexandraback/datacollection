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

tint K;

struct Position
{
    Position() : index(0), level(0) {}
    tint index, level;
    void merge(tint origIndex)
    {
        index = index * K + origIndex;
        level++;
    }
    void moveToLevel(tint L)
    {
        while (level < L)
        {
            index *= K;
            level++;
        }
    }
};

int main()
{	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
        tint C,S; cin >> K >> C >> S;
        tint minCant = (K + C-1) / C;
        ostringstream res;
        if (S < minCant)
            res << "IMPOSSIBLE";
        else
        {
            forn(i, minCant)
            {
                tint A = C*i;
                tint B = min(A+C, K);
                Position p;
                forsn(j, A, B)
                    p.merge(j);
                p.moveToLevel(C);
                if (i) res << " ";
                res << p.index+1;
            }
        }
		cout << "Case #" << caso + 1 << ": " << res.str() << endl;
		cerr << "Case #" << caso + 1 << ": " << res.str() << endl;
	}
	return 0;
}
