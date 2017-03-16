#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					cin>>n
#define p(n)					cout<<n<<'\n'
#define sd(n)					int n;cin>>n;
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 cout<<str<<'\n'
#define pans(t,ans)                             do{cout<<"Case #"<<t<<": "<<ans<<endl;} while(0)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void print_mat(vvi &mat)
{
    int s1=sz(mat),s2=sz(mat[0]);
    int i,j;
    FOR(i,0,s1)
    {
        FOR(j,0,s2) cout<<mat[i][j]<<' ';
        cout<<endl;
    }
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(T);
    int i,j,t,k;
    FOR(t,0,T)
    {
        sd(n);sd(m);sd(k2);
        int N=n*m;
        int ans=N;
        FOR(i,1,1<<N)
        {
            vvi mat(n,vi(m,0));
            
            FOR(j,0,n)
            {
                FOR(k,0,m)
                {
                    if (i&(1<<(j*m+k))) mat[j][k]=1;
                }
            }
            int tans=__builtin_popcount(i);
            int covered=tans;
            FOR(j,1,n-1)
            {
                FOR(k,1,m-1)
                {
                    if (mat[j][k]==1) continue;
                    bool succ=true;
                    int h=j,v=k;
                    while (h<n&&mat[h][k]==0) h++;
                    if (h==n) succ=false;
                    h=j;
                    while (h>=0&&mat[h][k]==0) h--;
                    if (h<0) succ=false;
                    
                    while (v<m&&mat[j][v]==0) v++;
                    if (v==m) succ=false;
                    v=k;
                    while (v>=0&&mat[j][v]==0) v--;
                    if (v<0) succ=false;
                    if (succ)
                    {
                        covered++;
//                        cout<<j<<' '<<k<<" covered"<<endl;
                    }
                    
                }
            }
//            if (tans==4&&covered>=k2)
//            {
//                print_mat(mat);
//                cout<<endl;
//            }
            if (covered>=k2) ans=min(ans,tans);
        }
        pans(t+1,ans);
    }
}
