#include<bits/stdc++.h>
using namespace std;
int powe( int a , int b )
{
    int ret=1;
    for( int i=0; i<b; ++i ) ret*=a;
    return ret;
}
int findmax( string a, string b )
{
    int ret=0;
    size_t found=-1 ;
    while ( (found=a.find(b,found+1))!=string::npos ){
        ret++;
    }
    return ret;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;  cin>>t;
    for( int tt=1; tt<=t; ++tt ) {
        int k,tlen,slen,mx=-1;  cin>>k>>tlen>>slen;
        string key,target;  cin>>key>>target;
        long double ans=0;
        map<string,int> m;
        for( int i=0; i<powe(k,slen); ++i ) {
            int x=i;
            string temp="";
            while( temp.length()!=slen ) {
                temp+=key[x%k];
                x/=k;
            }
            mx=max(mx,findmax(temp,target));
            ans+=((long double)findmax(temp,target))/(long double)powe(k,slen);
        }
        cout<<setprecision(7)<<"Case #"<<tt<<": "<<mx-ans<<endl;
    }
    return 0;
}
/*
5
6 2 2
GOOGLE
GO
*/
