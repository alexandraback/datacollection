#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int T;
    cin>>T;

    for(int tc=1; tc<=T; ++tc){
        int n; 
        cin>>n;

        vector<int> bf(n);
        for(int i=0;i<n;++i){ cin>>bf[i]; --bf[i]; }

        vector<int> v(n);
        for(int i=0;i<n;++i) v[i]=i;
        
        int mx=0;

        do{
            //verify:
            int cmx=1;
            for(int i=1; i<=n; ++i){
                bool good=true;
                for(int j=0;j<i;++j){
                    if(bf[v[j]]!=v[(i+j-1)%i] && bf[v[j]]!=v[(j+1)%i])
                        good=false;
                }
                if(good) cmx=i;
            }
            if(cmx>mx) mx=cmx;
        }
        while(next_permutation(v.begin(),v.end()));

        cout<<"Case #"<<tc<<": "<<mx<<'\n';

    }
}
