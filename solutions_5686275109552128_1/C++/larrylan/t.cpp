#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, D, P[1000];
    cin>>T;
    for(int tt=1; tt<=T; tt++){
        cin>>D;
        for(int i=0; i<D; i++)
            cin>>P[i];
        int ans = 1000;
        for(int i=1; i<=1000; i++){
            int s=i;
            for(int j=0; j<D; j++)
                s += (P[j]-1)/i;
            ans = min(ans,s);
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
