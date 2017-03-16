#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int nt,T,N;
int p[1005][1005];
int f[1005];
int tn,tt;
bool test;
  
void dfs(int n){
     f[n]++;
     if (f[n]>=2) test=true;
     for (int j=1;j<=N;j++) {
         if (p[n][j]==1) dfs(j);
     }
}

int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    nt=0;cin>>T;
    while (T--) {
          nt++;
          cin>>N;
          memset(p,0,sizeof(p));
          test=false;
          for (int i=1;i<=N;i++) {
              cin>>tn;
              for (int j=0;j<tn;j++) {
                  cin>>tt;
                  p[i][tt]=1;
              }
          }
          for (int i=1;i<=N;i++) {
              memset(f,0,sizeof(f));
              dfs(i);
          }
          if (test) printf("Case #%d: Yes\n",nt);
          else printf("Case #%d: No\n",nt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
