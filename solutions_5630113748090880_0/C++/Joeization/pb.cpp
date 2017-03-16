#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,a,b;
int cnt[2555];
int main(){
    cin>>t;
    string s;
    for(int ti=1;ti<=t;ti++){
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n*2-1;i++){
            for(int j=0;j<n;j++){
                cin>>k;
                cnt[k]++;
            }
        }
        bool is=false;
        cout<<"Case #"<<ti<<": ";
        for(int i=0;i<2555;i++){
            if(cnt[i]%2==1){
                if(is)cout<<" ";
                is=true;
                cout<<i;
            }
        }
        cout<<endl;
    }
}