#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
char s[123];
int main(){
   freopen("bl.in","r",stdin);
   freopen("bl2.out","w",stdout);
   int t;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      scanf("%s",s);
      int n=strlen(s);
      int ans=1;
      for(int i=1;i<n;i++)if(s[i]!=s[i-1])ans++;
      if(s[n-1]=='+')ans--;
      printf("Case #%d: %d\n",tt,ans);
   }
   return 0;
}

