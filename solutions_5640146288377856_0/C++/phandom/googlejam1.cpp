#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){


int T,R,C,W;

cin>>T;

for(int i = 0 ; i < T; ++i){

    cin>>R>>C>>W;
    int ans = 0;
    if(C % W == 0){
        ans = C/W;
    }
    else{
        ans = C/W + 1;

    }
    ans = R * ans + W - 1;

cout<<"Case #"<<i+1<<": "<<ans<<endl;
}

return 0;
}
