#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int i,res,acum,n,c1,cases;
    string s;
    cin>>cases;
    for(c1=1;c1<=cases;c1++){
        cin>>n>>s;
        acum=0;
        res=0;
        for(i=0;i<s.length();i++){
            if(s[i]>'0'){
                if(acum>=i){
                    acum+=(s[i]-'0');
                }
                else{
                    res=res+(i-acum);
                    acum=i+(s[i]-'0');
                }
            }
        }
        cout<<"Case #"<<c1<<": "<<res<<endl;
    }
}
