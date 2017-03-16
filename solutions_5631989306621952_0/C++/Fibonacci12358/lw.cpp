#include <iostream>
#include <string>

using namespace std;

int t;

int main(){
    cin>>t;
    for(int x=0;x<t;x++){
        cout<<"Case #"<<x+1<<": ";
        string s;
        string f="";
        cin>>s;
        f.push_back(s[0]);
        for(int i=1;i<s.length();i++){
            if(s[i]>=f[0]){
                f.insert(0,1,s[i]);
            }
            else{
                f.push_back(s[i]);
            }
        }
        cout<<f<<endl;
    }
    return 0;
}
