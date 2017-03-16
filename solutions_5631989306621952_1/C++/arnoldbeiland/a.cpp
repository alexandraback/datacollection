#include <iostream>
#include <string>
using namespace std;


int main(){
    int T;
    cin>>T;

    for(int tc=1; tc<=T; ++tc){
        string s;
        cin>>s;

        string ss="";
        ss+=s[0];

        for(unsigned i=1;i<s.size();++i){
            if(s[i]>=ss[0]) ss=s[i]+ss;
            else ss=ss+s[i];
        } 
        
        cout<<"Case #"<<tc<<": "<<ss<<'\n';
    }
}
