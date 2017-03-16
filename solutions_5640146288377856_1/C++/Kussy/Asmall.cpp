#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    for(int tt = 1; tt<=T; tt++) {
        int o;
        int r, c, w;
        cin>>r>>c>>w;

        if(c%w == 0)
        o = r *(c/w) + w - 1;
        else
        o = r * (c/w) + w;

        cout<<"Case #"<<tt<<": "<<o<<endl;
    }
    return 0;
}
