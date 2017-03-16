#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,tk=1;
    scanf("%d",&t);
    while(t--){
        int n;
        char s[1200];
        scanf("%d",&n);
        scanf("%s",s);
        int np=0,ans=0;
        for(int i=0;i<=n;i++){
            int x=s[i]-'0';
            if(x>0 && np<i){
                ans+=i-np;
                np=i;
            }
            np+=x;
        }
        printf("Case #%d: %d\n",tk++,ans);
    }
}
            
