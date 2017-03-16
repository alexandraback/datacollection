#include<iostream>
#include<vector>
using namespace std;


int f() {
    int n;
    cin>> n;
    string s;
    cin>>s;
    vector<int> v(++n);
    for(int i=0;i<n;i++) v[i] = s[i]-'0';
    
    int c=0;
    int h=0;
    for(int i=0;i<n;i++) {
        if(v[i]==0) continue;
        if(c < i) {
            h += i-c;
            c = i;
        }
        c += v[i];
    }
    return h;

}

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": "<<f()<<"\n";
        
    }
}
