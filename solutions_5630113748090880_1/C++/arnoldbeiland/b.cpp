#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int T;
    cin>>T;

    for(int tc=1; tc<=T; ++tc){
        int n; cin>>n;
        
        int nr=n*(2*n-1);
        vector<int> v(nr);

        for(int i=0;i<nr;++i) cin>>v[i];
        sort(v.begin(),v.end());
       
        
        cout<<"Case #"<<tc<<": ";
        int out=0;
        int i=0;

        while(out<n){
            if(i==nr-1 || v[i]!=v[i+1]){ 
                cout<<v[i];
                ++out;
                if(out<n) cout<<' ';
                ++i;
            }
            else i+=2;
        }
        cout<<'\n';
    }
}
