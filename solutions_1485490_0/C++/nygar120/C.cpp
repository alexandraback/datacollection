#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/* GCJ template part 02 -- Common macro definitions */
#define FOR(i, a, b)    for(int i = int(a); i < int(b); ++i)
#define REP(i, n)       FOR(i, 0, n)
#define FORE(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define REPE(i, n)      FORE(i, 0, n)
#define FORD(i, a, b)   for(int i = int(b) - 1; i >= int(a); --i)
#define REPD(i, n)      FORD(i, 0, n)
#define FORDE(i, a, b)  for(int i = int(b); i >= int(a); --i)
#define REPDE(i, n)     FORDE(i, 0, n)
#define IT(c)           __typeof((c).begin())
#define FORIT(i, c)     for(IT(c) i = (c).begin(); i != (c).end(); ++i)
#define SZ(c)           (int((c).size()))
#define ALL(c)          (c).begin(), (c).end()
#define SET(m, v)       memset((m), (v), sizeof(m))
#define REVERSE(c)      reverse(ALL(c))
#define SORT(c)         sort(ALL(c))
#define UNIQ(c)         SORT(c), (c).erase(unique(ALL(c)), (c).end())
#define PB              push_back
#define MP              make_pair
#define BIT(x)          (1<<(x))
#define MAPRET(m, x)    { IT(m) _ = m.find(x); if(_ != m.end()) return _->second; }

/* GCJ template part 03 -- Common type definitions */
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;
typedef vector<VD> VVD;

// Tests if string a starts with string b
inline bool startswith(const string &a, const string &b) {
    return a.size() >= b.size() && a.compare(0, b.size(), b) == 0;
}

// Tests if string a end with string b
inline bool endswith(const string &a, const string &b) {
    return a.size() >= b.size() && a.compare(a.size() - b.size(), b.size(), b) == 0;
}

template<class T> inline T SQR(T x) { return x*x; }

// Tests wether an integer is prime
// Testing all integers from 1 to 1,000,000 takes about 1.5s
bool PRIME(int n) {
    if (n < 2) return false;
    if ((n&1) == 0) return n == 2;
    for (int d = 3; d*d <= n; d += 2) if(n%d == 0) return false;
    return true;
}

// A fast prime sieve, generating prime numbers upto (and including)
// `max` using `max`/16 bytes of memory.
 // Takes about 0.2s for max=10M.
void GENPRIMES(vector<int> &primes, int max) {
    primes.clear();
    if (max < 2)
        return;

    /* Sieve (odd numbers only) */
    vector<bool> comp((max + 1)/2);
    for (int n = 3; n*n <= max; n += 2)
        if (!comp[n/2])
            for (int m = n*n; m <= max; m += 2*n)
                comp[m/2] = true;

    /* Collect primes */
    primes.push_back(2);
    for (int n = 3; n <= max; n += 2)
        if (!comp[n/2])
            primes.push_back(n);
}

int posit(int a)
{
    if (a < 0) return 0;
    return a;
}

int N, M;
ULL tabN[101][2], tabM[101][2];

ULL max(ULL a, ULL b) {if (a>b)return a; return b;}
ULL min(ULL a, ULL b) {if (a>b)return b; return a;}

ULL  recu(int a, ULL na, int b,  ULL nb,  ULL  t)
{
   // printf("recu %d %d %d %d - %d\n",a,na,b,nb,t);
    
    if (tabN[a][1] == tabM[b][1])
    {
        t += min(na, nb);
        na -= min(na,nb);
        nb -= min(na,nb);
    }

    ULL titi = 0;
    if (a+1 < N)
       titi = max(titi,recu(a+1,tabN[a+1][0],b,nb,t));
    else
        titi = max(titi, t);
        
    if (b+1 < M)
       titi = max(titi,recu(a,na,b+1,tabM[b+1][0],t));
    else
        titi = max(titi, t);
    return titi;
}

int main()
{
    int T;

    cin >> T;

    FORE(i, 1, T)
    {
        cout << "Case #" << i << ": ";
        
        cin >> N;
        cin >> M;

        FORE(j, 0, N-1)
        {
            scanf("%llu", &tabN[j][0]);
            cin >> tabN[j][1];
            if ((j > 0) && (tabN[j-1][1] == tabN[j][1]))
               {tabN[j-1][0] += tabN[j][0]; N--; j--;}
        }
        FORE(j, 0, M-1)
        {
            scanf("%llu", &tabM[j][0]);
            cin >> tabM[j][1];
            if ((j > 0) && (tabM[j-1][1] == tabM[j][1]))
               {tabM[j-1][0] += tabM[j][0]; M--; j--;}
        }
        
        printf("%llu\n", recu(0, tabN[0][0], 0, tabM[0][0], 0));
    }
    return 0;
}
