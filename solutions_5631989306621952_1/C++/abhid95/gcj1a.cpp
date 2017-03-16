#include<bits/stdc++.h>
using namespace std;
int t, _t, n, i;
string tmp, v;
string s;
int main() {
    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        cin>>s;
        n = s.length();
        tmp = "";
        v = "";
        tmp.push_back(s[0]);
        for(i = 1; i < n; i++) {
            if(tmp[tmp.size()-1] <= s[i]) {
                tmp.push_back(s[i]);
            }
            else {
                v.push_back(s[i]);
            }
        }
        reverse(tmp.begin(), tmp.end());
        printf("Case #%d: ", _t);
        cout<<tmp+v<<endl;
    }

    return 0;
}
