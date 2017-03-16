#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;

char s[N];
int p[N];
int pre[N];
double dp[N][N][N];
int go[N][255];
int main(){
  freopen("1.in","r",stdin);
  freopen("1.txt","w",stdout);
  int tt, k, l, n, cc, i, j;
  char ch;
  scanf("%d",&tt);
  for(int cas=1; cas<=tt; ++cas){
    printf("Case #%d: ", cas);
    scanf("%d%d%d",&k,&l,&n);
    cc = k;
    scanf("%s",s);
    memset(p,0,sizeof(p));
    for(i=0;i<k;++i){
      p[s[i]]++;
    }
    scanf("%s",s);
    
    for(i=0;i<l;++i) if(p[s[i]]==0) break;
    if(i!=l){
      puts("0.0");
      continue;
    }
    
    for(i=1;i<l;++i){
      for(j=0;j+i<l;++j) if(s[j]!=s[i+j]) break;
      if(j+i==l) break;
    }
   

    int mx = 0;
    if(n>=l){
      mx = 1 + (n-l)/i;
    }
    memset(pre,-1,sizeof(pre));
    int j=-1;
    for(i=1;i<l;++i){
      while(j!=-1 && s[i]!=s[j+1]) j=pre[j];
      if(s[i]==s[j+1]) ++j;
      pre[i]=j;
    }
    
    
    memset(go,0,sizeof(go));
    go[0][s[0]]=1;
    for(i=0;i<l;++i){
      for(ch='A';ch<='Z';++ch){
        int j = i;
        while(j!=-1 && s[j+1] != ch) j=pre[j];
        if(s[j+1] == ch) ++j;
        go[i+1][ch] = j+1;
      }
    }


    double ans = 0; 
    for(i=0;i<=n;++i) for(j=0;j<=mx;++j) for(k=0;k<=l;++k) dp[i][j][k]=0;
    dp[0][0][0] = 1;
    for(i=0;i<n;++i) for(j=0;j<=mx;++j) for(k=0;k<=l;++k) for(ch='A';ch<='Z';++ch){
      int res = go[k][ch]==l;
      dp[i+1][j+res][go[k][ch]] += dp[i][j][k]*p[ch]*1.0/cc;
    }
    for(j=1;j<=mx;++j) for(k=0;k<=l;++k) ans += 1.0*j*dp[n][j][k];
    printf("%.6f\n", mx-ans);
  }
  return 0;
}
