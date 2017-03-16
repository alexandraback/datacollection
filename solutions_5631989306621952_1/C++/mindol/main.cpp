#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc;
    cin>>tc;
    for(int mindol=1;mindol<=tc;mindol++) {
        string s,now;
        cin>>s;
        for(int i=0;i<s.size();i++) {
            string a = now + s[i];
            string b = s[i] + now;
            if(a.compare(b) > 0) now = a;
            else now = b;
        }
        cout<<"Case #"<<mindol<<": "<<now<<endl;
    }
    return 0;
}
