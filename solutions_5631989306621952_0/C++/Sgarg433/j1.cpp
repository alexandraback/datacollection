#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("j1.txt","r",stdin);
freopen("j1out.txt","w",stdout);
int t;
cin>>t;
for(int i=0;i<t;i++){
    string s;
    cin>>s;
    string s1="";
    s1+=s[0];
    for(int j=1;j<s.size();j++){
        if(s[j]>=s1[0]){
            s1=s[j]+s1;
        }
        else{
            s1=s1+s[j];
        }
    }
    cout<<"Case #"<<i+1<<": "<<s1<<endl;
}
}
