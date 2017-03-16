#include <cstdio>

int a[1010];
int b[1010];
int c[1010];
int main(){
  freopen("B-large.in","r",stdin);
  freopen("B-large.out","w",stdout);
  int tc;
  scanf("%d", &tc);
  for(int ti = 1; ti <= tc; ti++){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d%d", &a[i], &b[i]);
      c[i] = 0;
    }
    int collect = 0;
    int turn = 0;
    int n2 = n+n;
    while(collect < n2){
      int d = -1;
      for(int i = 0; i < n; i++)
	if(c[i] < 2 && collect >= b[i])
	  d = i;
      if(d >= 0){
	collect += 2-c[d];
	c[d] = 2;
	turn++;
	continue;
      }
      int e = -1;
      for(int i = 0; i < n; i++)
	if(c[i] < 1 && collect >= a[i] && (d<0 || (b[i]>e))){
	  e = b[i];
	  d = i;
	}
      if(d >= 0){
	collect += 1-c[d];
	c[d] = 1;
	turn++;
	continue;
      }
      break;
    }
    if(collect == n2){
      printf("Case #%d: %d\n", ti, turn);
    }else{
      printf("Case #%d: Too Bad\n", ti);
    }
  }
}
