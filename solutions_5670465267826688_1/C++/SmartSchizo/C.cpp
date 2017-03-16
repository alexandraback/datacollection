#include<stdio.h>

char s[1000000];
int A[1000000];
int Q[8][8] = {
  {0,1+0,2,1+2,4,1+4,6,7},
  {1+0,0,1+2,2,1+4,4,1+6,6},
  {2,1+2,1+0,0,6,1+6,1+4,4},
  {1+2,2,0,1+0,1+6,6,4,1+4},
  {4,1+4,1+6,6,1+0,0,2,1+2},
  {1+4,4,6,1+6,0,1+0,1+2,2},
  {6,1+6,4,1+4,1+2,2,1+0,0},
  {1+6,6,1+4,4,2,1+2,0,1+0}
};

void solve(int t) {
  int i, r, N, X;
  scanf("%d %d %s",&N,&X,s);
  for(i=0;i<N;i++) A[i] = (s[i]-'i'+1)*2;
  
  int num = 0, state = 0, ok = 0;
  for(r=1; r<=8 && r<=X; r++) {
    for(i=0;i<N;i++) {
      num = Q[num][A[i]];
      //printf("%d %d\n",num,state);
      if(num == 2 && state == 0) state = 1;
      if(num == 6 && state == 1) state = 2;
    }
    if(X%4 == r && num == 1) ok = 1;
  }
  
  if(state == 2 && ok) printf("Case #%d: YES\n",t);
  else printf("Case #%d: NO\n",t);
}

int main() {
  int t,T;
  //freopen("/Users/sushi/Downloads/C-small-attempt1.in","r",stdin);
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
