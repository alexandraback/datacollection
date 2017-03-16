#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("f4.txt","r",stdin);
    freopen("o4.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int k,c,s;
        cin>>k>>c>>s;
        cout<<"Case #"<<t<<": ";
        for(int i=1;i<=s;i++) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
}
