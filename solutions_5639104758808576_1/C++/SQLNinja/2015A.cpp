#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int tc;cin>>tc;
    for(int t=1;t<=tc;t++){
        long long  smax;string s;
        cin>>smax>>s;
        long long  ans=0,sm=0;
        if(s[0]=='0'){ans++;s[0]='1';}
        for(int i=1;i<s.length();i++){
                sm+=(s[i-1]-'0');
            if(s[i]=='0'&&sm<i+1){
                s[i]='1';ans++;
            }
        }
        cout<<"Case #"<<t<<": ";
        cout<<ans<<endl;
    }
}
