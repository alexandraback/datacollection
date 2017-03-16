#include <bits/stdc++.h>
using namespace std;
int test;

int a[10000];
int b[10000];


void sol(){
    int n;
    cin>>n;
    string s;
    map <string,int> Ma,Mb;
    for (int i=0;i<n;i++){
        cin>>s;
        if (Ma.find(s)==Ma.end()) Ma[s]=Ma.size();
        a[i]=Ma[s];
        cin>>s;
        if (Mb.find(s)==Mb.end()) Mb[s]=Mb.size();
        b[i]=Mb[s];
    }
    int ans=0;

    for (int B=0;B<(1<<n);B++){
        int x=0,y=0,z=0,d=0;
        for (int i=0;i<n;i++)
        if (B&(1<<i)){
            x|=(1<<a[i]);
            z|=(1<<b[i]);
        } else {
            y|=(1<<a[i]);
            d|=(1<<b[i]);
        }

        if ((y&x)==x && (y|x)==y)
        if ((d&z)==z && (d|z)==d)
            ans=max(ans,__builtin_popcount(B));
    }

    test++;
    cout<<"Case #"<<test<<": "<<ans<<endl;
}

int main() {
    freopen("C.in","r",stdin);
    freopen("C.txt","w",stdout);
    int t;
    cin>>t;
    while (t--){
        sol();
    }
    return 0;
}
