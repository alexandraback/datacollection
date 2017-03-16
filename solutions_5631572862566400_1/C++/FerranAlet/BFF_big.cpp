//Done by Ferran Alet

#include<bits/stdc++.h>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) //cerr << #x << " = " << x << endl
#define Debug(v) //cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define DEBUG(M) //cerr << #M <<":"<<endl; for(int iM=0;iM<M.size();++iM) { for(int jM=0;jM<M[iM].size();++jM) cerr<<M[iM][jM]<<' '; cerr<<endl;} cerr<<endl
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
    freopen("C-large-sol.out","w",stdout);
    freopen("C-large.in","r",stdin);
    //freopen("Bff_sample.in","r",stdin);
    DRI(casos);
    FORU(cas,casos){
        cerr<<cas<<endl;
        debug(cas);
        DRI(n);
        VI a(n);
        FOR(i,n) cin>>a[i];
        FOR(i,n) a[i]--;
        int cont = 0;
        VI c(n,-1); //visit time
        int res = 1;
        VVI happy(n);
        VI bff(n,-1);
        int happies = 0;
        FOR(i,n){
            if(c[i]!=-1) continue;
            int p = i;
            int primer = cont;
            c[p] = cont++;
            debug(p);
            debug(c[p]);
            debug(a[p]);
            debug(c[a[p]]);
            //cerr<<"---------"<<endl;
            while(c[a[p]]<primer){
                debug(p);
                debug(c[p]);
                debug(a[p]);
                debug(c[a[p]]);
                //cerr<<"---------"<<endl;
                p = a[p];
                c[p] = cont++;
            }
            //c[a[p]]!=-1
            if(c[a[p]]<primer){ //Encaixo amb altra trunyaco
                if(bff[a[p]]!=-1){
                    happy[a[p]].push_back(c[p]-primer+1);
                    //happy[bff[a[p]]].push_back(c[p]-primer+1);
                }
            }
            else{
                if(c[p]-c[a[p]]==1) {
                    //happy[p].push_back(c[p]-c[i]+1);
                    happy[a[p]].push_back(c[p]-c[i]-1);
                    if(bff[p]==-1){
                        happies+=2;
                        bff[p] = a[p];
                        bff[a[p]]= p;
                    }
                }
                else res = max(res,c[p]-c[a[p]]+1);
            }
        }
        FOR(i,n) {
            sort(happy[i].begin(),happy[i].end());
            reverse(happy[i].begin(),happy[i].end());
        }
        DEBUG(happy);
        FOR(i,n){
            if(happy[i].size()>=1){
                happies+=happy[i][0];
            }
            //if(happy[i].size()>1) happies+=happy[i][0]+happy[i][1]-2;
        }
        cout << "Case #"<<cas<<": ";
        cout << max(res,happies) <<endl;
    }
}
