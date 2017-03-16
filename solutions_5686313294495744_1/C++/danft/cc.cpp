#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int N=2111;
string v[2111][2];
vector<string> va; 
vector<string> vb; 

vi adj[2111];
int n;
int mat[N], umat[N];
bool mark[N];

bool aug(int u) {
    if(mark[u]) return false;
    mark[u] = true;
    for(int v:adj[u])
        if( mat[v] == -1 || aug( mat[v] ) )
        {
            umat[u]=v;
            mat[v]=u;
            return true;
        }
    return false;
}

int mcbm( ) {
    memset(mat,-1,sizeof mat);
    memset(umat,-1,sizeof umat);

    int ret=0;
    while( 1 ) {
        memset( mark, 0, sizeof( mark ));
        int rinc=0;
        for( int i = 0; i<n; i++) if( umat[i] == -1 && !mark[i] )
            rinc+=aug(i);
        if(!rinc)break;
        ret+=rinc;
    }
    return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
    int T;cin>>T;
    For(tt,0,T) {
        cin>>n;
        va.clear();
        vb.clear();
        For(i,0,N)
            adj[i].clear();
        For(i,0,n) {
            cin>>v[i][0]>>v[i][1];
            va.pb(v[i][0]);
            vb.pb(v[i][1]);
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        va.erase(unique(va.begin(), va.end()), va.end());
        vb.erase(unique(vb.begin(), vb.end()), vb.end());

        For(i,0,n) {
            int u =lower_bound(va.begin(), va.end(), v[i][0]) - va.begin();
            int vv=lower_bound(vb.begin(), vb.end(), v[i][1]) - vb.begin();
            adj[u].pb(vv);
        }
        //cout<<va.size()<<" "<<vb.size()<<" "<<mcbm()<<"@\n";
        int mm = va.size() + vb.size() - mcbm();
        cout<<"Case #"<<tt+1<<": ";
        cout<<n-mm<<endl;
    }
	
	
	return 0;
}
