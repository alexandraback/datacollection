#include<stdio.h>

char cars[100][200];
int lets[26], clets[26], frees[26], edges[100][2], flags[26];
long long fac[150];

void solve(int t) {
  int i,j,n,l,k=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%s",cars[i]);
  for(j=0;j<26;j++) lets[j] = 0;
  for(j=0;j<26;j++) frees[j] = 0;
  for(j=0;j<26;j++) flags[j] = 0;

  for(i=0;i<n;i++) {
    for(j=0;cars[i][j];j++) {
      lets[ cars[i][j] - 'a' ]++;
    }
  }

  for(i=0;i<n;i++) {
    for(j=0;j<26;j++) clets[j] = 0;
    for(j=0;cars[i][j];j++) {
      if( clets[ cars[i][j] - 'a' ] > 0 && cars[i][j-1] != cars[i][j] ) {
        //invalid car
        printf("Case #%d: 0\n",t);
        return;
      }
      clets[ cars[i][j] - 'a' ]++;
      l = j;
    }
    for(j=0;j<26;j++) if( clets[j] > 0 && lets[j]  > clets[j] && j != cars[i][0]-'a' && j != cars[i][l]-'a' ) {
      //trapped letter
      printf("Case #%d: 0\n",t);
      return;
    }
    if(cars[i][0] == cars[i][l]) {
      frees[ cars[i][0]-'a' ]++;
    } else {
      edges[k][0] = cars[i][0]-'a';
      edges[k][1] = cars[i][l]-'a';
      k++;
    }
  }
  for(i=0;i<k;i++) {
    int a = edges[i][0],b = edges[i][1];
    if( flags[a] & 1 ) {
      //cars start with the same letter
      printf("Case #%d: 0\n",t);
      return;
    }
    flags[a] |= 1;
    if( flags[b] & 2 ) {
      //cars end with the same letter
      printf("Case #%d: 0\n",t);
      return;
    }
    flags[b] |= 2;
  }
  long long total = 1, MOD = 1000000007;
  int parts = 0;
  for(i=0;i<26;i++) if(flags[i] == 1) parts++;
  if( k > 0 && !parts ) {
    //circular
    printf("Case #%d: 0\n",t);
    return;
  }
  
  fac[0] = 1;
  for(i=1;i<150;i++) fac[i] = fac[i-1]*i % MOD;
  
  for(i=0;i<26;i++) {
    total = (total * fac[ frees[i] ]) % MOD;
    if( frees[i] > 0 && flags[i] == 0 ) parts++;
  }
  total = (total * fac[ parts ]) % MOD;

  printf("Case #%d: %lld\n",t, total);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
