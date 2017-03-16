#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int z=1; z<=t; z++){
        cout<<"Case #"<<z<<": ";
        int r,c,w;
        cin>>r>>c>>w;
        //cout<<r<<" "<<c<<" "<<w<<endl;
        int tot = 0;
        for(int i=1; i<=r-1; i++) {
            int cur = w;
            while(cur<=c) {
                cur+=w;
                tot++;
            }
        }
        int cur = w;
        while(cur<=c) {
            cur += w;
            tot++;
        }
        if(c%w!=0) tot++;
        tot+=w-1;
        cout<<tot<<endl;
    }
    return 0;
}