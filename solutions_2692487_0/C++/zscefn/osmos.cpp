#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i) {
        int vastaus;
        int oma,n; 
        cin>>oma>>n;
        vector<int> motes(n);
        for(int j=0; j<n; ++j) {
            cin>>motes[j];
        }
        sort(motes.begin(), motes.end());
        vastaus=n;
        int l=0;
        int p=n;
        for(int j=0; j<n; ++j) {
            if(motes[j]<oma) {
                --p;
                oma+=motes[j];
            }
            else if(oma>1){
                for(int k=0; motes[j]>=oma; ++k) {
                    oma+=oma-1; 
                    ++l;
                }
                oma+=motes[j];
                --p;
            }
            if(l+p<vastaus) {
                vastaus=l+p;
            }
        }
        cout<<"Case #"<<i<<": "<<vastaus<<'\n';
    }
}
