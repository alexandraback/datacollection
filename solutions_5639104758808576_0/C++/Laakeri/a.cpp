#include <bits/stdc++.h>
using namespace std;
int main(){
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout<<"Case #"<<tc<<": ";
        int n;
        cin>>n;
        string s;
        cin>>s;
        int h=0;
        int v=0;
        for (int i=0;i<(int)s.size();i++){
            int a=s[i]-'0';
            if (a>0){
                if (i>h){
                    v+=i-h;
                    h=i;
                }
                h+=a;
            }
        }
        cout<<v<<endl;
    }
}
