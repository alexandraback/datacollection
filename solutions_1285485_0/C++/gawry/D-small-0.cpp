#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
#define MAX 2000000
int h,w,d;
char m[33][33];
#define EPS (1e-6)
long double frac(long double x){
  long double y=x-(int)x;
  if(fabs(y-1)<EPS)return 0;
  assert(y>-EPS);
  return y;
}
long double f(long double a,long double b){
  if(fabs(b)<EPS)return 1000;
  if(frac(a)<EPS)return 1/fabs(b);
  if(b>0)return (1-frac(a))/b;
  if(b<0)return frac(a)/-b;
  return 1000;
}
int g(long double cur,long double dir){
  if(frac(cur)<EPS){
    int tmp=(int)(cur+EPS);
    assert(fabs(tmp-cur)<EPS);
    return dir>0?tmp:tmp-1;
  }
  return (int)cur;
}
void solve(){
  scanf("%d %d %d",&h,&w,&d);
  for(int i=0;i<h;i++)scanf(" %s",m[i]);
  long double sx,sy;
  for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(m[i][j]=='X'){sx=i+0.5;sy=j+0.5;}
  int ans=0;
  for(int _dx=-d;_dx<=d;_dx++)for(int _dy=-d;_dy<=d;_dy++)if((_dx||_dy)&&__gcd(abs(_dx),abs(_dy))==1){
    int dx=_dx,dy=_dy;
    long double scale=sqrt(dx*dx+dy*dy),len=0,cx=sx,cy=sy;
    bool correct=true;
    do{
      long double t=min(f(2*cx,2*dx),f(2*cy,2*dy));
      assert(t>0);
      cx+=t*dx;
      cy+=t*dy;
      len+=t*scale;
      //cerr<<cx<<" "<<cy<<" "<<dx<<" "<<dy<<endl;
      assert(cx>0&&cy>0);
      char next=m[g(cx,dx)][g(cy,dy)];
      if(next!='#')continue;
      if(frac(cx)<EPS&&frac(cy)<EPS){
        assert(dx&&dy);
        char left=m[g(cx,-dx)][g(cy,dy)];
        char right=m[g(cx,dx)][g(cy,-dy)];
        if(left!='#'&&right!='#')correct=false;
        else{
          if(left=='#')dy=-dy;
          if(right=='#')dx=-dx;
        }
      }else{
        if(frac(cx)<EPS)dx=-dx;
        if(frac(cy)<EPS)dy=-dy;
      }
    }while(correct&&(fabs(cx-sx)>EPS||fabs(cy-sy)>EPS)&&len<d+EPS);
    ans+=correct&&abs(cx-sx)<EPS&&abs(cy-sy)<EPS&&len<d+EPS;
  }
  printf("%d\n",ans);
}
main(){
  char in[100],out[100],*pos;
  strcpy(in,__FILE__);
  strcpy(out,__FILE__);
  pos=in;
  while(*pos!='.')pos++;
  strcpy(pos,".in");
  pos=out;
  while(*pos!='.')pos++;
  strcpy(pos,".out");
  freopen(in,"r",stdin);
  freopen(out,"w",stdout);
  int t;
  scanf("%d",&t);
  for(int tt=1;tt<=t;tt++){
    fprintf(stderr,"processing case %d\n",tt);
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
  freopen(out,"r",stdin);
  char c;while((c=getc(stdin))!=EOF)putc(c,stderr);
}

