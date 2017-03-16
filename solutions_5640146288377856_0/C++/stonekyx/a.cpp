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
        cout<<"Case #"<<Tcnt<<": "<<ans<<endl;
    }
    return 0;
}

