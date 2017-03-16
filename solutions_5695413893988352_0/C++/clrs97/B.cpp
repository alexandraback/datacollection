#include<cstdio>
#include<cstring>
typedef long long ll;
const ll inf=2000000000000000000LL;
struct P{
  ll v,a,b;
  P(){v=inf;}
  P(ll _v,ll _a,ll _b){v=_v;a=_a;b=_b;}
  P operator+(P o){
    if(v>o.v)return o;
    if(v<o.v)return *this;
    if(a>o.a)return o;
    if(a<o.a)return *this;
    if(b>o.b)return o;
    return *this;
  }
}f[22][2],ans;
int T,C,n,i,j,k,x,y,A[22],B[22],tmp[22];char a[22],b[22];
void write(ll x,int n){
  for(int i=1;i<=n;i++)tmp[i]=x%10LL,x/=10LL;
  for(int i=n;i;i--)printf("%d",tmp[i]);
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1);
    for(i=1;i<=n;i++){
      if(a[i]=='?')A[i]=-1;else A[i]=a[i]-'0';
      if(b[i]=='?')B[i]=-1;else B[i]=b[i]-'0';
    }
    for(i=1;i<=n;i++)for(j=0;j<2;j++)f[i][j]=P();
    f[0][0]=P(0,0,0);
    for(i=0;i<n;i++)for(j=0;j<2;j++)if(f[i][j].v<inf){
      for(x=0;x<=9;x++)if(x==A[i+1]||A[i+1]<0)for(y=0;y<=9;y++)if(y==B[i+1]||B[i+1]<0){
        if(j==0&&x<y)continue;
        if(j==0)k=x>y;else k=1;
        f[i+1][k]=f[i+1][k]+P(f[i][j].v*10LL+x-y,f[i][j].a*10LL+x,f[i][j].b*10LL+y);
      }
    }
    ans=f[n][0]+f[n][1];
    for(i=1;i<=n;i++)for(j=0;j<2;j++)f[i][j]=P();
    f[0][0]=P(0,0,0);
    for(i=0;i<n;i++)for(j=0;j<2;j++)if(f[i][j].v<inf){
      for(x=0;x<=9;x++)if(x==A[i+1]||A[i+1]<0)for(y=0;y<=9;y++)if(y==B[i+1]||B[i+1]<0){
        if(j==0&&x>y)continue;
        if(j==0)k=x<y;else k=1;
        f[i+1][k]=f[i+1][k]+P(f[i][j].v*10LL+y-x,f[i][j].a*10LL+x,f[i][j].b*10LL+y);
      }
    }
    ans=ans+f[n][0]+f[n][1];
    printf("Case #%d: ",++C);
    write(ans.a,n);
    putchar(' ');
    write(ans.b,n);
    puts("");
  }
  return 0;
}