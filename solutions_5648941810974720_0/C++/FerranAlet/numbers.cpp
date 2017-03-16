//Done by Ferran Alet

#include<bits/stdc++.h>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define Debug(v) cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define DEBUG(M) cerr << #M <<":"<<endl; for(int iM=0;iM<M.size();++iM) { for(int jM=0;jM<M[iM].size();++jM) cerr<<M[iM][jM]<<' '; cerr<<endl;} cerr<<endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORS(x,y) for(int x=0;x<int(y.size());++x)
#define FORU(x,y) for(int x=1;x<=y;x++)
#define RFOR(x,y) for(int x=y-1;x>=0;--x)
#define DRI(x) int x; cin>>x
#define DRII(x,y) int x,y; cin>>x>>y
#define DRIII(x,y,z) int x,y,z; cin>>x>>y>>z
#define PB push_back
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;
typedef vector<VP> VVP;

/*ZERO        Z
ONE         O-W-U-Z
TWO         W
THREE       R-Z-U
FOUR        U
FIVE        F-U
SIX         X
SEVEN
EIGHT       H-3
NINE

T: 3,8
H: 3,8
R:
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("A-small.out","w",stdout);
    freopen("A-small-attempt0.in","r",stdin);
    string s;
    DRI(casos);
    FORU(cas,casos){
        debug(cas);
        cin>>s;
        map<char,int> M;
        FOR(i,s.size()) M[s[i]]++;
        VI v(10);
        v[0] = M['Z'];
        v[1] = M['O']-M['Z']-M['W']-M['U'];
        v[2] = M['W'];
        v[3] = M['R']-M['Z']-M['U'];
        v[4] = M['U'];
        v[5] = M['F']-M['U'];
        v[6] = M['X'];
        v[7] = M['S']-M['X'];
        v[8] = M['H']-v[3];
        v[9] = (M['N']-v[1]-v[7])/2;
        cout<<"Case #"<<cas<<": ";
        FOR(i,10) FOR(j,v[i]) cout<<i;
        cout<<endl;
    }
}
