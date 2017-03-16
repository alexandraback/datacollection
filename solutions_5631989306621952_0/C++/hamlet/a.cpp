#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<set>
#include<vector>
#include<map>
#include<cassert>
#include<queue>
using namespace std;
string s;

string f(int a,int b){
    if(a==b)return string(1,s[a]);
    char c=s[a];
    for(int i=a;i<b;i++)
        c=max(c,s[i]);
    string dev="";

    if(c<=s[b]){
        dev+=s[b];
        dev=dev+f(a,b-1);
    }else{
        dev+=s[b];
        dev=f(a,b-1)+dev;
    }
    
    return dev;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int tc;
    cin>>tc;
    for(int caso=1;caso<=tc;caso++){
        cin>>s;
        cout<<"Case #"<<caso<<": ";
        cout<<f(0,s.size()-1)<<endl;
    }

    
    return 0;
}





