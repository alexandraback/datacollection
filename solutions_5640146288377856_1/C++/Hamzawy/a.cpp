#include<iostream>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;++t){
        int w,r,c;
        cin>>r>>c>>w;
        cout<<"Case #"<<t<<": "<<(r-1)*(c/w)+((c/w)+(w-1)+(c%w!=0))<<"\n";
    }
    return 0;
}
