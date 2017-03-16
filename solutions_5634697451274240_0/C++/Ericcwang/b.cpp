#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    cin>>T;
    for (int i=1;i<=T;i++){
        string s;
        cin>>s;
        int j=s.size();
        j--;
        int cnt=0;
        while (j>=0 && s[j]=='+') j--;
        while (j>=0){
            char curr=s[j];
            cnt++;
            j--;
            while (j>=0 && s[j]==curr) j--;
        }
        cout<<"Case #"<<i<<": "<<cnt<<endl;
    }
}
