#include <vector>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int sol(int c, int w){
    if(c%w==0){
        return c/w+w-1;
    }
    else
        return c/w+w;
}

int main(){
    int t,r,c,w;
    int sum;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>r>>c>>w;
        sum=0;
        for(int j=0;j<r;j++){
            sum+=sol(c,w);
        }
        cout<<"Case #"<<i<<": "<<sum<<endl;
    }
    return 0;
}
