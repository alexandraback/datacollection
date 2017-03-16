#include<stdio.h>
#include<algorithm>

int max_cover[2][1001][4001]; //width, stones

void solve(int t) {
  int i,j,n,m,r=0,k,w,jj;
  scanf("%d %d %d",&n,&m,&w);

  for(j=0;j<=m;j++) {
    for(k=1;k<=(m+n)*2;k++) {
      max_cover[0][j][k] = 0;
      max_cover[1][j][k] = 0;
    }
  }

  for(j=0;j<=m;j++) max_cover[r][j][j] = j;
  for(i=2;i<n;i++) {
    r = 1-r;
    for(j=0;j<=m;j++) {
      int t = (j>1)+(j>0);
      for(k=1;k+t<=(m+n)*2;k++) {
        for(jj=std::max(j-2,0);jj<=j+2&&jj<=m;jj++) {
          max_cover[r][j][k+t] = std::max( max_cover[r][j][k+t], max_cover[1-r][jj][k] + j );
        }
      }
    }
  }
  int ans = 2*(n+m);
  for(j=0;j<=m;j++) {
    for(k=1;k<ans;k++) {
      if(max_cover[r][j][k]>=w) {
        int kk = k + std::max(j-2,0);
        if(kk < ans) ans = kk;
      } else if(max_cover[r][j][k]>=w-m) {
        int kk = k + std::max(w-max_cover[r][j][k],j-2);
        if(kk < ans) ans = kk;
      }
    }
  }
  printf("Case #%d: %d\n",t,ans);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
