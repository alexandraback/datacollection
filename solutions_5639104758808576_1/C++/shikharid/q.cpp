#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,l;
    string s;
    int ans=0,stn=0;
    cin.sync_with_stdio(false);
   //ifstream cin("A-large.in");
    //ofstream cout("out.txt");
    cin>>t;
    for(int tt=1;tt<=t;tt++){

        cin>>l>>s;
        ans=stn=0;
        for(int i=0;i<=l;i++){
            if(s[i]!='0'){

                if(ans>=i){
                    ans+=(s[i]-'0');
                }
                else{
                    stn+=(i-ans);
                    ans+=(i-ans);
                    ans+=(s[i]-'0');
                }
            }
        }
        cout<<"Case #"<<tt<<": "<<stn<<endl;

    }
    return 0;
}
