#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
char s1[100], s2[100];
int C,J;
int abs(int a){return a>0?a:-a;}
void dfs(int i, int tc, int tj) {
  if(!s1[i]){
    if (abs(C-J)>abs(tc-tj)) {
      C=tc;
      J=tj;
    } else if (abs(C-J)==abs(tc-tj) && tc < C) {
      C=tc;
      J=tj;
    } else if (abs(C-J)==abs(tc-tj) && tc == C && tc < J) {
      C=tc;
      J=tj;
    }
    return;
  }
  if (s1[i] == '?' && s2[i] == '?') {
    for (int j=0;j<10;j++) {
      for(int k=0;k<10;k++) {
        dfs(i+1,tc*10+j,tj*10+k);
      }
    }
  } else if (s1[i] == '?') {
    for (int j=0;j<10;j++)
        dfs(i+1,tc*10+j,tj*10+(s2[i]-'0'));
  } else if(s2[i]=='?') {
    for (int j=0;j<10;j++)
        dfs(i+1,tc*10+s1[i]-'0',tj*10+j);
  } else {
    dfs(i+1,tc*10+s1[i]-'0',tj*10+s2[i]-'0');
  }
}
void solve() {
  C=10000;
  J = 0;
  dfs(0, 0, 0);
}
int main() {
  int n;
  scanf("%d",&n);
  for(int t=0;t<n;t++) {
    scanf("%s%s",s1,s2);
    solve();
    int len = strlen(s1);
    for(int i=len-1;i>=0;i--) {
      s1[i]=C%10+'0';
      C/=10;
      s2[i]=J%10+'0';
      J/=10;
    }
    printf("Case #%d: %s %s\n", t+1, s1, s2);
  }
  return 0;
}
