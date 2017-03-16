#include <bits/stdc++.h>
using namespace std;
string result[10005];

int main(){
    int T;
    cin>>T;
  
   	for(int index=1; index<=T; index++) {
        string s;
        cin>>s;
        result[1]=s[0];
        
        for(int i=1;i<s.size();++i){
            string fi = result[i];
            string se = fi;
            se=s[i] + result[i];
            fi=result[i] + s[i];
            result[i+1]=max(fi,se);
        }
        cout << "Case #" << index << ": " << result[(int)s.size()] << endl;
    }
    return 0;
}