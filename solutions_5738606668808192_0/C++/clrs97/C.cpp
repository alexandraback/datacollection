#include<cstdio>
typedef long long ll;
const int N=400;
int T,C,n,m,i,j,q[15],p[N],tot,v[N];
inline int cal(int n,int S,int m){
  for(int i=0;i<tot;i++){
    int j=p[i],ret=1;
    for(int k=n-1;~k;k--){
      ret=ret*m%j;
      if(S>>k&1)ret=(ret+1)%j;
    }
    ret=(ret*m+1)%j;
    if(!ret)return j;
  }
  return 0;
}
inline void write(int n,int S){
  putchar('1');
  for(int k=n-1;~k;k--)putchar('0'+(S>>k&1));
  putchar('1');
  for(int j=2;j<=10;j++)printf(" %d",q[j]);
  puts("");
}
void find(){
  scanf("%d%d",&n,&m);
  n-=2;
  for(i=0;m;i++){
    for(j=2;j<=10;j++){
      q[j]=cal(n,i,j);
      if(!q[j])break;
    }
    if(j==11)write(n,i),m--;
  }
}
int main(){
  for(i=2;i<N;i++)if(!v[i]){
    p[tot++]=i;
    for(j=i;j<N;j+=i)v[j]=1;
  }
  scanf("%d",&T);
  for(C=1;C<=T;C++){
    printf("Case #%d:\n",C);
    find();
  }
  return 0;
}