#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int countManeuver(const string& state){
    char lastType = '+';
    int counter = 0;
    for(int i=state.length()-1;i>=0;i--){
        if(state[i]!=lastType){
            counter++;
            lastType = state[i];
        }
    }
    return counter;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        string get;
        cin>>get;
        printf("Case #%d: %d\n",i+1,countManeuver(get));
    }
    return 0;
}
