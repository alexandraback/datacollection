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

void solve(int num)
{
    string s;
    cin >> s;
    vector<int> hist(300,0);
    for(char c : s) hist[c]++;
    vector<int> ans(11,0);

    vector<int> nums = {0,4,6,8,5,7,2,3,1,9};
    string match = "ZUXGFVWHOI";
    vector<string> words = {"ZERO", "ONE", "TWO", "THREE",
    "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    FOR(i,0,9)
    {
        int n = nums[i];
        ans[n] = hist[match[i]];
        for(char c : words[n]) hist[c] -= ans[n];
    }

    cout<<"Case #"<<num<<": ";

    FOR(i,0,9) FOR(j,1,ans[i]) cout << i;
    cout << "\n";
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
