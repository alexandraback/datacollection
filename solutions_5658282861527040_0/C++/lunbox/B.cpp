#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

const int INF = 0X3F3F3F3F;
const double PI = acos(-1.0); //3.1415926535897932384626433832795;
const double EPS = 1e-11;
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1}; //4 direction

#define FOR(i,s,e) for(int i=(s);i<=(int)(e);++i)
#define FORD(i,s,e) for(int i=(s);i>=(int)(e);--i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define CLR(x) memset((x),0,sizeof(x));
#define MEM(a,b) memset((a),b,sizeof(a));
#define PRV(v) REP(vi,v.size()) cout << v[vi] << ' ';cout << endl

inline int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
//inline string tolower(string s){ REP(i,s.SZ) s[i] = tolower(s[i]); return s; }
//inline string toupper(string s){ REP(i,s.SZ) s[i] = toupper(s[i]); return s; }

template<class T> inline T sqr(const T& x) { return x * x; }
template<class T> inline int toint(const T& x){ stringstream ss; ss << x; int r; ss >> r; return r; } 
template<class T> inline int todouble(const T& x){ stringstream ss; ss << x; double r; ss >> r; return r; } 
template<class T> inline string tostr(const T& x) { ostringstream os(""); os << x; return os.str(); }
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}//NOTES:stov(
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

typedef long long LL;
typedef double DB;
typedef stringstream SS;
typedef set< int > SI;
typedef pair< int, int > PII;
typedef vector< int > VI;
typedef vector< VI > VVI;
typedef vector< string > VS;
typedef map< string, int > MSI;
typedef map< int, int > MII;

const int MAXN = 110;
int n, len, a, b, k;
bool flag;
string s, st;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int cas, ans;
    cin>>cas;
    REP(T, cas) {
        cin>>a>>b>>k;
        ans = 0;
        for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            if ((i & j) < k) ++ans;
        printf("Case #%d: %d\n", T+1, ans);        
    }
    return 0;
}
