#include <string.h>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

#define rep(i,s,t) for(int i=s;i<t;i++)
int t,k,l,s;
double p[30];
double Max,sum;
char a[105],b[105];

map<char,int>mp;
double pr[30];
int mm[30];
int nn;

const int N=6000;
const int S=30;
int fail[N],ch[N][S],sz,leaf[N];

void init(int i){
    fail[i]=leaf[i]=0;
    memset(ch[i],0,sizeof ch[i]);
}

void insert(int j,int v){
    int p=0;
    for(int i=0;i<=j;i++){
        int id=mp[b[i]];
        if(!ch[p][id]){
            init(sz);ch[p][id]=sz;sz++;
        }
        p=ch[p][id];
    }
    if(v){
        leaf[p] =1;
    }
}

void build(){
    queue<int>q;
    fail[0]=0;
    rep(i,1,nn+1) if(ch[0][i]){
        q.push(ch[0][i]),fail[ch[0][i]]=0;
    }
    while(!q.empty()){
        int x=q.front();q.pop();
        leaf[x] |= leaf[fail[x]];
        rep(i,1,nn+1){
            int nxt=ch[x][i],p=fail[x];
            if(!nxt) ch[x][i]=ch[p][i];
            else{
                q.push(nxt);
                fail[nxt]=ch[p][i];
            }
        }
    }
}

double dp[105][N];
double num[105][N][105];

void solve(){
    for(int i=0;i<=s;i++) for(int j=0;j<=sz;j++) dp[i][j]=-1.0;
    dp[0][0]=0;
    for(int i=0;i<s;i++) for(int j=0;j<sz;j++) if(dp[i][j]!=-1.0){
        for(int k=1;k<=nn;k++){
            int nxt = ch[j][k];
            int v=0;
            if(leaf[nxt]) v++;
            double vv=dp[i][j]+v;
            if(dp[i+1][nxt]==-1 || dp[i+1][nxt]<vv) dp[i+1][nxt]=vv;
        }
    }
    Max=0;
    for(int i=0;i<sz;i++) if(dp[s][i]>Max){
        Max=dp[s][i];
    }

    for(int i=0;i<=s;i++) for(int j=0;j<=sz;j++) for(int k=0;k<=s;k++) num[i][j][k]=-1.0;
    num[0][0][0]=1;

    for(int i=0;i<s;i++) for(int j=0;j<sz;j++) for(int r=0; r<=Max;r++)if(num[i][j][r]!=-1.0){
        for(int k=1;k<=nn;k++){
            int nxt = ch[j][k];
            int v=r;
            if(leaf[nxt]) v++;
            if(num[i+1][nxt][v]==-1) num[i+1][nxt][v]=0;
            num[i+1][nxt][v]+=num[i][j][r]*pr[k];
        }
    }
    sum=0;
    for(int i=0;i<sz;i++) for(int r=0;r<=Max;r++) if(num[s][i][r]!=-1.0)sum+=num[s][i][r]*r;
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
   scanf("%d",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%d%d%d%s%s",&k,&l,&s,a,b);
        for(int i=0;i<26;i++) p[i]=0.0;
        int len=strlen(a),lb=strlen(b);
        for(int i=0;i<len;i++) p[a[i]-'A']+=1.0;
        for(int i=0;i<26;i++) p[i]/=len;
        bool tag=1;
        for(int i=0;i<lb;i++){
            if(p[b[i]-'A']==0.0){
                tag=0;break;
            }
        }
        if(!tag){
            printf("Case #%d: %lf\n",ca,0.0);
        }
        else{
            nn=0;mp.clear();init(0);sz=1;
            for(int i=0;i<26;i++) if(p[i]!=0.0){
                nn++;
                mp[(char)(i+'A')]=nn;
                pr[nn]=p[i];
                mm[nn]=i;
            }
            for(int i=0;i<lb;i++){
                insert(i,(i==lb-1?1:0));
            }
             build();
            solve();
           // printf("%lf %lf\n",Max,sum);
            printf("Case #%d: %lf\n",ca,Max-sum);
        }
    }
    return 0;
}
