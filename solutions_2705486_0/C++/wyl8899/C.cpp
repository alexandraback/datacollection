#define FILE_IO

#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

const int Dic=521196;
const int maxn=3010;
const int inf=1<<29;
//int tot=1;
char dic[Dic][11];
/*int son[maxt][26];
bool fin[maxt];*/
int f[maxn][5];
char s[maxn];

/*void build(){
  int i,n,p,c;
  scanf("%s",s),n=strlen(s);
  for(p=1,i=0;i<n;++i){
    c=s[i]-'a';
    if(!son[p][c])son[p][c]=++tot;
    p=son[p][c];
  }
  fin[p]=1;
}*/

int main(){
  freopen("dic.txt","r",stdin);
  for(int i=0;i<Dic;++i)
    scanf("%s",dic[i]);
  freopen("t.in","r",stdin);
  freopen("t.out","w",stdout);
  int T=0,n,i,j;
  scanf("%*d");
  while(scanf("%s",s)!=EOF){
    printf("Case #%d: ",++T);
    fprintf(stderr,"%d\n",T);
    n=strlen(s);
    for(i=0;i<n+100;++i)
      for(j=0;j<5;++j)
        f[i][j]=i==n?0:inf;
    for(i=n-1;i>=0;--i){
      for(int j=0;j<Dic;++j){
        int last=-inf,m=strlen(dic[j]),cnt=0,k,fir=4;
        if(j==302152){
          int fuck=1;
        }
        if(i+m>n)continue;
        for(k=0;k<m;++k)
          if(s[i+k]!=dic[j][k]){
            if(k-last<5)
              break;
            else
              last=k,++cnt,fir=min(fir,k);
          }
        if(k==m){
          int t=cnt+f[i+k][max(0,5-(m-last))];
          for(k=0;k<=fir;++k)
            f[i][k]=min(f[i][k],t);
        }
      }
    }
    int ans=inf;
    for(i=0;i<5;++i)
      ans=min(ans,f[0][i]);
    printf("%d\n",ans);
  }
  return 0;
}
