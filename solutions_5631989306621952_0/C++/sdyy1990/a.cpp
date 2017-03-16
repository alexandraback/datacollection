#include <iostream>
#include <string>
using namespace std;
string solve(string s) {
    string ans("");
//    cout << s <<"_"<<ans<<endl;
    for (int i = 0 ; i < s.size(); i++) {
        string v1(ans);
        string v2(ans);
        v1.push_back(s[i]);
        v2.insert(v2.begin(),s[i]);
        //cout << v1 <<" " << v2<< endl;
        if (v1<v2) ans = v2; else ans = v1;
    }
    return ans;
}
int main() {
    int nn; 
    cin >> nn;
    for (int i = 1; i<=nn; i++) {
        cout << "Case #"<<i<<": ";
        string s;cin>>s;
        cout << solve(s)<<endl;
    }
    

    
}
