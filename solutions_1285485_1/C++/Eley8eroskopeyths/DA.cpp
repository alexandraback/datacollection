#include<iostream>
#include<cmath>

using namespace std;

struct vec {
  int x;
  int y;
} startx, startv, currx, currv;

int times(vec v,vec u) {
  return v.x*u.y-v.y*u.x;
}

int gcd(int n, int m) {
  if(n<0) n=-n;
  if(m<0) m=-m;
  if(n==0) return m;
  else return gcd(m%n,n);
}

int abs(int n) {
  if(n<0) return -n;
  else return n;
}

int main() {
  int T,H,W,D,ret;
  cin>>T;
  vec e;

  for(int v=1;v<=T;v++) {
    cin>>H;
    cin>>W;
    cin>>D;
    char A[H][W];

    for(int i=0;i<H;i++) {
      for(int j=0;j<W;j++) {
        cin>>A[i][j];
        if(A[i][j]=='X') {
          startx.x=j;
          startx.y=i;
        }
      }
    }
    ret=0;
    for(int a=-D;a<=D;a++) {
      for(int b=-D;b<=D;b++) {
        if(gcd(a,b)==1&&a*a+b*b<=D*D) {
          startv.x=a;
          startv.y=b;
          currv=startv;
          currx=startx;

          if(currv.x>=0) e.x=1;
          else e.x=-1;
          if(currv.y>=0) e.y=1;
          else e.y=-1;

          bool err=false;

          int loop=1;
//dbg          cout<<"("<<currx.x<<" "<<currx.y<<")["<<currv.x<<" "<<currv.y<<"]";
          while(!err&&loop*loop*(a*a+b*b)<=D*D) {
            for(int k=1;k<=abs(a)+abs(b);k++) {
//1
              if(e.x>0&&e.y>0) {
                if(times(e,currv)>0) {
                  if(A[currx.y+1][currx.x]!='#') {
                    currx.y=currx.y+1;
                    e.y=e.y+2;
                  }
                  else {
                    currv.y=-currv.y;
                    e.y=-e.y-2;
                  }
                }
                else if(times(e,currv)<0) {
                  if(A[currx.y][currx.x+1]!='#') {
                    currx.x=currx.x+1;
                    e.x=e.x+2;
                  }
                  else {
                    currv.x=-currv.x;
                    e.x=-e.x-2;
                  }
                }
                else if(times(e,currv)==0) {
                  k++;
                  if(A[currx.y+1][currx.x+1]!='#') {
                    currx.x=currx.x+1;
                    currx.y=currx.y+1;
                    e.x=e.x+2;
                    e.y=e.y+2;
                  }
                  else {
                    if(A[currx.y][currx.x+1]!='#'&&A[currx.y+1][currx.x]!='#') {
                      err=true;
                      k=abs(a)+abs(b);
                    }
                    else if(A[currx.y][currx.x+1]=='#'&&A[currx.y+1][currx.x]!='#') {
                      currv.x=-currv.x;
                      e.x=-e.x-2;
                      e.y=e.y+2;
                      currx.y=currx.y+1;
                    }
                    else if(A[currx.y+1][currx.x]=='#'&&A[currx.y][currx.x+1]!='#') {
                      currv.y=-currv.y;
                      e.y=-e.y-2;
                      e.x=e.x+2;
                      currx.x=currx.x+1;
                    }
                    else {
                      currv.x=-currv.x;
                      currv.y=-currv.y;
                      e.x=-e.x-2;
                      e.y=-e.y-2;
                    }
                  }
                }
              }
//2
              else if(e.x>0&&e.y<0) {
                if(times(e,currv)>0) {
                  if(A[currx.y][currx.x+1]!='#') {
                    currx.x=currx.x+1;
                    e.x=e.x+2;
                  }
                  else {
                    currv.x=-currv.x;
                    e.x=-e.x-2;
                  }
                }
                else if(times(e,currv)<0) {
                  if(A[currx.y-1][currx.x]!='#') {
                    currx.y=currx.y-1;
                    e.y=e.y-2;
                  }
                  else {
                    currv.y=-currv.y;
                    e.y=-e.y+2;
                  }
                }
                else if(times(e,currv)==0) {
                  k++;
                  if(A[currx.y-1][currx.x+1]!='#') {
                    currx.x=currx.x+1;
                    currx.y=currx.y-1;
                    e.x=e.x+2;
                    e.y=e.y-2;
                  }
                  else {
                    if(A[currx.y][currx.x+1]!='#'&&A[currx.y-1][currx.x]!='#') {
                      err=true;
                      k=abs(a)+abs(b);
                    }
                    else if(A[currx.y][currx.x+1]=='#'&&A[currx.y-1][currx.x]!='#') {
                      currv.x=-currv.x;
                      e.x=-e.x-2;
                      e.y=e.y-2;
                      currx.y=currx.y-1;
                    }
                    else if(A[currx.y-1][currx.x]=='#'&&A[currx.y][currx.x+1]!='#') {
                      currv.y=-currv.y;
                      e.x=e.x+2;
                      e.y=-e.y+2;
                      currx.x=currx.x+1;
                    }
                    else {
                      currv.x=-currv.x;
                      currv.y=-currv.y;
                      e.x=-e.x-2;
                      e.y=-e.y+2;
                    }
                  }
                }
              }
//3
              else if(e.x<0&&e.y>0) {
                if(times(e,currv)>0) {
                  if(A[currx.y][currx.x-1]!='#') {
                    currx.x=currx.x-1;
                    e.x=e.x-2;
                  }
                  else {
                    currv.x=-currv.x;
                    e.x=-e.x+2;
                  }
                }
                else if(times(e,currv)<0) {
                  if(A[currx.y+1][currx.x]!='#') {
                    currx.y=currx.y+1;
                    e.y=e.y+2;
                  }
                  else {
                    currv.y=-currv.y;
                    e.y=-e.y-2;
                  }
                }
                else if(times(e,currv)==0) {
                  k++;
                  if(A[currx.y+1][currx.x-1]!='#') {
                    currx.x=currx.x-1;
                    currx.y=currx.y+1;
                    e.x=e.x-2;
                    e.y=e.y+2;
                  }
                  else {
                    if(A[currx.y][currx.x-1]!='#'&&A[currx.y+1][currx.x]!='#') {
                      err=true;
                      k=abs(a)+abs(b);
                    }
                    else if(A[currx.y][currx.x-1]=='#'&&A[currx.y+1][currx.x]!='#') {
                      currv.x=-currv.x;
                      e.x=-e.x+2;
                      e.y=e.y+2;
                      currx.y=currx.y+1;
                    }
                    else if(A[currx.y+1][currx.x]=='#'&&A[currx.y][currx.x-1]!='#') {
                      currv.y=-currv.y;
                      e.x=e.x-2;
                      e.y=-e.y-2;
                      currx.x=currx.x-1;
                    }
                    else {
                      currv.x=-currv.x;
                      currv.y=-currv.y;
                      e.x=-e.x+2;
                      e.y=-e.y-2;
                    }
                  }
                }
              }
//4
              else if(e.x<0&&e.y<0) {
                if(times(e,currv)>0) {
                  if(A[currx.y-1][currx.x]!='#') {
                    currx.y=currx.y-1;
                    e.y=e.y-2;
                  }
                  else {
                    currv.y=-currv.y;
                    e.y=-e.y+2;
                  }
                }
                else if(times(e,currv)<0) {
                  if(A[currx.y][currx.x-1]!='#') {
                    currx.x=currx.x-1;
                    e.x=e.x-2;
                  }
                  else {
                    currv.x=-currv.x;
                    e.x=-e.x+2;
                  }
                }
                else if(times(e,currv)==0) {
                  k++;
                  if(A[currx.y-1][currx.x-1]!='#') {
                    currx.x=currx.x-1;
                    currx.y=currx.y-1;
                    e.x=e.x-2;
                    e.y=e.y-2;
                  }
                  else {
                    if(A[currx.y][currx.x-1]!='#'&&A[currx.y-1][currx.x]!='#') {
                      err=true;
                      k=abs(a)+abs(b);
                    }
                    else if(A[currx.y][currx.x-1]=='#'&&A[currx.y-1][currx.x]!='#') {
                      currv.x=-currv.x;
                      e.x=-e.x+2;
                      e.y=e.y-2;
                      currx.y=currx.y-1;
                    }
                    else if(A[currx.y-1][currx.x]=='#'&&A[currx.y][currx.x-1]!='#') {
                      currv.y=-currv.y;
                      e.x=e.x-2;
                      e.y=-e.y+2;
                      currx.x=currx.x-1;
                    }
                    else {
                      currv.x=-currv.x;
                      currv.y=-currv.y;
                      e.x=-e.x+2;
                      e.y=-e.y+2;
                    }
                  }
                }
              }
//dbg              cout<<k<<"("<<currx.x<<" "<<currx.y<<")["<<currv.x<<" "<<currv.y<<"]";
            }

            if(!err&&currx.x==startx.x&&currx.y==startx.y) {
              ret++;
//dbg              cout<<"*";
              err=true;
            }
            else {
              loop++;
            }
          }
//dbg          cout<<endl;
        }
      }
    }

    cout<<"Case #"<<v<<": "<<ret<<endl;
  }

  return 0;
}




