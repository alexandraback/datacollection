#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int i,t,cases,can,num;
    string s;
    cin>>t;
    cases=1;
    while(cases<=t){
        cin>>s;
        bool b[s.length()];
        for(i=0;i<s.length();i++){
            b[i]=1;
            if(s[i]=='-')b[i]=0;
        }
        can=0;
        num=b[0];
        i=0;
        while(i<s.length()-1){
            if(s[i]!=s[i+1]){
                num=1-num;
                can++;
            }
            i++;
        }
        if(num==0)can++;
        cout<<"Case #"<<cases<<": "<<can<<endl;
        cases++;
    }
}
