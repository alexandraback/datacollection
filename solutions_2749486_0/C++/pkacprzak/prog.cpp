#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>
#include <ctime>

#include "gmpxx.h"

using namespace std;
#define pb push_back
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
inline void pisz(int n) { printf("%d\n",n); }
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long num;
typedef double fl;
typedef mpz_class big;

void output(int t, string msg)
{
    cout << "Case #" << t << ": " << msg << "\n";
}
void output(int t, int n)
{
    cout << "Case #" << t << ": " << n << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int tests;
    int x, y;
    cin >> tests;
    REP(t, 1, tests)
    {
        cin >> x >> y;
        map<pair<int, int>, pair<int, int> > visited;
        map<pair<int, int>, pair<int, int> >::iterator m_it;
        queue<pair<pair<int, int>, int> > q;
        q.push(mp(mp(0,0), 1));
        visited.insert(mp(mp(0, 0), mp(0, 0)));
        while(!q.empty())
        {
            int a = q.front().fi.fi;
            int b = q.front().fi.se;
            int d = q.front().se;
            q.pop();
            if(a == x && b == y)
            {
                string s;
                while(a != 0 || b != 0)
                {
                    m_it = visited.find(mp(a, b));
                    pair<int, int> p = mp(m_it->se.fi, m_it->se.se); 
                    //cout << p.fi << " " << p.se << endl;
                    if(a - p.fi > 0)
                    {
                        s += 'E';
                    }
                    else if(a - p.fi < 0)
                    {
                        s += 'W';
                    }
                    else if(b - p.se > 0)
                    {
                        s += 'N';
                    }
                    else if(b - p.se < 0)
                    {
                        s += 'S';
                    }
                    a = p.fi;
                    b = p.se;
                }
                cout << "Case #" << t << ": ";
                REPD(i, s.length() - 1, 0) cout << s[i];
                cout << "\n";
                break;
            }
            if(visited.find(mp(a + d, b)) == visited.end())
            {
                q.push(mp(mp(a + d, b), d + 1));
                visited.insert(mp(mp(a + d, b), mp(a, b)));
            }
            if(visited.find(mp(a - d, b)) == visited.end())
            {
                q.push(mp(mp(a - d, b), d + 1));
                visited.insert(mp(mp(a - d, b), mp(a, b)));
            }
            if(visited.find(mp(a, b + d)) == visited.end())
            {
                q.push(mp(mp(a, b + d), d + 1));
                visited.insert(mp(mp(a, b + d), mp(a, b)));
            }
            if(visited.find(mp(a, b - d)) == visited.end())
            {
                q.push(mp(mp(a, b - d), d + 1));
                visited.insert(mp(mp(a, b - d), mp(a, b)));
            }
        } 
    }
    return 0;
}
