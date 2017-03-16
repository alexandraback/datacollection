#include <iostream>

using namespace std;

int main()
{
    int T, Tcnt=1;
    cin>>T;
    for(; T; T--,Tcnt++) {
        int R, C, W;
        cin>>R>>C>>W;
        int ans = C/W + W - (C%W==0);
        if(R>1) {
            ans += (R-1)*(C/W);
        }
        cout<<"Case #"<<Tcnt<<": "<<ans<<endl;
    }
    return 0;
}

