#include <bits/stdc++.h>
using namespace std;
const string z[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int t,tt,ii,i,j,k,kj,cnt,a[26],u[10],r[10];
char s[2020];
bool w,q;
int main() {
  freopen("As.in","r",stdin);
  freopen("As.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%s",s);
    for (i=0; i<26; i++) a[i]=0;
    for (i=0; i<10; i++) r[i]=0;
    for (i=0; s[i]; i++) a[s[i]-'A']++;
    for (ii=0; ii<10; ii++) {
      w=true;
      for (i=0; i<10 && w; i++) if (u[i]!=t) for (j=0; j<z[i].length() && w; j++) {
        q=true;
        for (k=0; k<10 && q; k++) if (u[k]!=t && i!=k) for (kj=0; kj<z[k].length() && q; kj++)
          if (z[i][j]==z[k][kj]) q=false;
        if (q) {
          w=false;
          u[i]=t;
          for (cnt=k=0; k<z[i].length(); k++) if (z[i][j]==z[i][k]) cnt++;
          cnt=a[z[i][j]-'A']/cnt;
          r[i]+=cnt;
          for (k=0; k<z[i].length(); k++) a[z[i][k]-'A']-=cnt;
          break;
        }
      }
    }
    printf("Case #%d: ",t);
    for (i=0; i<10; i++) for (j=0; j<r[i]; j++) printf("%d",i);
    puts("");
    fprintf(stderr,"Case #%d\n",t);
  }
  return 0;
}
