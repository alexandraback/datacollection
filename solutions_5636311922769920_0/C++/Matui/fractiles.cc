#include <iostream>

using namespace std;
int T,K,C,S;
void solve(int);
int main(){
    cin>>T;
    for(int i=1;i<=T;++i){
        cin>>K>>C>>S;
        solve(i);
    }
    return 0;
}
void solve(int i){
    cout<<"Case #"<<i<<": ";
    for(int j=1;j<=S;++j)
        cout<<j<<' ';
    cout<<endl;
}
