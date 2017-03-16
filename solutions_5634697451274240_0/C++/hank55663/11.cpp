#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
      char c[100];
      scanf("%s",c);
      int length=strlen(c);
      c[length]='+';
      int ans=0;
      for(int i=1;i<=length;i++)
        if(c[i]!=c[i-1])
            ans++;
      printf("Case #%d: %d\n",T,ans);
    }
}
