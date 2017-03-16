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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("Asmall.out","w",stdout);
    freopen("Azero.in","r",stdin);
    int casos;
    cin>>casos;
    VI d(1000100,INF);
    VI ant(1000100,-1);
    d[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        if( pos+1<=1000000 && d[pos+1]>d[pos]+1){
            d[pos+1]=d[pos]+1;
            ant[pos+1] = pos;
            q.push(pos+1);
        }
        stringstream ss;
        ss<<pos;
        string st;
        ss>>st;
        reverse(st.begin(),st.end());
        stringstream sss;
        sss<<st;
        int aux;
        sss>>aux;
        if(aux<=1000000 && d[aux]>d[pos]+1){
            ant[aux] = pos;
            d[aux]= d[pos]+1;
            q.push(aux);
        }
    }
    FORU(cas,casos){
        DRI(a);
        /*cout<<d[a]<<": ";
        cout<<a<<"<-";
        while(ant[a]!=-1){
            if(ant[a]!=a-1) cout<<ant[a]<<"<-";
            a = ant[a];
        }
        cout<<endl;*/
        cout<<"Case #"<<cas<<": "<<d[a]<<endl;
    }
}
