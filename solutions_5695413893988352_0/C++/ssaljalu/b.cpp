#include <stdio.h>
#include <string.h>

int T,TT;
long long pow[19],MAX;
char s1[20],s2[20];
int n;
long long x1,y1,x2,y2;
long long ax,ay;

long long r(long long x){
  x%=10;
  if(x<0)x+=10;
  return x;
}

void print(int cnt, long long x){
  if(cnt==0)return;
  print(cnt-1,x/10);
  printf("%lld",x%10);
}

// x <= y
int dfs1(int v, long long x, long long y){
  if(x>y)return 0;
  if(v==n){
    x1=x;
    y1=y;
    return 1;
  }
  long long c1=(s1[v]!='?'),d1=s1[v]-'0';
  long long c2=(s2[v]!='?'),d2=s2[v]-'0';
  if(c1 && c2)
    return dfs1(v+1,x*10+d1,y*10+d2);
  if(c1 && !c2){
    if(dfs1(v+1,x*10+d1,y*10+d1))return 1;
    return dfs1(v+1,x*10+d1,y*10+r(d1+1));
  }
  if(!c1 && c2){
    if(dfs1(v+1,x*10+d2,y*10+d2))return 1;
    return dfs1(v+1,x*10+r(d2-1),y*10+d2);
  }
  if(x==y){
    if(dfs1(v+1,x*10,y*10))return 1;
    return dfs1(v+1,x*10,y*10+1);
  }
  return dfs1(v+1,x*10+9,y*10);
}

// x >= y
int dfs2(int v, long long x, long long y){
  if(x<y)return 0;
  if(v==n){
    x2=x;
    y2=y;
    return 1;
  }
  long long c1=(s1[v]!='?'),d1=s1[v]-'0';
  long long c2=(s2[v]!='?'),d2=s2[v]-'0';
  if(c1 && c2)
    return dfs2(v+1,x*10+d1,y*10+d2);
  if(c1 && !c2){
    if(dfs2(v+1,x*10+d1,y*10+d1))return 1;
    return dfs2(v+1,x*10+d1,y*10+r(d1-1));
  }
  if(!c1 && c2){
    if(dfs2(v+1,x*10+d2,y*10+d2))return 1;
    return dfs2(v+1,x*10+r(d2+1),y*10+d2);
  }
  if(x==y){
    if(dfs2(v+1,x*10,y*10))return 1;
    return dfs2(v+1,x*10+1,y*10);
  }
  return dfs1(v+1,x*10,y*10+9);
}

int main(){
  int i;
  pow[0]=1;
  for(i=1;i<=18;i++)pow[i]=pow[i-1]*10;
  MAX=4*pow[18];
  scanf("%d",&TT);
  for(T=1;T<=TT;T++){
    scanf("%s%s",s1,s2);
    n=strlen(s1);
    x1=x2=0;
    y1=y2=MAX;
    dfs1(0,0,0);
    dfs2(0,0,0);
    if(y1-x1<=y2-x2){
      ax=x1;ay=y1;
    }else{
      ax=x2;ay=y2;
    }
    printf("Case #%d: ",T);
    print(n,ax);
    printf(" ");
    print(n,ay);
    printf("\n");
  }
  return 0;
}
