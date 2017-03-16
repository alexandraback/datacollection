#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string solve(string s){
    int n = s.size();
    string sol = "";
    string c = " ";
    for(int i=0;i<n;++i){
        c[0] = s[i];
        string a = sol + c;
        string b = c + sol;
        if(a>b){
            sol = a;
        }else{
            sol = b;
        }
    }
    return sol;
}

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;++t){
        string s;
        cin>>s;
        string sol = solve(s);
        cout<<"Case #"<<t<<": "<<sol<<endl;
    }
    return 0;
}

