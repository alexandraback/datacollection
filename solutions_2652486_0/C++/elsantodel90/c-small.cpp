#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)

#define forall(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

typedef long long tint;
typedef pair<tint,tint> pint;
typedef vector<tint> vint;

map<tint, map<vint,tint> > p;
vector<vint> allV;

int main()
{
    forsn(a,2,6)
    forsn(b,2,a+1)
    forsn(c,2,b+1)
    {
        vint v(3);
        v[0] = a;
        v[1] = b;
        v[2] = c;
        allV.push_back(v);
        forn(mask, 8)
        {
            tint prod = 1;
            forn(k, 3)
                if ((1<<k) & mask) prod *= v[k];
            p[prod][v]++;
        }
    }
    int TT; cin >> TT;
    forn(tt,TT)
    {
        tint R,N,M,K; cin >> R >> N >> M >> K;
        cout << "Case #" << tt+1 << ":" << endl;
        forn(casito,R)
        {
            vint products(K);
            forn(j,K) {cin >> products[j];}
            vector<vint> candidates;
            forall(v, allV)
            {
                bool funca = true;
                forn(i,K)
                    funca &= (p[products[i]][*v] > 0);
                if (funca) candidates.push_back(*v);
            }
            
            int ret = rand() % candidates.size();
            forn(i,N) cout << candidates[ret][i];
            cout << endl;
        }
    }
    return 0;
}
