#include <bits/stdc++.h>
#define mpr std::make_pair
#define lg std::__lg
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define RI(n) scanf("%d",&n);
#define RI2(a,b) scanf("%d%d",&a,&b);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define mod 1000000007
typedef long long LL;
typedef double LD;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
using namespace std;
vector<int>e[100+10];
int n,l;
//LL p[100+10]={1};
char s[100+10][100+10],a[100+10],b[100+10];
bool vis[100+10]={};
LL ans;
char aa[100+10][100+10];
int cnt[100+10][100+10];
int p[100+10];
int qq[100+10];
bool c[100+10];
void dfs(int now){
    mst(c);
    char last=-1;
    for(int i=0;i<now;i++){
        int tmp=qq[i];
        for(int j=0;j<p[tmp];j++){
            if(last==aa[tmp][j])continue;
            else{
                last=aa[tmp][j];
                if(c[last-'a'])return;
                c[last-'a']=1;
            }
        }
    }
    if(now==n){
        ans++;
        return;
    }
    if(now==0){
        for(int i=0;i<n;i++){
            vis[i]=1;
            qq[now]=i;
            dfs(now+1);
            vis[i]=0;
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                qq[now]=i;
                dfs(now+1);
                vis[i]=0;
            }
        }
    }
}
main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int T,Case=0;
    bool val;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        val=0;
        mst(cnt);
        mst(qq);
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
            l=strlen(s[i]);
            char last=-1;
            int top=-1;
            for(int j=0;j<l;j++){
                if(s[i][j]!=last){
                    last=s[i][j];
                    aa[i][++top]=s[i][j];
                    cnt[i][top]=1;
                }
                else{
                    cnt[i][top]++;
                }
            }
            p[i]=top+1;
        }
        ans=0;
        dfs(0);
        printf("Case #%d: ",++Case);
        printf("%d\n",ans);
    }
}
