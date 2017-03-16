#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;

int main() {
    int t,o=1;
    cin>>t;
    while(t--)
    {
        int r,c,w,ans;
        cin>>r>>c>>w;
        if(c%w==0)
            ans=(c/w)+(w-1);
        else 
            ans=(c/w)+w;
        cout<<"Case #"<<o<<": "<<ans<<endl;
        
o++;
    }
    
return 0;         
}
