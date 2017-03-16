#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, S;
    char p[2000];
    cin>>T;
    for(int tt=1; tt<=T; tt++){
        cin>>S>>p;
        int ans=0, va=0;
        for(int i=0; i<=S; i++)
            ans=max(ans,i-va), va+=p[i]-'0';
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
