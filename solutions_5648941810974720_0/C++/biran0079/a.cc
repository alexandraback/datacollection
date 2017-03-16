#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
char s[2010];
int ct[26];
char* D[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char res[1000];
bool done() {
  for (int i = 0; i < 26; i++) 
    if (ct[i]) return false;
  return true;
}
bool dec(int d) {
  bool res=true;
  char* ss=D[d];
  for (int i =0;ss[i]; i++){
    if (--ct[ss[i]-'A'] < 0) {
      res = false;
    }
  }
  return res;
}
void inc(int d) {
  char* ss=D[d];
  for (int i =0;ss[i]; i++){
    ++ct[ss[i]-'A'];
  }
}
bool dfs(int d,int level) {
  if(done()) {
    return true;
  }
  for (int i=d;i<10;i++) {
    if(dec(i)) {
      res[level]=i + '0';
      if (dfs(i, level+1)) return true; 
      res[level]=0;
    }
    inc(i);
  }
  return false;
}
void solve() {
  memset(ct,0,sizeof(ct));
  for(int i=0;s[i];i++) ct[s[i]-'A']++;
  memset(res,0,sizeof(res));
  dfs(0,0);
}
int main() {
  int n;
  scanf("%d",&n);
  for(int t=0;t<n;t++) {
    scanf("%s",s);
    solve();
    printf("Case #%d: %s\n", t+1, res);
  }
  return 0;
}
