#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

#define lli long long int

string compute(string s){
    string t;
    int len = s.size();
    t = s[0];
    int st = 0;
    int en = 0;
    for(int i=1;i<len;i++){
        if(s[i]>=t[st]){
            t = s[i] + t;
        }
        else {
            t = t + s[i];

        }
        en++;
        //cout<<t<<endl;
    }
    return t;
}

int main(){
    freopen("A-small-attempt0.txt","r",stdin);
    freopen("out.txt","w",stdout);
    //printf("Hello CodeJam !!! :P :D\n");
    int t;
    string s;
    cin>>t;
    for(int cas = 1;cas<=t;cas++){
        cin>>s;
        cout<<"Case #"<<cas<<": ";
        cout<<compute(s)<<endl;
    }

}
