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

int n;

string A,B;
int res, rA, rB;

void rec(int pos, int a, int b){
    //cerr<<pos<<' '<<a<<' '<<b<<'!'<<endl;
    if(pos==2*n){
        int act = abs(a-b);
        if(act<res or (act==res && a<rA) or (act==res && a==rA && b<rB)){
            res = act;
            rA = a;
            rB = b;
        }
        return;
    }
    if(pos<n){
        if(A[pos]=='?'){
            FOR(i,10) {
                rec(pos+1,10*a+i,b);
            }
        }
        else rec(pos+1,10*a+A[pos]-'0',b);
    }
    else{
        if(B[pos%n]=='?'){
            FOR(i,10){
                rec(pos+1,a,10*b+i);
            }
        }
        else rec(pos+1,a,b*10+B[pos%n]-'0');
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("B-small-sol.out","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    DRI(casos);
    FORU(cas,casos){
        debug(res);
        res = INF;
        cin>>A>>B;
        n = A.size();
        rec(0,0,0);
        VI AA(n),BB(n);
        FOR(i,n){
            AA[i] = rA%10;
            rA/=10;
        }
        FOR(i,n){
            BB[i] = rB%10;
            rB/=10;
        }
        reverse(AA.begin(),AA.end());
        reverse(BB.begin(),BB.end());
        cout <<"Case #"<<cas<<": ";
        FOR(i,n) cout<<AA[i]; cout <<' ';
        FOR(i,n) cout<<BB[i]; cout <<endl;
    }
}
