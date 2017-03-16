#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
double bc[3009][3009]; // (i ch k) * 2^-i
double sm(ll m, ll k){
  double ct=0;
  if(m%2==0)
    ct+=bc[m][m/2]*0.5;
  for(int i=k;i<=(m-1)/2;i++){
    ct+=bc[m][i];
  }
  return ct;
}
int main(){
  ll t;
  ll n,x,y;
  ll lay,kr,d;
  bc[0][0]=1.0;
  for(int i=1;i<3009;i++){
    bc[i][0]=bc[i-1][0]*0.5;
    bc[i][i]=bc[i-1][i-1]*0.5;
  }
  for(int i=1;i<3009;i++){
    for(int j=1;j<i;j++){
      bc[i][j]=(bc[i-1][j]+bc[i-1][j-1])*0.5;
    }
  }
  scanf("%lld",&t);
  for(int z=1;z<=t;z++){
    scanf("%lld %lld %lld",&n,&x,&y);
    printf("Case #%d: ",z);
    if(x<0)
      x*=-1;
    lay=(x+y)/2;
    n-=(lay+lay*(lay-1)*2);
    if(n<=0){
      printf("0.0\n");
      continue;
    }
    d=lay*4+1;
    kr=y+1;
    if(x==0){
      if(n>=d)
	printf("1.0\n");
      else
	printf("0.0\n");
      continue;
    }
    if(kr+(d+1)/2<=n+1){
      printf("1.0\n");
      continue;
    }
    double pr=0.5;
    if(kr>n-(kr-1))
      pr-=sm(n,n-(kr-1));
    else
      pr+=sm(n,kr);
    if(pr<0)
      pr=0;
    printf("%.7lf\n",pr);
  }
  return 0;
}
