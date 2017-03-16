#include<iostream>
#include<queue>
using namespace std;

int f() {
    int n;
    cin>>n;
    vector<int> v(1004,0);

    int best=0;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        v[a]++;
        if(a>best) best=a;
    }
    for(int i=1000;i>=0;i--) v[i]+=v[i+1];


    for(int i=best;i>=1;i--) {
        int cuts = 0;
        for(int j=1;j*i<=1000;j++) {
            if(v[i*j+1]>0)
            cuts += v[i*j+1];
        }
        if(cuts + i < best) best = cuts + i;
    }
    return best;
    
}

int main() {

    int t;
    cin>>t;
    for(int i=1;i<=t;i++) cout<<"Case #"<<i<<": "<<f()<<endl;
}

