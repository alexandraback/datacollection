#include <bits/stdc++.h>
using namespace std;
int tc,tt,n,x,i,j;
string s,t,cs,ct,rs,rt;
char st[22],cx,cy;
long long a,b,r;
void upd(long long cr, const string& cs, const string& ct) {
  if (cr!=r) {
    if (cr<r) { r=cr; rs=cs; rt=ct; }
    return;
  }
  if (cs!=rs) {
    if (cs<rs) { rs=cs; rt=ct; }
    return;
  }
  if (ct<rt) rt=ct;
}
int main() {
  freopen("Bs.in","r",stdin);
  freopen("Bs.out","w",stdout);
  scanf("%d",&tt);
  for (tc=1; tc<=tt; tc++) {
    scanf("%s",st); s=st;
    scanf("%s",st); t=st;
    n=s.length();
    r=2000000000; r*=r;
    for (x=0; x<n; x++) if (s[x]!=t[x] && s[x]!='?' && t[x]!='?') break;
    for (i=0; i<=x; i++) {
      if (i==n) {
        upd(0,s,t);
        break;
      }
      for (cx='0'; cx<='9'; cx++) if (s[i]==cx || s[i]=='?')
        for (cy='0'; cy<='9'; cy++) if (cx!=cy && (t[i]==cy || t[i]=='?')) {
          cs=s; cs[i]=cx; a=cx-'0';
          ct=t; ct[i]=cy; b=cy-'0';
          for (j=i+1; j<n; j++) {
            if (cs[j]=='?') {
              if (cx<cy) cs[j]='9'; else cs[j]='0';
            }
            if (ct[j]=='?') {
              if (cx<cy) ct[j]='0'; else ct[j]='9';
            }
            a=a*10+cs[j]-'0';
            b=b*10+ct[j]-'0';
          }
          upd(abs(a-b),cs,ct);
        }
      if (s[i]=='?') {
        if (t[i]=='?') s[i]=t[i]='0'; else s[i]=t[i];
      } else if (t[i]=='?') t[i]=s[i];
    }
    printf("Case #%d: %s %s\n",tc,rs.c_str(),rt.c_str());
  }
  return 0;
}
