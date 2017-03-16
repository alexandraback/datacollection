#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME "Bs0"
#define UsingFile 1

char p[105];
char q[105];
double x[55];
int ct[55];
double dp[105][105];
int f[105][26];
bool allpo(){
    for(int i=0;q[i];i++)
        if(ct[q[i]-'A']==0)return 0;
    return 1;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        int K,L,S;//K-keyboard 
        scanf("%d%d%d",&K,&L,&S);
        scanf("%s%s",p,q);
        memset(ct,0,sizeof ct);
        for(i=0;p[i];i++)ct[p[i]-'A']++;
        for(i=0;i<26;i++)x[i]=1.*ct[i]/K;
        for(i=L-1;i>=0;i--){
            string a,b;
            for(j=0;j<i;j++)a+=q[j];
            for(j=0;j<i;j++)b+=q[L-1-j];
            reverse(b.OP,b.ED);
            if(a==b)break;
        }
        int maxb=0;
        int rem=S;
        int jump=i;
        if(allpo()){
            while(rem>=L)
                rem-=L-i,maxb++;
        }
        for(i=0;i<L;i++)for(j=0;j<26;j++){
            if(j==q[i]-'A'){
                f[i][j]=i+1;
            }else{
                string T;
                for(k=0;k<i;k++)T+=q[k];
                T+=j+'A';
                for(k=T.SZ-1;k>=0;k--){
                    if(T.substr(0,k)==T.substr(T.SZ-k,k)){
                        f[i][j]=k;
                        break;
                    }
                }
            }
        }
        if(maxb){
            memset(dp,0,sizeof dp);
            dp[0][0]=1;
            double ans=maxb;
            for(i=0;i<S;i++)for(j=0;j<L;j++)if(dp[i][j]>1e-8){
                for(k=0;k<26;k++)if(ct[k]){
                    int next=f[j][k];
                    double pp=dp[i][j]*x[k];
                    if(next==L){
                        ans-=pp;
                        dp[i+1][jump]+=pp;
                    }else {
                        dp[i+1][next]+=pp;
                    }
                }
            }
            printf("Case #%d: %.8f\n",CA,ans);
        }else printf("Case #%d: 0.0\n",CA);
    }
    return 0;
}

