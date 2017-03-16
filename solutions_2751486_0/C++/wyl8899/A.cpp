//#define FILE_IO

#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
#ifdef unix
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef double lf; 

typedef pair<int,int> pii;
typedef pair<lf,lf> pff;
#define mp make_pair
#define X first
#define Y second  

#define pb push_back
#define forI_(i,V,_) for(typeof(V.end())i=_;i!=V.end();++i)
#define forI(i,V) forI_(i,V,V.begin())

const int maxn=1000010;
char s[maxn];
//int a[maxn];

int main(){
#ifdef FILE_IO
  freopen("t.in","r",stdin);
  freopen("t.out","w",stdout);
#endif
  int T,Case=0;
  int n,m,i,l,now;
  ll ans;
  for(scanf("%d",&T);T--;){
    scanf("%s%d",s+1,&n);
    m=strlen(s+1);
    for(i=1;i<=m;++i)
      if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        s[i]=0;
      else
        s[i]=1;
    ans=0,l=0,now=0;
    for(i=1;i<=m;++i){
      if(!s[i]){
        if(now>=n)l=i-n;
        now=0;
        ans+=l;
      }else{
        now++;
        if(now>=n)
          ans+=i-n+1;
        else
          ans+=l;
      }
    }
    printf("Case #%d: %lld\n",++Case,ans);
  }
  return 0;
}
