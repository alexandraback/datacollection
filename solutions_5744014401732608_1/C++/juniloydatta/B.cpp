#include<bits/stdc++.h>

using namespace std;
#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 1005

using namespace std;
int mat[55][55];
LL pw[55];

string ar[]={"IMPOSSIBLE","POSSIBLE"};
int main(){
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int test; cin>>test;
    for(int kase=1;kase<=test;kase++){
        int n; LL m; cin>>n>>m;
        LL mx=(1ll<<(n-2));
        cout<<"Case #"<<kase<<": ";
        if(m>mx) cout<<ar[0]<<endl;
        else{
            vector<int>V;
            int st=2;
            int rem=n-2;
            int g;
            pw[1]=1ll;
            pw[1]=1ll;
            for(int i=2;i<=n;i++){
                pw[i]=pw[i-1]*2ll;
                g=i;
                if(pw[i]>m){
                    g=i-1;
                    break;
                }
            }
            mat[1][n]=1;
            for(int i=2;i<=g;i++){
                mat[1][i]=1;
                for(int j=i+1;j<=g;j++){
                    mat[i][j]=1ll;
                }
                mat[i][n]=1;
            }
            m-=pw[g];
            int gg=g+1;
            while(m>0 && g>0){
                if((pw[g]/2)>m) g--;
                else{
                    mat[g][gg]=1;
                    mat[gg][n]=1;
                    m-=pw[g]/2;
                    g--;
                }
            }
            if(m==1){
                mat[1][gg]=1,m--;
                mat[gg][n]=1;
            }
            if(m>0) cout<<ar[0]<<endl;
            else{
                cout<<ar[1]<<endl;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        cout<<mat[i][j];
                    }
                    cout<<endl;
                }
            }
        }
        memset(mat,0,sizeof mat);
    }
    return 0;
}

