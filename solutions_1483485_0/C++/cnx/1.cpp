#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const char t[]="yhesocvxduiglbkrztnwjpfmaq";

int main(){
    freopen("1.txt","r",stdin);
    freopen("1.ans","w",stdout);
    int _;
    string s;
    cin>>_;getline(cin,s);
    for(int __=1;__<=_;++__){
        getline(cin,s);
        cout<<"Case #"<<__<<": ";
        for(int i=0;i<s.size();++i)
            if(s[i]==' ')cout<<' ';
            else cout<<t[s[i]-'a'];
        cout<<'\n';
    }
    return 0;
}

