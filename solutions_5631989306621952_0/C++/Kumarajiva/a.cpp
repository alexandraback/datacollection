#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

int i,j,n,ca,cas;
char s[1010];
string ans;

int main(){

  freopen("A_s.in","r",stdin);
  freopen("A_s.out","w",stdout);
  scanf("%d",&cas);
  for (ca=1;ca<=cas;ca++){
    scanf("%s",s+1);
    ans.clear();
    n=strlen(s+1);
    for (i=1;i<=n;i++)
      if (s[i]>=ans[0]) ans=s[i]+ans;
      else ans=ans+s[i];
    printf("Case #%d: ",ca);
    cout<<ans<<endl;
  }
  return 0;



}
