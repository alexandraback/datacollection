#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int i,j,k,l,m,n, ans, cur , test,s,t;
string str;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    cin>>t;
    while(t--){
        test++;
        cin>>s>>str;
        cur = ans = 0;
        if (s!=str.size()-1) cout<<"oooooooo\n";
        for (i=0;i<str.size();i++){
            if (str[i]!='0'){
                if (cur<i){
                    ans+=i-cur;
                    cur=i;
                }
                cur+=str[i]-'0';    
            }
        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}
