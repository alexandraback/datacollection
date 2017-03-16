#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, r, c, w;
    ifstream cin("large.in");
    ofstream cout("lar.txt");
    cin>>t;
    for(int tt=1;tt<=t;tt++){
          cin >> r >> c >> w;
          int wid = ceil(c/(w*1.0));
          int ans =  r*wid + w - 1;
          cout<<"Case #"<<tt<<": "<<ans<<endl;


    }
    return 0;
}
