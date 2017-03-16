#include <iostream>
using namespace std;

int main(){
    int T,R,C,W,counter = 1;
    cin>>T;
    while(T--){
        cin>>R>>C>>W;
        int ans = (R-1)*(C/W)+(C/W-1)+W;
        ans+= (C%W!=0)?1:0;
        cout<<"Case #"<<counter++<<": "<<ans<<endl;
    }
    return 0;
}
