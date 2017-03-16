#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define qforsn(i,s,n) for(i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)

#define forall(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

typedef long long tint;
typedef pair<tint,tint> pint;
typedef vector<tint> vint;

const int MAX = 18564*2;

map<tint,double> p[MAX];
vector<vector<int> > allV;

int main()
{
    forn(i,MAX) p[i].clear();
    double QUANTUM = 1.0;
    forn(i,12) QUANTUM /= 2.0;
    {
        vector<int> v(12);
        #define a v[0]
        #define b v[1]
        #define c v[2]
        #define d v[3]
        #define e v[4]
        #define f v[5]
        #define g v[6]
        #define h v[7]
        #define i v[8]
        #define j v[9]
        #define k v[10]
        #define l v[11]
        qforsn(a,2,9)
        qforsn(b,2,a+1)
        qforsn(c,2,b+1)
        qforsn(d,2,c+1)
        qforsn(e,2,d+1)
        qforsn(f,2,e+1)
        qforsn(g,2,f+1)
        qforsn(h,2,g+1)
        qforsn(i,2,h+1)
        qforsn(j,2,i+1)
        qforsn(k,2,j+1)
        qforsn(l,2,k+1)
        {
            allV.push_back(v);
        }
        #undef a
        #undef b
        #undef c
        #undef d
        #undef e
        #undef f
        #undef g
        #undef h
        #undef i
        #undef j
        #undef k
        #undef l
    }
    forn(i,allV.size())
    {
        forn(mask, (1<<12))
        {
            tint prod = 1;
            forn(z, 12)
                if ((1<<z) & mask) prod *= allV[i][z];
            p[i][prod] += QUANTUM;
        }
    }
    
    int TT; cin >> TT;
    forn(tt,TT)
    {
        tint R,N,M,K; cin >> R >> N >> M >> K;
        cout << "Case #" << tt+1 << ":" << endl;
        forn(casito,R)
        {
            tint products[64];
            forn(j,K) {cin >> products[j];}
            double bestScore = 0.0;
            int best = 0;
            
            forn(ind,allV.size())
            {
                double score = 1.0;
                forn(i,K)
                {
                    map<tint,double>::const_iterator it = p[ind].find(products[i]);
                    if (it == p[ind].end())
                    {
                        score = 0.0;
                        break;
                    }
                    else
                        score *= it->second;
                }
                if (score > bestScore)
                {
                    bestScore = score;
                    best = ind;
                }
            }
            forn(i,N) cout << allV[best][i];
            cout << endl;
        }
    }
    return 0;
}
