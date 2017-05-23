#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<cstdio>

using namespace std;

int main(){

    freopen("gcj_round1A_input_prbA.txt","r",stdin);
    freopen("gcj_round1A_output_prbA.txt","w",stdout);

    int t,r;
    cin>>t;
    for(r=1;r<=t;r++){
        string s,ans="";
        cin>>s;
        long long len,i,x;
        len=s.length();
        ans+=s[0];
        for(i=1;i<len;i++){
            x=ans.length();
            if(s[i]>=ans[0])ans.insert(0,1,s[i]);
            else ans.insert(x,1,s[i]);
        }

        cout<<"Case #"<<r<<": ";
        cout<<ans<<"\n";
    }
    return 0;





}
