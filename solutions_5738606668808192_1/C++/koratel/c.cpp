#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int (I) = (A); (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int (I) = (A); (I) >= (B); (I)--)
#define FOREACH(I,A)  for(__typeof(A.begin()) I = A.begin(); I != A.end(); ++I)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAIN(A,X)  (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
using namespace std;
typedef signed long long slong;
typedef long double ldouble;
const slong Infinity = 1000000100;
const ldouble Epsilon = 1e-9;

template<typename T, typename U> ostream& operator << (ostream& os, const pair<T,U>&p) { return os << "(" << p.X << "," << p.Y << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& V) { os << "["; FORW(i,0,SIZE(V)) os << V[i] << ((i==SIZE(V)-1) ? "" : ","); return os << "]"; }
template<typename T> ostream& operator << (ostream &os, const set<T>& S) {os << "("; for(T i: S) os << i << (i==*S.rbegin()?"":","); return os << ")"; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& M){os << "{"; for(pair<T,U> i: M) os << i << (i.X==M.rbegin()->X?"":","); return os << "}"; }
template<typename T, typename F> T lbound(T p, T q, F f) { while(p < q) { T r = p+(q-p)/2; if(f(r)) q = r; else p = r+1; } return p; }
template<typename T, typename F> T lboundl(T p, T q, F f) { FOR(i,1,70) { T r = (p+q)/2; if(f(r)) q = r; else p = r; } return p; }

vector<int> primes;

int find_proof(string s, int base)
{
    int n = s.length();
    for(int p : primes)
    {
        slong mod = 0;
        FOR(i,0,n-1)
        {
            mod = (mod*base + s[i])%p;
        }
        if(mod == 0) return p;
    }
    return 0;
}

void solve(int num)
{
    int N, J;
    cin >> N >> J;
    map<string,vector<int> > jamcoins;

    while(SIZE(jamcoins) < J)
    {
        string s(N,1);
        vector<int> proof;
        FOR(i,1,N-2) s[i] = rand()%2;
        if(jamcoins.count(s)) continue;
        FOR(i,2,10)
        {
            int d = find_proof(s,i);
            if(d == 0) break;
            proof.PB(d);
        }

        if(proof.size() == 9)
        {
            FOR(i,0,N-1) s[i] += '0';
            jamcoins.insert(MP(s,proof));
        }
    }

    cout<<"Case #"<<num<<":\n";
    for(auto coin : jamcoins)
    {
        cout << coin.X;
        for(int d : coin.Y) cout << " " << d;
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    srand(time(0));
    FOR(i,2,(1<<15))
    {
        int kk = 1;
        for(int j=2; j*j<=i; j++)
        {
            if(i%j == 0) kk = 0;
        }
        if(kk) primes.PB(i);
    }
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
