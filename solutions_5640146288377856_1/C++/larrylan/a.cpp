#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, R, C, W;
    cin>>T;
    for(int tt=1; tt<=T; tt++){
        cin>>R>>C>>W;
        int ans=(C-1)/W+W+(R-1)*(C/W);
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
