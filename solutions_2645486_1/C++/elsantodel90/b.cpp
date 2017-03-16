#include <iostream>
#include <stack>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)

typedef long long tint;
typedef pair<tint,tint> pint;

const int MAXN = 1000000;

tint v[MAXN];
int next[MAXN];

int main()
{
    int TT; cin >> TT;
    forn(tt,TT)
    {
        tint E,R,N; cin >> E >> R >> N;
        forn(i,N) cin >> v[i];
        stack<pint> s;
        dforn(i,N)
        {
            while (!s.empty() && s.top().first < v[i]) s.pop();
            next[i] = s.empty() ? (-1) : s.top().second;
            s.push(make_pair(v[i] , i));
        }
        tint res = 0;
        tint cE = E;
        forn(i,N)
        {
            if (next[i] == -1)
            {
                res += cE * v[i];
                cE = 0;
            }
            else
            {
                tint bajo = max(0LL, E - (next[i] - i) * R);
                tint gasto = max(0LL, cE - bajo);
                res += gasto * v[i];
                cE -= gasto;
            }
            cE += R;
            cE = min(cE,E);
        }
        cout << "Case #" << tt+1 << ": " << res << endl;
    }
    return 0;
}
