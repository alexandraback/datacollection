#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define ld long double
#define ll long long
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define inf (int)1e9
#define pi pair<int,int>
#define y1 fdfs
using namespace std;
inline void read(int &x){x = 0;while(1){char ch = getchar();if(ch==' '||ch=='\n') break;x = x*10 + ch - '0';}}
inline void write(int x){char wr[12];int k = 0;if(!x) ++k,wr[k] = '0';while(x){++k;wr[k] = char(x%10+'0');x/=10;}for(int i=k;i>=1;--i)putchar(wr[i]);}
int n,m,lol,t;
bool a[51][51];
int c[51],color= -1;
bool bb;
void dfs(int v)
{
    if(lol>m) return;
    if(v==n) {
        ++lol;
        return;
    }
    c[v] = color;
    for(int i=1;i<=n;++i){
        if(a[v][i]) {
            if(c[i]==color&&i!=n) {
                lol = inf;
                return;
            }
            dfs(i);
        }
    }
    c[v] = color + 1;
}
int kol()
{
    lol = 0;
    color+=2;
    dfs(1);
    return lol;
}
void rec(int x,int y,bool p)
{
    if(bb) return;
    a[x][y] = p;
    if(kol()>m)
    {
        a[x][y] = 0;
        return;
    }
    if(x==n-1&&y==n)
    {
        int w = kol();
        if(w==m)
        {
            cout<<"POSSIBLE\n";
            bb = 1;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                    cout<<a[i][j];
                cout<<"\n";
            }
        }
        a[x][y] = 0;
        return;
    }
    if(y==n)
    {
        rec(x+1,1,0);
        rec(x+1,1,1);
    }else{
        rec(x,y+1,0);
        if(y+1!=x) rec(x,y+1,1);
    }
    a[x][y] = 0;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("1.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>t;
    for(int T=1;T<=t;++T)
    {
        cin>>n>>m;
        cout<<"Case #"<<T<<": ";
        memset(a,0,sizeof a);
        bb = 0;
        rec(1,2,0);
        rec(1,2,1);
        if(!bb) cout<<"IMPOSSIBLE\n";
    }
}
