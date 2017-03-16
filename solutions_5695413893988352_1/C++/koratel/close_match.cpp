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

typedef pair<string,string> pss;
string C, J, CC, JJ;

int match(int a, int b)
{
    FOR(i,a,b)
    {
        if(C[i] != '?' && J[i] != '?' && C[i] != J[i]) return 0;
    }
    return 1;
}

void mini_match(int a, int b)
{
    FOR(i,a,b)
    {
        if(C[i] == '?')
        {
            if(J[i] == '?')
            {
                C[i] = J[i] = '0';
            }
            else C[i] = J[i];
        }
        else if(J[i] == '?')
        {
            J[i] = C[i];
        }
    }
}

string fill_with(string s, int a, int b, char c)
{
    FOR(i,a,b)
    {
        if(s[i] == '?') s[i] = c;
    }
    return s;
}

slong val(string s)
{
    slong ret = 0;
    for(char c : s)
    {
        ret = ret*10 + (c - '0');
    }
    return ret;
}

void solve(int num)
{
    cin >> C >> J;
    CC = C;
    JJ = J;
    int n = C.length();

    pair<slong, pss> ans = {Infinity*Infinity, {"",""}};

    if(match(0,n-1))
    {
        mini_match(0,n-1);
        pair<slong,pss> cur = {abs(val(C)-val(J)), {C,J}};
        ans = cur;
    }
    else
    {
        FOR(i,0,n-1) // first diff
        {
            if(i>0 && !match(0,i-1)) continue;
            FOR(ci,'0','9')
            {
                FOR(ji,'0','9')
                {
                    C = CC;
                    J = JJ;
                    if(C[i]!='?' && C[i]!=ci) continue;
                    if(J[i]!='?' && J[i]!=ji) continue;
                    C[i] = ci;
                    J[i] = ji;
                    mini_match(0,i-1);
                    if(ci > ji)
                    {
                        C = fill_with(C, i+1, n-1, '0');
                        J = fill_with(J, i+1, n-1, '9');
                    }
                    else
                    {
                        C = fill_with(C, i+1, n-1, '9');
                        J = fill_with(J, i+1, n-1, '0');
                    }
                    pair<slong,pss> cur = {abs(val(C)-val(J)), {C,J}};
                    ans = min(ans, cur);
                }
            }
        }
    }

    cout<<"Case #"<<num<<": ";
    cout << ans.Y.X << " " << ans.Y.Y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
