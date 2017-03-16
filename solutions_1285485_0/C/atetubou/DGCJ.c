#include<stdio.h>
#include<string.h>
#include<math.h>

int abs(int a){
  if(a<0)return -a;
  return a;
}

int gcd(int a,int b){
  if(a>b){
    int t=a;
    a=b;
    b=t;
  }
  if(a==0)return b;
  return gcd(b%a,a);
}
int h,w,d;
char in[300][300];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int tx[]={0,1,1,0},ty[]={0,0,1,1};

int can(int x,int y,int a,int b){
  int co=0;
  int r=abs(2*a*b);
  x*=r;
  y*=r;
  //puts("");
  //printf("start %d %d %d %d\n",x,y,a,b);
  while(1){
    x+=a;
    y+=b;
    ++co;    
    int lx=co*a,ly=co*b;
    /*
    printf("%d/%d %d/%d %.5f %.5f %.5f\n",
           x,r,y,r,lx*1.0/r,ly*1.0/r,sqrt(lx*lx+ly*ly)/r);
    */
    if(lx*lx+ly*ly>r*r*d*d)break;
    if(x%r==0 && y%r==0 &&
       in[x/r][y/r]=='X')return 1;

    if(lx*lx+ly*ly>=r*r*d*d)break;
    if(x%r==r/2){
      if(y%r==r/2){
        int idx=(a<0)?(b<0)?2:1:(b<0)?3:0;
        int ix=x/r,iy=y/r;
        if(in[ix+tx[idx+1&3]][iy+ty[idx+1&3]]=='#' &&
           in[ix+tx[idx+2&3]][iy+ty[idx+2&3]]=='#' &&
           in[ix+tx[idx+3&3]][iy+ty[idx+3&3]]=='#'){
          a=-a;
          b=-b;
        }else if(in[ix+tx[idx+1&3]][iy+ty[idx+1&3]]!='#' &&
                 in[ix+tx[idx+2&3]][iy+ty[idx+2&3]]=='#' &&
                 in[ix+tx[idx+3&3]][iy+ty[idx+3&3]]!='#'){
          break;
        }else if(in[ix+tx[idx+1&3]][iy+ty[idx+1&3]]=='#' &&
                 in[ix+tx[idx+2&3]][iy+ty[idx+2&3]]=='#' &&
                 in[ix+tx[idx+3&3]][iy+ty[idx+3&3]]!='#'){
          if(idx%2)b=-b;
          else a=-a;
        }else if(in[ix+tx[idx+1&3]][iy+ty[idx+1&3]]!='#' &&
                 in[ix+tx[idx+2&3]][iy+ty[idx+2&3]]=='#' &&
                 in[ix+tx[idx+3&3]][iy+ty[idx+3&3]]=='#'){
          if(idx%2)a=-a;
          else b=-b;
        }
      }else{
        int idx=(a<0)?1:0;
        int ix=x/r,iy=(y+r/2)/r;
        if(in[ix+tx[!idx]][iy+ty[!idx]]=='#')a=-a;
      }
    }else{
      if(abs(y)%r==r/2){
        int idx=(b<0)?1:0;
        int ix=(x+r/2)/r,iy=y/r;
        if(in[ix+tx[!idx*3]][iy+ty[!idx*3]]=='#')b=-b;
      }
    }
  }
  return 0;
}

int solve(){
  scanf("%d %d %d",&h,&w,&d);
  int sx=0,sy=0;
  for(int i=0;i<h;++i){
    scanf(" %s",in[i]);
    for(int j=0;j<w;++j)
      if(in[i][j]=='X')sx=i,sy=j;
  }
  int ret=0;
  for(int i=0;i<4;++i){
    int cx=sx,cy=sy;
    int le=0;
    while(1){
      cx+=dx[i];
      cy+=dy[i];
      ++le;
      if(in[cx][cy]=='#'){
        ret+=2*le-1<=d;
        break;
      }
    }
  }
  if(can(sx,sy,1,1))++ret;
  if(can(sx,sy,1,-1))++ret;
  if(can(sx,sy,-1,1))++ret;
  if(can(sx,sy,-1,-1))++ret;
  for(int a=1;a<=2*d;++a)
    for(int b=1;b<a;++b){
      //printf("%d %d %d\n",a,b,gcd(a,b));
      if(gcd(a,b)!=1)continue;
      if(can(sx,sy,a,b))++ret;
      if(can(sx,sy,a,-b))++ret;
      if(can(sx,sy,-a,b))++ret;
      if(can(sx,sy,-a,-b))++ret;
      if(can(sx,sy,b,a))++ret;
      if(can(sx,sy,-b,a))++ret;
      if(can(sx,sy,b,-a))++ret;
      if(can(sx,sy,-b,-a))++ret;
    }
  return ret;
}

int main(){
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;++i)
    printf("Case #%d: %d\n",i+1,solve());
  return 0;
}
