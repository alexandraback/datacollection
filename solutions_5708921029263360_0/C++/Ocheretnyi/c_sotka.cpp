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
const int N = 15;
int t,J,P,S,K;
char used1[N][N],used2[N][N],used3[N][N];
char used[N*N*N];
vector<pair<int,pair<int,int> > >q,ans;
int cur = 0;
void rec(char pos,char p)
{
    int i = ans[pos].x;
    int j = ans[pos].y.x;
    int k = ans[pos].y.y;
    used1[i][j]+=p;
    used2[j][k]+=p;
    used3[i][k]+=p;
    cur+=p;
    used[pos] = p;
    if(used1[i][j]>K||used2[j][k]>K||used3[i][k]>K)
    {
        p*=-1;
        used1[i][j]+=p;
        used2[j][k]+=p;
        used3[i][k]+=p;
        used[pos] = 0;
        cur+=p;
        return;
    }
    if(cur+ans.size()-1-pos<=q.size())
    {
        p*=-1;
        used1[i][j]+=p;
        used2[j][k]+=p;
        used3[i][k]+=p;
        used[pos] = 0;
        cur+=p;
        return;
    }
    if(pos==ans.size()-1)
    {
        vector<pair<int,pair<int,int> > >zz;
        for(int w=0;w<ans.size();++w)
            if(used[w]) zz.pb(ans[w]);
        if(zz.size()>q.size()) q = zz;
        p*=-1;
        used1[i][j]+=p;
        used2[j][k]+=p;
        used3[i][k]+=p;
        used[pos] = 0;
        cur+=p;
        return;
    }
    rec(pos+1,1);
    rec(pos+1,0);
    p*=-1;
    used1[i][j]+=p;
    used2[j][k]+=p;
    used3[i][k]+=p;
    used[pos] = 0;
    cur+=p;
}
int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("1.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>t;
    for(int T=1;T<=t;++T)
    {
        cin>>J>>P>>S>>K;
        memset(used1,0,sizeof used1);
        memset(used2,0,sizeof used2);
        memset(used3,0,sizeof used3);
        memset(used,0,sizeof used);
        q.clear();
        ans.clear();
        cout<<"Case #"<<T<<": ";
        for(int i=1;i<=J;++i)
        for(int j=1;j<=P;++j)
        for(int k=1;k<=S;++k)
            ans.pb(mp(i,mp(j,k)));
        rec(0,1);
        rec(0,0);
        cout<<q.size()<<"\n";
        for(int i=0;i<q.size();++i)
            cout<<q[i].x<<' '<<q[i].y.x<<' '<<q[i].y.y<<"\n";
    }
}
