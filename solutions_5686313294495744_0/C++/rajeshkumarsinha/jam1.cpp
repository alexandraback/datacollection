#include<bits/stdc++.h>
using namespace std;

#define l long long

ifstream fin("input.txt");
ofstream fout("output.txt");



int main(){
    int t;cin>>t;
    for(int j=1;j<=t;j++){
        int n;cin>>n;
        map<string,int>mark;
        for(int i=0;i<n;i++){
            string s1,s2;
            cin>>s1>>s2;
            mark[s1]++;
        }

        int ans=0;
        for(map<string,int>::iterator it=mark.begin();it!=mark.end();++it){
            ans+=(it->second);ans--;
        }
        cout<<"Case #"<<j<<": ";

        cout<<ans<<endl;

    }
}
