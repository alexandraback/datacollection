#include<iostream>
#include<string>
using namespace std;
int T;
void solve(int,string);
int main(){
    cin>>T;
    for(int i=1;i<=T;++i){
        string a;
        cin>>a;
        solve(i,a);
    }
    return 0;
}

void solve(int i,string a){
    char s = '+';
    int c=0;
    for(int j=a.size()-1;j>=0;--j){
        if(a[j]==s) continue;
        c++;
        s=a[j];
    }
    cout<<"Case #"<<i<<": "<<c<<endl;
}
