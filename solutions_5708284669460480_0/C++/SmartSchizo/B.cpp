#include<stdio.h>


int A[26], K, L, S;
char word[10000], lets[1000], current[1000];
double dp[1001][1001];
int dp2[1001][1001];

double go(int pos, int matched) {
  double ans = (matched == L);
  if(pos == S) return ans;
  if(dp[pos][matched] >= 0) return dp[pos][matched];
  int i,j,k;
  
  for(i=0;i<K;i++) {
    
    if(word[matched] != lets[i]) {
      for(j=0;j<matched;j++) current[j] = word[j];
      current[matched] = lets[i];
      
      for(k=1;k<=matched;k++) {
        for(j=0;k+j<=matched;j++) if(current[k+j] != word[j]) break;
        if(k+j > matched) break;
      }
      
      ans += go(pos+1,matched+1-k) * 1.0 / K;
    } else {
      ans += go(pos+1,matched+1) * 1.0 / K;
    }
  }
  dp[pos][matched] = ans;
  return ans;
}

int go2(int pos, int matched) {
  int ans = (matched == L);
  
  if(pos == S) return ans;
  if(dp2[pos][matched] >= 0) return dp2[pos][matched];
  int i,j,k,a,best = 0;
  
  for(i=0;i<K;i++) {
    if(word[matched] != lets[i]) {
      for(j=0;j<matched;j++) current[j] = word[j];
      current[matched] = lets[i];
      
      for(k=1;k<=matched;k++) {
        for(j=0;k+j<=matched;j++) if(current[k+j] != word[j]) break;
        if(k+j > matched) break;
      }
      
      a = go2(pos+1,matched+1-k);
      if(a > best) best = a;
    } else {
      a = go2(pos+1,matched+1);
      if(a > best) best = a;
    }
  }
  ans += best;
  dp2[pos][matched] = ans;
  return ans;
}

void solve(int t) {
  int i, j;
  scanf("%d %d %d",&K,&L,&S);
  for(i=0;i<26;i++) A[i] = 0;
  scanf("%s %s",lets,word);
  
  for(i=0;i<=S;i++) for(j=0;j<=L;j++) {
    dp[i][j] = -1;
    dp2[i][j] = -1;
  }
  
  printf("Case #%d: %.9lf\n",t,go2(0,0) - go(0,0));
}

int main() {
  int t,T;
  //freopen("/Users/sushi/Downloads/C-small-attempt1.in","r",stdin);
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
